//
// Created by emanuel on 27/2/20.
//

#include <iostream>
#include "Person.h"

Person::Person() {}
Person::Person(string name, int age){
    Person::name = name;
    Person::age = age;
}
Person::~Person() {}
void Person::showInformation() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Age: " <<getAge() << std::endl;
}
void Person::setName(string name) {
    this->name = name;
}
string Person::getName() {
    return name;
}
void Person::setAge(int age) {
    this->age = age;
}
int Person::getAge() {
    return age;
}