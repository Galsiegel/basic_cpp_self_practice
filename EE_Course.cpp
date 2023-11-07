#include "EE_Course.h"

//constructor

EE_Course::EE_Course() {}

EE_Course::EE_Course(const int Course_num, char* Course_name, double Hw_weight, int Hw_counter) :
	Course(Course_num, Course_name, Hw_weight, Hw_counter), factor_(0) {}


//getters

int EE_Course::getFactor() {
	return factor_;
}

//setters
int EE_Course::setFactor(int Factor) {
	factor_ = Factor;
	return 1;
}

//calculat EE course grade
int EE_Course::getEECourseGrade() {
	int EE_Grade = getCourseGrade() + factor_;
	return ((EE_Grade > 100) ? 100 : EE_Grade); //returns grade. max grade 100
}


