//
// Created by Kolio on 10/27/2026.
//
#include "Student.h"
#include <iostream>
#include <stdexcept>

Student::Student(const std::string &name, const std::string &facultyNumber, int capacity) {
    this->name = name;
    this->facultyNumber = facultyNumber;
    this->capacity = capacity > 0 ? capacity : 10;
    this->grades = new double[this->capacity];
    this->gradeCount = 0;
}

Student::~Student() {
    delete[] this->grades;
}

void Student::addGrade(double grade) {
    if (grade < 2.0 || grade > 6.0) {
        throw std::invalid_argument("Grade out of range! Must be between 2.0 and 6.0.");
    }

    if (this->gradeCount >= this->capacity) {
        throw std::overflow_error("Cannot add grade beyond capacity!");
    }

    this->grades[this->gradeCount] = grade;
    this->gradeCount++;
}

double & Student::getBest() {
    if (this->gradeCount == 0) {
        throw std::logic_error("The student does not have any grades!");
    }

    int bestIndex = 0;
    for (int i = 1; i < this->gradeCount; i++) {
        if (this->grades[i] > this->grades[bestIndex]) {
            bestIndex = i;
        }
    }

    return this->grades[bestIndex];
}

const double & Student::getByIndex(int i) const {

    if (i < 0 || i >= this->gradeCount) {
        throw std::out_of_range("Index out of bounds!");
    }

    return this->grades[i];
}

double Student::getAverage() const {
    if (this->gradeCount == 0) {
        throw std::logic_error("Student does not have any grades!");
    }

    double sum = 0.0;
    for (int i = 0; i < this->gradeCount; i++) {
        sum += this->grades[i];
    }
    return sum / this->gradeCount;
}


void Student::print() const {
    std::cout << "Name: " << this->name << "\n";
    std::cout << "Faculty Number: " << this->facultyNumber << "\n";
    std::cout << "Grades (" << this->gradeCount << "/" << this->capacity << "): ";

    if (this->gradeCount == 0) {
        std::cout << "No grades yet.";
    } else {
        for (int i = 0; i < this->gradeCount; i++) {
            std::cout << this->grades[i] << (i == this->gradeCount - 1 ? "" : ", ");
        }
    }
    std::cout << std::endl;
}