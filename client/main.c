#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;
    /*
        The variable server is a pointer to a structure of type hostent. This structure is defined in the
        header file netdb.h as follows:

        struct  hostent {
            char    *h_name;        /* official name of host
            char    **h_aliases;    /* alias list
            int     h_addrtype;     /* host address type
            int     h_length;       /* length of address
            char    **h_addr_list;  /* list of addresses from name server
        #define h_addr  h_addr_list[0]  /* address, for backward compatiblity
        };

        Note that h_addr is an alias for the first address in the array of network addresses.
    */

    char buffer[256];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    /*
        argv[1] contains the name of a host on the Internet, e.g. cheerios@cs.rpi.edu. The function:

            struct hostent *gethostbyname(char *name)

        Takes such a name as an argument and returns a pointer to a hostent containing information
        about that host. The field char *h_addr contains the IP address. If this structure is NULL,
        the system could not locate a host with this name.
    */

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    /*
        This code sets the fields in serv_addr. Much of it is the same as in the server. However, because
        the field server->h_addr is a character string, we use the function:

            void bcopy(char *s1, char *s2, int length)

        which copies length bytes from s1 to s2.
    */

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
        error("ERROR connecting");
    }
    /*
        The connect function is called by the client to establish a connection to the server. It takes
        three arguments, the socket file descriptor, the address of the host to which it wants to connect
        (including the port number), and the size of this address. This function returns 0 on success
        and -1 if it fails.

        Notice that the client needs to know the port number of the server, but it does not need to know
        its own port number. This is typically assigned by the system when connect is called.
    */

    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0){
        error("ERROR writing to socket");
    }

    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0){
        error("ERROR reading from socket");
    }
    printf("%s\n",buffer);
    return 0;
}


//man connect