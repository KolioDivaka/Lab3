#include <iostream>

#include "Exercice1/Student.h"
#include "Exercise2/Course.h"
#include "Exercise3/ScoreTable.h"




static void callExercise1();
static void callExercise2();
static void callExercise3();

static void summarize(const Student& s) {
     s.print();
}
static Student& getBestStudent(Student students[], int count );

int main() {

     callExercise1();
     callExercise2();
     callExercise3();
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

     std::cout<< "---Top Student---" << std::endl;
     summarize(topStudent);

     double& bestGrade = topStudent.getBest();
     if (bestGrade + 0.25 <=6.00) {
          bestGrade += 0.25;
     }
     else {
          bestGrade = 6.00;
     }

     std::cout << "---After Grade Raise---" << std::endl;
     summarize(topStudent);
}catch (const std:: exception& e) {
     std::cerr <<"Error: "<< e.what() <<std::endl;
}


}

static void callExercise2() {
     Course c1("C++ Programming", 5);
     Course c2("Data Structures", 3);


     Student s1("John Doe", "12345");
     Student s2("Maria Petrova", "12346");
     Student s3("Gogo Gogo", "12347");


     c1.enroll(s1);
     c1.enroll(s2);
     c1.enroll(s3);

     std::cout << "--- Before Transfer ---";
     printReport(c1);
     printReport(c2);


     std::cout << "\n--- Making the transfer ---\n";
     transfer(s2, c1, c2); //[cite: 1]


     std::cout << "\n--- After transfer ---";
     printReport(c1); //[cite: 1]
     printReport(c2); //[cite: 1]
}

static void callExercise3() {
     int rows = 3;
     int cols = 4;


     ScoreTable table(rows, cols);


     double player0Scores[] = {10.5, 12.0, 8.5, 14.0};
     double player1Scores[] = {15.0, 9.5, 11.0, 13.5};
     double player2Scores[] = {7.0, 8.5, 9.0, 10.0};


     table.fillRow(0, player0Scores, 4);
     table.fillRow(1, player1Scores, 4);
     table.fillRow(2, player2Scores, 4);


     table.at(2, 3) = 12.5;


     std::cout << "--- Score Table---\n";
     for (int i = 0; i < rows; ++i) {
          std::cout << "Player " << i << ": ";
          for (int j = 0; j < cols; ++j) {
               std::cout << table.at(i, j) << " ";
          }
          std::cout << "\n";
     }
     std::cout << "---------------------------\n\n";


     std::cout << "Compare player 0 and 1\n";
     compareRows(table, 0, 1);

     std::cout << "\nCompare player 1 and 2  \n";
     compareRows(table, 1, 2);
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
     std::cout << "Occupations: " << percentage << "%\n";
}

void compareRows(const ScoreTable& t, int row1, int row2) {
     if (row1 < 0 || row1 >= t.rows || row2 < 0 || row2 >= t.rows) {
          std::cout << "Invalid row index!"<< std::endl;
          return;
     }

     double sum1 =0;
     double sum2 =0;

     for (int j =0 ; j<t.columns ; ++j) {
          sum1 += t.at(row1,j);
          sum2 += t.at(row2,j);
     }
     double average1 = sum1 / t.columns;
     double average2 = sum2 / t.columns;


     std::cout<< "Average score for player "<< row1<<": "<< average1<< std::endl;
     std::cout << "Average score for player "<< row2<<": "<< average2<< std::endl;

     if (average1 > average2) {
          std::cout <<"Player " << row1<<" has better stats"<< std::endl;
     }
     else if (average2 > average1) {
          std::cout <<"Player " << row2<<" has better stats"<< std::endl;
     }
     else {
          std::cout<<"Both players are equal";
     }
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
