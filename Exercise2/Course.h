//
// Created by Kolio on 10/27/2026.
//

#ifndef LAB3_COURSE_H
#define LAB3_COURSE_H
#include <string>


class Student;
class Transfer;
class Course {
private:
    std::string title;
    int maxStudents;
    int currentStudents;
    Student** enrolled;

public:
    Course(const std::string& title, int maxStudents);
    ~Course();
    void enroll(Student& student);
    Student& getEnrolledStudent(int i);
    [[nodiscard]] const Student& getEnrolledStudent(int i) const;
    friend void transfer(Student& student, Course& from, Course& to);
    friend void printReport(const Course& course);
};


#endif //LAB3_COURSE_H
