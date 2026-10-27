//
// Created by Kolio on 10/27/2026.
//

#include "Course.h"

#include <iostream>

Course::Course(const std::string &title, int maxStudents) {
    this->title = title;
    this->maxStudents = maxStudents;
    this->currentStudents = 0;
    this->enrolled = new Student*[maxStudents];


}

Course::~Course() {
    delete[] enrolled;
}

void Course::enroll(Student &student) {
    if (currentStudents<maxStudents) {
        enrolled[currentStudents] = &student;
        currentStudents++;
    }
    else {
        std::cout<< "The course :"<< title <<" is full!"<< std::endl;
    }


}

Student & Course::getEnrolledStudent(int i) {
    if (i < 0 || i >= currentStudents) {
        throw std::out_of_range("Index out of range");
    }
    return *enrolled[i];
}

const Student & Course::getEnrolledStudent(int i) const {
    if (i < 0 || i >= currentStudents) {
        throw std::out_of_range("Index out of range");
    }
    return *enrolled[i];
}
