#include "StArray.h"

//Counstructor
StArray::StArray() :num_students_(0) {
	for (int i = 0; i < MAX_STUDENT_NUM; i++) {
		students_[i] = nullptr;
	}

}
//Destructor
StArray::~StArray() {
	if (num_students_ > 0) {
		resetStArray();
	}
}

// adding student to array
// returns 1 for success 0 for fail
bool StArray::addStudent(int student_id, char* student_name) {
	if (student_name == nullptr) return false;
	else if (num_students_ < MAX_STUDENT_NUM)
	{
		students_[num_students_] = new Student(student_name, student_id);
		num_students_++;
		return true;
	}
	return false;
}

//add EE course,return false if student isnt in the system
bool StArray::addEE_Course(int student_id, int course_num, char* course_name, int hw_num, double hw_weight) {
	int student_location = findStudent(student_id);
	if (student_location == -1) return false;//no student in array
	else {

		bool tempEE_Course = students_[student_location]->addEE_Course(new EE_Course(course_num, course_name, hw_weight, hw_num));
		if (tempEE_Course) return true;
		else return false;//failed to add course
	}
}

//add CS course,return false if student isnt in the system
bool StArray::addCS_Course(int student_id, int course_num, char* course_name, int hw_num, double hw_weight, int flag, char* book_name) {
	int student_location = findStudent(student_id);
	if (student_location == -1) return false;//no student in array
	bool tempCS_Course = students_[student_location]->addCS_Course(new CS_Course(course_num, course_name, hw_weight, hw_num, flag, book_name));
	return tempCS_Course;

}
//set hw grade
//returns fail if student or course or wanted hw doesnt exist
bool StArray::setHwGrade(int student_id, int course_num, int hw_serial, int hw_grade) {
	int student_location = findStudent(student_id);
	if (student_location == -1) return false;//no student in array
	EE_Course* EEcourse = students_[student_location]->getEE_Course(course_num);
	CS_Course* CScourse = students_[student_location]->getCS_Course(course_num);
	if (EEcourse == nullptr && CScourse == nullptr) return false;//no course found
	if (EEcourse != nullptr) {
		return (EEcourse->setHwGrade(hw_serial, hw_grade));
	}
	if (CScourse != nullptr) {
		return (CScourse->setHwGrade(hw_serial, hw_grade));
	}
	// Handle the case where none of the above conditions matched
	return false;
}
//set exam grade, return fail if student or course doesnt exist
bool StArray::setExamGrade(int student_id, int course_num, int exam_grade) {
	int student_location = findStudent(student_id);
	if (student_location == -1) return false;//no student in array
	EE_Course* EEcourse = students_[student_location]->getEE_Course(course_num);
	CS_Course* CScourse = students_[student_location]->getCS_Course(course_num);
	if (EEcourse == nullptr && CScourse == nullptr) return false;//no course found
	if (EEcourse != nullptr) {
		return (EEcourse->setExamGrade(exam_grade));
	}
	if (CScourse != nullptr) {
		return (CScourse->setExamGrade(exam_grade));
	}
	// Handle the case where none of the above conditions matched
	return false;

}
//add factor to all students studying wanted course, return 1 if added 0 if not
bool StArray::setFactor(int course_num, int factor) {
	int factorAdded = 0;
	for (int i = 0; i < num_students_; i++) {
		EE_Course* EEcourse = students_[i]->getEE_Course(course_num);
		if (EEcourse) {
			factorAdded = EEcourse->setFactor(factor);
		}
	}
	return factorAdded;
}

//print student
//return 0 if student doesnt exist, else return 1
bool StArray::printStudent(int student_id) {
	int student_location = findStudent(student_id);
	if (student_location == -1) return false;//no student in array
	students_[student_location]->print();
	return true;
}

//print all students info
void StArray::printAll() {
	for (int i = 0; i < num_students_; i++) {
		students_[i]->print();
	}
	return;
}

//delete all students currently in array 
void StArray::resetStArray() {
	for (int i = 0; i < num_students_; i++) {
		delete students_[i];
		students_[i] = NULL;
	}
}

//find student index
int StArray::findStudent(int student_id) {
	for (int i = 0; i < num_students_; i++) {
		if (students_[i]->getID() == student_id) return i;
	}
	return -1;
}