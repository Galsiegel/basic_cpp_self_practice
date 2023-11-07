#ifndef Course_H
#define Course_H
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include "Proj.h"
#include <string.h>
using std::cout;

class Course {
public:
	//constructor and destructor
	Course();
	//constructor that initiates Course_num,Course_name,Hw_weight,Hw_counter
	Course(const int Course_num, char* Course_name, double Hw_weight, int Hw_counter);
	~Course();

	//Methods to access data individually 
	int getNum() const;
	char* getName() const;
	int getExamGrade() const;
	int getHwGrade(int Hw_SerialNum) const;
	int getHwNum() const;
	double getHwWeight() const;
	double getHwAverage() const;
	int getCourseGrade() const;


	//Methods to change data individually
	bool setExamGrade(int ExamGrade);
	bool setHwGrade(int Hw_SerialNum, int HwGrade);
	char* new_name(char* name); // function to copy name

private:

	int Course_num_;
	char* Course_name_;
	double Hw_weight_;
	int Hw_counter_;
	int* grades_;
	int ExamGrade_;
};

#endif

