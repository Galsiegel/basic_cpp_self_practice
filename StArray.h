#ifndef StArray_H
#define StArray_H
#include "Student.h"

class StArray {
public:
	StArray();
	~StArray();

	bool addStudent(int student_id, char* student_name);
	bool addEE_Course(int student_id, int course_num, char* course_name, int hw_num, double hm_weight);
	bool addCS_Course(int student_id, int course_num, char* course_name, int hw_num, double hm_weight, int flag, char* book_name);
	bool setHwGrade(int student_id, int course_num, int hw_serial, int hw_grade);
	bool setExamGrade(int student_id, int course_num, int exam_grade);
	bool setFactor(int course_num, int factor);
	bool printStudent(int student_id);
	void printAll();
	void resetStArray();
	int findStudent(int student_id);


private:
	Student* students_[MAX_STUDENT_NUM];
	int num_students_{};
};
#endif	