/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
//This header file contains definitions of a number of data types used in system calls
//These types are used in the next two include files.
#include <sys/types.h>
//The header file socket.h includes a number of definitions of structures needed for sockets.
#include <sys/socket.h>
//The header file netinet/in.h contains constants and structures needed for internet domain addresses.
#include <netinet/in.h>

//Function prototype
void dostuff(int);
//This function is called when a system call fails
void error(char *msg)
{
    perror(msg); //perror - print a system error message
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
    /*
    sockfd and newsockfd are file descriptors
    sockfd: stores the value returned by the socket system call
    newsockfd: stores the value returned by the accept system call
    portno: stores the port number on which the server accepts connections
    clilen: stores the size of the address of the client. This is needed for the accept system call
    n: is the return value for read() and write(). It contains the number of characters
    red or written.
    */

    char buffer[256];
    //The server reads characters from the socket connection into this buffer.

    struct sockaddr_in serv_addr, cli_addr, pid;
    /*
       A sockaddr_in is a structure containing an internet address. This structure is defined in
       <netinet/in.h>. Here is the definition:

       struct sockaddr_in {
           short   sin_family;
           u_short sin_port;
           struct  in_addr sin_addr;
           char    sin_zero[8];
       };

       An in_addr structure, defined in the same header file, contains only one field, a unsigned
       long called s_addr.

       serv_addr: will contain the address of the server
       cli_addr: will contain the address of the client which connects to the server

    */

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    //Conditional to check if a port number was specified as a argument for the server accept the
    //connections


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR opening socket");
    }
    /*
       The socket(int domain, int type, int protocol) system call creates a new socket. It takes
       three arguments.

       AF_INET: is the address domain of the socket
       SOCK_STREAM: is the type of the socket
       0: If this argument is zero (and it always should be except for unusual circumstances),
       the operating system will choose the most appropriate protocol. It will choose TCP for
       stream sockets and UDP for datagram sockets.

       Note: The socket system call returns an entry into the file descriptor table (i.e. a small
       integer). This value is used for all subsequent references to this socket.
    */

    bzero((char *) &serv_addr, sizeof(serv_addr));
    /*
       The function bzero() sets all values in a buffer to zero. It takes two arguments, the first
       is a pointer to the buffer and the second is the size of the buffer. Thus, this line
       initializes serv_addr to zeros.
    */

    portno = atoi(argv[1]);
    /*
       The port number on which the server will listen for connections is passed in as an argument,
       and this statement uses the atoi() function to convert this from a string of digits to an integer.
    */


    serv_addr.sin_family = AF_INET;
    /*
       The variable serv_addr is a structure of type struct sockaddr_in. This structure has four fields.
       The first field is short sin_family, which contains a code for the address family. It should always
       be set to the symbolic constant AF_INET.
    */

    serv_addr.sin_addr.s_addr = INADDR_ANY;
    /*
       The third field of sockaddr_in is a structure of type struct in_addr which contains only a single
       field unsigned long s_addr. This field contains the IP address of the host. For server code, this
       will always be the IP address of the machine on which the server is running, and there is a symbolic
       constant INADDR_ANY which gets this address.
    */
    serv_addr.sin_port = htons(portno);
    /*
       The second field of serv_addr is unsigned short sin_port , which contain the port number. However,
       instead of simply copying the port number to this field, it is necessary to convert this to network
       byte order using the function htons() which converts a port number in host byte order to a port
       number in network byte order.
    */

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    /*
        int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
        The bind() system call binds a socket to an address, in this case the address of the current
        host and port number on which the server will run. It takes three arguments, the socket file
        descriptor, the address to which is bound, and the size of the address to which it is bound.
        The second argument is a pointer to a structure of type sockaddr, but what is passed in is a
        structure of type sockaddr_in, and so this must be cast to the correct type. This can fail
        for a number of reasons, the most obvious being that this socket is already in use on this
        machine.

    */
    listen(sockfd,5);
    /*
       int listen(int sockfd, int backlog);
       The listen system call allows the process to listen on the socket for connections. The first
       argument is the socket file descriptor, and the second is the size of the backlog queue, i.e.,
       the number of connections that can be waiting while the process is handling a particular
       connection. This should be set to 5, the maximum size permitted by most systems. If the first
       argument is a valid socket, this call cannot fail, and so the code doesn't check for errors.
    */
    clilen = sizeof(cli_addr);
    /*
    while (1) {
       newsockfd = accept(sockfd,
                        (struct sockaddr *) &cli_addr, &clilen);
       if (newsockfd < 0){
           error("ERROR on accept");
       }

       pid = fork();
       if (pid < 0){
           error("ERROR on fork");
       }

       if (pid == 0)  {
        close(sockfd);
        dostuff(newsockfd);
        exit(0);
       }
       else{
           close(newsockfd);
       }
   }
   */

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");
    /*
       The accept() system call causes the process to block until a client connects to the server.
       Thus, it wakes up the process when a connection from a client has been successfully established.
       It returns a new file descriptor, and all communication on this connection should be done using
       the new file descriptor. The second argument is a reference pointer to the address of the client
       on the other end of the connection, and the third argument is the size of this structure.
    */

    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0){
        error("ERROR reading from socket");
    }
    printf("Here is the message: %s\n",buffer);
    /*
       ssize_t read(int fd, void *buf, size_t count);

       Note that we would only get to this point after a client has successfully connected to our
       server. This code initializes the buffer using the bzero() function, and then reads from the
       socket. Note that the read call uses the new file descriptor, the one returned by accept(),
       not the original file descriptor returned by socket(). Note also that the read() will block
       until there is something for it to read in the socket, i.e. after the client has executed a
       write(). It will read either the total number of characters in the socket or 255, whichever is
       less, and return the number of characters read.
    */

    n = write(newsockfd,"I got your message",18);
    if (n < 0){
        error("ERROR writing to socket");
    }
    /*
       write(int fd, char[], sizeof(char[]));

       Once a connection has been established, both ends can both read and write to the connection.
       Naturally, everything written by the client will be read by the server, and everything written
       by the server will be read by the client. This code simply writes a short message to the client.
       The last argument of write is the size of the message.
    */
    return 0;
}

//man socket
//man bind
//man listen
//man accept
//man read
//man write
//man perror command

/*The  perror() function produces a message on standard error describing the last
error encountered during a call to a system or library function.*/


/******** DOSTUFF() *********************
 There is a separate instance of this function
 for each connection.  It handles all communication
 once a connnection has been established.
 *****************************************/
void dostuff (int sock)
{
    int n;
    char buffer[256];

    bzero(buffer,256);
    n = read(sock,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("Here is the message: %s\n",buffer);
    n = write(sock,"I got your message",18);
    if (n < 0) error("ERROR writing to socket");
}