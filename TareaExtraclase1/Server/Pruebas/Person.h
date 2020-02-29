//
// Created by emanuel on 27/2/20.
//

#ifndef SERVER_PERSON_H
#define SERVER_PERSON_H
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person();
    Person(string name, int age);
    ~Person();
    virtual void showInformation();
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
};

#endif //SERVER_PERSON_H
