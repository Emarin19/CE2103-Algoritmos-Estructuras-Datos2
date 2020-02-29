//
// Created by emanuel on 27/2/20.
//

#include <iostream>
#include "Student.h"
#include "Person.h"
#include <string>

Student::Student() {}
Student::Student(string name, int age, string career) : Person(name,age) {
    this->career = career;
}
Student::~Student() {}
void Student::showInformation() {
    Person::showInformation();
    std::cout << "Career: " << getCareer() << endl;
}
void Student::setCareer(string career) {
    this->career = career;
}
string Student::getCareer() {
    return career;
}



