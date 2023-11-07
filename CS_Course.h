#ifndef CS_Course_H
#define CS_Course_H
#include "Course.h"

class CS_Course : public Course {
public:
    // Constructors
    CS_Course();
    CS_Course(const int Course_num, char* Course_name, double Hw_weight, int Hw_counter, int flag, char* book);
    //destructour
    ~CS_Course();
    // Functions
    int isTakef();
    char* getBook(); //must remmember to free memory
    int setTakef(bool value);
    void SetBook(char* Course_Book); // Take a const char* parameter for the book
    int getCSCourseGrade();
    //char* new_name(char* book_name);

private:
    bool flag_;
    char* book_; // Keep the data type as char*
};
#endif
