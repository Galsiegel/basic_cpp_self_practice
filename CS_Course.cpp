#include "CS_Course.h"

// Constructors

CS_Course::CS_Course() {
}

CS_Course::CS_Course(const int Course_num, char* Course_name, double Hw_weight, int Hw_counter, int flag, char* book) :
    Course(Course_num, Course_name, Hw_weight, Hw_counter), flag_(flag), book_(nullptr) {
    // Allocate memory for book_ and copy book if provided
    if (book != nullptr) {
        book_ = new_name(book);
    }
}

CS_Course::~CS_Course() {
    delete[] book_; // Deallocate book_ if it's not nullptr
}
int CS_Course::isTakef() {
    return((flag_) ? 1 : 0);

}

char* CS_Course::getBook() {
    if (book_ == nullptr) return nullptr;
    int length = strlen(book_)+1;
    char* Book_Wanted = new char[length];
    strcpy_s(Book_Wanted, length, book_);

    return Book_Wanted;
}

int CS_Course::setTakef(bool value) {
    flag_ = value;
    return 1;
}


void CS_Course::SetBook(char* Course_Book) {

    if (book_ != nullptr) delete[] book_;
    book_ = new_name(Course_Book);
    return;


}

int  CS_Course::getCSCourseGrade() {
    int tempGrade = getCourseGrade();
    int tempExamGrade = getExamGrade();
    if (flag_) {
        return tempGrade;
    }
    else return ((tempGrade > tempExamGrade) ? tempGrade : tempExamGrade);
}

