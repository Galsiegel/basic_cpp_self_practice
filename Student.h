#ifndef Student_H
#define Student_H
#include "Person.h"
#include "CS_Course.h"
#include "EE_Course.h"

class Student : public Person {
public:
	//constructours
	Student();
	Student(char* Person_name, int ID);
	//destructors
	~Student();
	//other functions

	//get num of total courses
	int getCourseCnt();
	//add EE course
	bool addEE_Course(EE_Course* EE_Course);
	//add CS course
	bool addCS_Course(CS_Course* CS_Course);
	//remove course
	bool remCourse(int Course_num);
	//return pointer to EE course
	EE_Course* getEE_Course(int Course_num);
	//return pointer to CS course
	CS_Course* getCS_Course(int Course_num);
	//calculate average of student
	int getAvg();
	//print student info
	void print();


private:
	EE_Course* EE_Courses_[MAX_COURSE_NUM];
	CS_Course* CS_Courses_[MAX_COURSE_NUM];
	int EE_NUM_, CS_NUM_;

};
#endif