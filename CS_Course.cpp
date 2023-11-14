#include "CS_Course.h"

// Constructors
// Default constructor for CS_Course
CS_Course::CS_Course() { 
   
}

 // Parameterized constructor for CS_Course
CS_Course::CS_Course(const int Course_num, char* Course_name, double Hw_weight, int Hw_counter, int flag, char* book) :
    Course(Course_num, Course_name, Hw_weight, Hw_counter), flag_(flag), book_(nullptr) {
    if (book != nullptr) {
        book_ = new_name(book); 
    }
}
//destructor
CS_Course::~CS_Course() {
    delete[] book_;
}

// Function to check HW is Takef or Magen
int CS_Course::isTakef() {

    return ((flag_) ? 1 : 0);
}

// Function to get the course book
char* CS_Course::getBook() {
    if (book_ == nullptr) return nullptr; // Returns nullptr if no book

    int length = strlen(book_) + 1;
    char* Book_Wanted = new char[length];
    strcpy_s(Book_Wanted, length, book_); 

    return Book_Wanted; // Returns a copy of book_
}

// Function to set HW as Takef
int CS_Course::setTakef(bool value) {
    flag_ = value; 
    return 1; 
}

// Function to set the course book
void CS_Course::SetBook(char* Course_Book) {
    if (book_ != nullptr) delete[] book_; // Deletes previous book_ if it exists
    book_ = new_name(Course_Book);
    return;
}

// Function to get the grade for the CS Course
int CS_Course::getCSCourseGrade() {
    int GradeWithHW = getCourseGrade(); // Gets the course grade
    int ExamGrade = getExamGrade(); // Gets the exam grade

    if (flag_) {
        return GradeWithHW; // Returns course grade if the course has TAKEF HW
    }
    else {
        // Returns the higher of the course grade or exam grade if HW not Takef
        return ((GradeWithHW > ExamGrade) ? GradeWithHW : ExamGrade);
    }
}
