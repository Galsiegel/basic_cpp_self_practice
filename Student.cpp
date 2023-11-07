#include "Student.h"


//constructour
Student::Student() {}
Student::Student(char* Person_name, int ID) :
    Person(ID, Person_name), EE_NUM_(0), CS_NUM_(0) {}

//destructour
Student::~Student() {
    for (int i = 0; i < MAX_COURSE_NUM; i++) {
        delete EE_Courses_[i];
        EE_Courses_[i] = nullptr; // Set the pointer to nullptr after deletion
        delete CS_Courses_[i];
        CS_Courses_[i] = nullptr; // Set the pointer to nullptr after deletion

    }
}

//get num of total courses
int Student::getCourseCnt() {
    return (EE_NUM_ + CS_NUM_);
}

//add EE course
bool Student::addEE_Course(EE_Course* EE_Course) {
    if (EE_NUM_ >= MAX_COURSE_NUM || EE_Course == nullptr) {
        return false;
    }
    // Add the EE_Course to the array
    EE_Courses_[EE_NUM_] = EE_Course;
    EE_NUM_++;
    return true;
}

//add CS course
bool Student::addCS_Course(CS_Course* CS_Course) {
    if (CS_NUM_ >= MAX_COURSE_NUM || CS_Course == nullptr) {
        return false;
    }
    // Add the EE_Course to the array
    CS_Courses_[CS_NUM_] = CS_Course;
    CS_NUM_++;
    return true;
}

//return pointer to EE course
EE_Course* Student::getEE_Course(int Course_num) {
    if (Course_num < 0) return NULL;
    for (int i = 0; i < MAX_COURSE_NUM; i++) {
        if (EE_Courses_[i] != nullptr) {
            int curNum = EE_Courses_[i]->getNum();
            if (curNum == Course_num) return EE_Courses_[i];
        }
    }
    return NULL;
}


//return pointer to CS course
CS_Course* Student::getCS_Course(int Course_num) {
    if (Course_num < 0) return NULL;
    for (int i = 0; i < MAX_COURSE_NUM; i++) {
        if (CS_Courses_[i] != nullptr) {
            int curNum = CS_Courses_[i]->getNum();
            if (curNum == Course_num) return CS_Courses_[i];
        }
    }
    return NULL;
}
//remove course
bool Student::remCourse(int Course_num) {
    // Search and remove the course from EE_Courses_ array
    for (int i = 0; i < MAX_COURSE_NUM; i++) {
        if (EE_Courses_[i] != nullptr && EE_Courses_[i]->getNum() == Course_num) {
            delete EE_Courses_[i];
            EE_Courses_[i] = nullptr;
            EE_NUM_--;
            return true;
        }
    }

    // Search and remove the course from CS_Courses_ array
    for (int i = 0; i < MAX_COURSE_NUM; i++) {
        if (CS_Courses_[i] != nullptr && CS_Courses_[i]->getNum() == Course_num) {
            delete CS_Courses_[i];
            CS_Courses_[i] = nullptr;
            CS_NUM_--;
            return true;
        }
    }

    // If the course wasn't found, return false
    return false;
}
//calculate average of student

int Student::getAvg()
{
    if (getCourseCnt() == 0) return 0;
    int i = 0;
    int sum = 0;
    for (i = 0; i < EE_NUM_; i++)
    {
        sum += (EE_Courses_[i]->getEECourseGrade());
    }

    for (i = 0; i < CS_NUM_; i++)
    {
        sum += (CS_Courses_[i]->getCSCourseGrade());
    }

    double value = ((double)sum / (double)getCourseCnt());
    value += 0.5;
    return (int)value;
}

//print student info
void Student::print()
{

    cout << "Student name: " << getName() << "\n";
    cout << "Student ID: " << getID() << "\n";
    cout << "Average grade: " << getAvg() << "\n";
    cout << "\n" << "EE courses:" << "\n";
    for (int i = 0; i < EE_NUM_; i++)
        cout << EE_Courses_[i]->getNum() << " " << EE_Courses_[i]->getName() << ": " << EE_Courses_[i]->getEECourseGrade() << "\n";
    cout << "\n" << "CS courses:" << "\n";
    for (int i = 0; i < CS_NUM_; i++)
        cout << CS_Courses_[i]->getNum() << " " << CS_Courses_[i]->getName() << ": " << CS_Courses_[i]->getCSCourseGrade() << "\n";
    cout << "\n";
}

