
//Course.cpp
#include "Course.h"
#include <string.h>
using namespace std;

//Constructor

//Counstructor
Course::Course(){}

Course::Course(const int Course_num, char* Course_name, double Hw_weight, int Hw_counter) :
	Course_num_(Course_num), Course_name_(new_name(Course_name)),
	Hw_weight_(Hw_weight), Hw_counter_(Hw_counter), grades_(new int[Hw_counter]), ExamGrade_(0) {}

//Destructor
Course::~Course()
{
	delete[] grades_;
	delete[] Course_name_;
}

//getters

//return Num of courses
int Course::getNum() const {
	return Course_num_;
}

//return name of course
char* Course::getName() const {
	return Course_name_;
}

//return exam grade
int Course::getExamGrade() const {

	return ExamGrade_;

}

int Course::getHwGrade(int Hw_SerialNum) const {
	if (Hw_SerialNum >= Hw_counter_ || Hw_SerialNum <= 0)
		return 0;
	return grades_[Hw_SerialNum];
}

int Course::getHwNum() const {
	return Hw_counter_;
}

double Course::getHwWeight() const {
	return Hw_weight_;
}
double Course::getHwAverage() const {
	if (Hw_counter_ == 0) return 0; // Handle division by zero
	double sum = 0;
	for (int i = 0; i < Hw_counter_; ++i) {
		sum += grades_[i];
	}
	return  sum / Hw_counter_;
}

int Course::getCourseGrade() const {
	double ExamWeight = 1 - Hw_weight_;
	double course_grade = (ExamWeight * ExamGrade_) +( Hw_weight_*getHwAverage()) + 0.5;
	int course_grade_round = (int)course_grade;
	return course_grade_round;
}

//setters
bool Course::setExamGrade(int ExamGrade) {
	if (ExamGrade > 100 || ExamGrade < 0)
		return false;
	ExamGrade_ = ExamGrade;
	return true;
}

bool Course::setHwGrade(int Hw_SerialNum, int HwGrade) {
	if (Hw_SerialNum >= Hw_counter_ || Hw_SerialNum < 0) return false;
	if (HwGrade > 100 || HwGrade < 0) return false;
	grades_[Hw_SerialNum] = HwGrade;
	return true;
}
//make new name
char* Course::new_name(char* name)
{
	int length = strlen(name) + 1;
	char* new_name = new char[length];

	//strcpy(new_name, name);
	strcpy_s(new_name, length,name);

	return new_name;
}
