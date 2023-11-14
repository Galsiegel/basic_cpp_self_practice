#ifndef EE_Course_H
#define EE_Course_H
#include "Course.h"

class EE_Course : public Course {
public:
	//Constructor
	EE_Course();
	EE_Course(const int Course_num, char* Course_name, double Hw_weight, int Hw_counter);
	//Methods
	int getFactor();
	//set factor to course, return 1 on success;
	int setFactor(int Factor);
	int getEECourseGrade();
private:
	int factor_{};
};
#endif // !EE_Course_H

