//
// Created by emanuel on 27/2/20.
//

#ifndef SERVER_STUDENT_H
#define SERVER_STUDENT_H

#include "Person.h"
#include <string>

class Student : public Person
{
private:
    string career;
public:
    Student();
    Student(string name, int age, string career);
    ~Student();
    void showInformation();
    void setCareer(string career);
    string getCareer();
};

#endif //SERVER_STUDENT_H
