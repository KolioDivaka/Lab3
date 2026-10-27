#include <iostream>

#include "Exercice1/Student.h"
#include "Exercise2/Course.h"



using namespace std;

static void callExercise1();
static void callExercise2();


static void summarize(const Student& s) {
     s.print();
}
static Student& getBestStudent(Student students[], int count );

int main() {

     // callExercise1();
     callExercise2();
     return 0;
}

static void callExercise1() {
try {
     Student s1("John Doe", "123456", 5);
     s1.addGrade(5.50);
     s1.addGrade(4.00);
     s1.addGrade(6.00);

     Student s2("Ivan Ivanov", "123457", 5);
     s2.addGrade(5.74);
     s2.addGrade(5.73);
     s2.addGrade(5.50);

     Student s3("Georgi Georgiev", "123458", 5);
     s3.addGrade(3.50);
     s3.addGrade(4.50);
     s3.addGrade(5.00);

     Student students[3]= {s1, s2, s3};

     Student& topStudent = getBestStudent(students, 3);

     cout<< "---Top Student---" << endl;
     summarize(topStudent);

     double& bestGrade = topStudent.getBest();
     if (bestGrade + 0.25 <=6.00) {
          bestGrade += 0.25;
     }
     else {
          bestGrade = 6.00;
     }

     cout << "---After Grade Raise---" << endl;
     summarize(topStudent);
}catch (const std:: exception& e) {
     cerr <<"Error: "<< e.what() << endl;
}


}

static void callExercise2() {
     Course c1("C++ Programming", 5);
     Course c2("Data Structures", 3);

     // Създаваме трима студенти[cite: 1]
     Student s1("John Doe", "12345");
     Student s2("Mariq Petrova", "12346");
     Student s3("Gogo Gogo", "12347");

     // Записваме тримата студенти в първия курс[cite: 1]
     c1.enroll(s1);
     c1.enroll(s2);
     c1.enroll(s3);

     std::cout << "--- Before Transfer ---";
     printReport(c1);
     printReport(c2);

     // Прехвърляме един студент (s2) във втория курс[cite: 1]
     std::cout << "\n--- Making the transfer ---\n";
     transfer(s2, c1, c2); //[cite: 1]

     // Отпечатваме отчетите и за двата курса[cite: 1]
     std::cout << "\n--- After transfer ---";
     printReport(c1); //[cite: 1]
     printReport(c2); //[cite: 1]
}


void transfer(Student& s, Course& from, Course& to) {
     int index = -1;
     for (int i = 0; i < from.currentStudents; i++) {
          if (from.enrolled[i] == &s) {
               index = i;
               break;
          }
     }

     if (index == -1) {
          std::cout << "Student: " << s.name << " is not found in the  " << from.title << " course." << std::endl;
          return;
     }

     if (to.currentStudents >= to.maxStudents) {
          std::cout << "Transfer completed: Course " << to.title << " is ful." << std::endl;
          return;
     }


     for (int i = index; i < from.currentStudents - 1; i++) {
          from.enrolled[i] = from.enrolled[i + 1];
     }
     from.currentStudents--;


     to.enrolled[to.currentStudents] = &s;
     to.currentStudents++;


     std::cout << "Student " << s.name << " (Faculty num: " << s.facultyNumber
               << ") was transferred \"" << from.title
               << "\" in the \"" << to.title << "\".\n";
}
void printReport(const Course& c) {
     double percentage = (c.maxStudents > 0)
         ? (static_cast<double>(c.currentStudents) / c.maxStudents) * 100.0
         : 0.0;

     std::cout << "\n=== Course Report: " << c.title << " ===\n";
     std::cout << "Enrolled students: " << c.currentStudents << " / " << c.maxStudents << "\n";
     std::cout << "Ocupations: " << percentage << "%\n";
}
Student & getBestStudent(Student students[], int count) {
     if (count<=0) {
          throw std::invalid_argument("The array cannot be empty!");
     }
     int bestIndex =0;
     double maxAverage = students[bestIndex].getAverage();

     for (int i=0;i<count;i++) {
          double currAverage = students[i].getAverage();
          if (currAverage > maxAverage) {
               maxAverage = currAverage;
               bestIndex = i;
          }
     }

     return students[bestIndex];
}
