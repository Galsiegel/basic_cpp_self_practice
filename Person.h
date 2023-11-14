#ifndef Person_H
#define Person_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Proj.h"
using std::cout;

class Person {
public:
	Person();
	Person(int ID, char* PersonName);
	virtual ~Person();

	//getters
	int  getID();
	char* getName();

	//other functions
	char* new_name(char* name);
private:
	int ID_{};
	char* PersonName_{};
};
#endif
