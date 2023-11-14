//main.cpp
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS
#include "Proj.h"
#include "StArray.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "EE_Course.h"
#include "CS_Course.h"
#include "Person.h"
#include "Student.h"
using std::cout;
using std::endl;
//check updated
void test1() {
    ////test num 2 - checking EE_Course 

    // Create an EE_Course object
    char courseName[] = "Electrical Engineering";
    EE_Course eeCourse(101, courseName, 0.2, 5);

    // Test setting and getting factor
    int factor = eeCourse.getFactor();
    std::cout << "Factor: " << factor << std::endl;
    eeCourse.setExamGrade(85);
    eeCourse.setHwGrade(0, 90);
    eeCourse.setHwGrade(1, 88);
    eeCourse.setHwGrade(2, 92);
    eeCourse.setHwGrade(3, 87);
    eeCourse.setHwGrade(4, 91);
    if (eeCourse.setFactor(3) == 1) {
        std::cout << "Factor set successfully." << std::endl;
    }
    else {
        std::cout << "Factor set failed." << std::endl;
    }

    factor = eeCourse.getFactor();
    std::cout << "Updated Factor: " << factor << std::endl;

    //// Test accessing data inherited from Course
    //int courseNum = eeCourse.getNum();
    //char* courseName = eeCourse.getName();
    //double hwWeight = eeCourse.getHwWeight();
    //int hwCounter = eeCourse.getHwNum();

    //std::cout << "Course Number: " << courseNum << std::endl;
    //std::cout << "Course Name: " << courseName << std::endl; // Corrected this line
    //std::cout << "Homework Weight: " << hwWeight << std::endl;
    //std::cout << "Homework Counter: " << hwCounter << std::endl;

    //// Test getting course grade
    //int courseGrade = eeCourse.getEECourseGrade();
    //std::cout << "Course Grade: " << courseGrade << std::endl;

    /*test 3 - CS
     Test 3.1: Create a CS_Course object and access its attributes*/

    char CSCourseName[] = "Computer Science";
    char CSBook[] = "Intro to Algorithms";
    CS_Course csCourse1(201, CSCourseName, 0.3, 3, true, CSBook);
    //CS_Course csCourse1(201, CSCourseName, 0.3, 3, true, CSBook);
    csCourse1.setExamGrade(85);
    csCourse1.setHwGrade(0, 95);
    csCourse1.setHwGrade(1, 88);
    csCourse1.setHwGrade(2, 67);

    //cout << "Course Number: " << csCourse1.getNum() << endl;
    //cout << "Course Name: " << csCourse1.getName() << endl;
    //cout << "Homework Weight: " << csCourse1.getHwWeight() << endl;
    //cout << "Number of Homework Assignments: " << csCourse1.getHwNum() << endl;
    //cout << "Homework Average: " << csCourse1.getHwAverage() << endl;
    //cout << "Course Grade: " << csCourse1.getCSCourseGrade() << endl;
    //cout << "Course Flag (Takef): " << csCourse1.isTakef() << endl;
    //cout << "Course Book: " << csCourse1.getBook() << endl;

    // Test 3.2 Modify attributes of the CS_Course object
    /*csCourse1.setTakef(false);
    char newbook[] = "Advanced Data Structures";
    csCourse1.SetBook(newbook);

    cout << "Course Flag (Takef) after modification: " << csCourse1.isTakef() << endl;
    cout << "Course Book after modification: " << csCourse1.getBook() << endl;
    cout << "updated Course Grade: " << csCourse1.getCSCourseGrade() << endl;*/

    //// test 4 - person.h

     //// Create a Person object
     //char personName[] = "John Doe"; // Original name
     //Person person(1, personName);

     //// Test getters
     //int id = person.getID();
     //char* name = person.getName();

     //// Display the retrieved values
     //cout << "ID: " << id << std::endl;
     //cout << "Name: " << name << std::endl;

     //// Modify the name
     //char newName[] = "Jane Doe";
     //person.new_name(newName);

     //// Test if the name has been updated
     //name = person.getName();
     //cout << "Updated Name: " << name << std::endl;

     //// Deallocate memory for name
     //delete[] name;


     //test 5 - student.h - has problems
     // // Create a Student object
     //char studentName[] = "Alice";
     //Student student(studentName, 1);


     //// Add the courses to the student
     //student.addEE_Course(&eeCourse);
     //student.addCS_Course(&csCourse1);

     //// Print student information
     //student.print();

    StArray stArray;

    // Test Case 1: Add Students
    char studentName1[] = "Moshe";
    stArray.addStudent(128, studentName1);
    char studentName2[] = "Gidon";
    stArray.addStudent(325, studentName2);

    // Test Case 2: Add EE Courses
    char courseName1[] = "Malam";
    stArray.addEE_Course(128, 100, courseName1, 1, 0.15);
    char courseName2[] = "Mitug";
    stArray.addEE_Course(128, 103, courseName2, 2, 0.2);
    char courseName3[] = "Malam";
    stArray.addEE_Course(325, 100, courseName3, 1, 0.15);
    char courseName4[] = "Sadot";
    stArray.addEE_Course(325, 105, courseName4, 2, 0.15);

    // Test Case 3: Set Homework Grades
    stArray.setHwGrade(128, 100, 0, 88);
    stArray.setHwGrade(128, 103, 1, 91);
    stArray.setHwGrade(128, 103, 0, 97);
    stArray.setHwGrade(325, 100, 0, 90);
    stArray.setHwGrade(325, 105, 0, 95);
    stArray.setHwGrade(325, 105, 1, 97);

    // Test Case 4: Set Exam Grades
    stArray.setExamGrade(128, 100, 90);
    stArray.setExamGrade(128, 103, 86);
    stArray.setExamGrade(325, 100, 78);
    stArray.setExamGrade(325, 105, 67);

    // Test Case 5: Add CS Courses
    char csCourseName1[] = "Combinatorics";
    char bookName1[] = "Graph_Algorithms";
    stArray.addCS_Course(128, 200, csCourseName1, 2, 0.2, 1, bookName1);
    char csCourseName2[] = "Combinatorics";
    char bookName2[] = "Graph_Algorithms";
    stArray.addCS_Course(325, 200, csCourseName2, 2, 0.2, 1, bookName2);

    // Set CS Course Grades
    stArray.setHwGrade(128, 200, 0, 86);
    stArray.setHwGrade(128, 200, 1, 95);
    stArray.setExamGrade(128, 200, 97);
    stArray.setHwGrade(325, 200, 0, 100);
    stArray.setHwGrade(325, 200, 1, 93);
    stArray.setExamGrade(325, 200, 82);

    // Test Case 6: Set Factors
    stArray.setFactor(100, 2);
    stArray.setFactor(200, 3);

    //// Test Case 7: Print Student Information
    //stArray.printStudent(128);
   // stArray.printStudent(325);

    // Test Case 8: Print All Students
    stArray.printAll();

    // Test Case 9: Find Students
    int studentId1 = stArray.findStudent(128);
    int studentId2 = stArray.findStudent(325);

    // Test Case 10: Reset Student Array
    stArray.resetStArray();

}

void test2() {
   

    return;
}

int main() {
    test1();
    //test2();
    

  return 0;

}


