//
// Created by Kolio on 10/27/2026.
//

#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H
#include <string>


class Course;

class Student {

private:
    std::string name;
    std::string facultyNumber;
    double* grades;
    int capacity;
    int gradeCount;

public:
    Student(const std::string& name, const std::string& facultyNumber, int capacity = 10);
    ~Student();

    void addGrade(double grade);
    double& getBest();
    [[nodiscard]]const double& getByIndex(int i) const;
    [[nodiscard]]double getAverage() const;
    void print() const;
    friend void transfer(Student& student, Course& from, Course& to);
    friend void printReport(const Course& course);
    



};


#endif //LAB3_STUDENT_H
