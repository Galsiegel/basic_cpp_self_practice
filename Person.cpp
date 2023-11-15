//Person.cpp
#include "Person.h"


//constructours

Person::Person() {};
Person::Person(int ID, char* PersonName) : ID_(ID), PersonName_(new_name(PersonName)) {
    };

//destructour

Person::~Person() {
    delete[] PersonName_;
}

//getters

int Person::getID() {
    return ID_;
}

char* Person::getName() {
    return new_name(PersonName_);;
}

// Make a new name
char* Person::new_name(char* name) {
    if (name == nullptr) {
        return nullptr; // Return nullptr if the provided name is null
    }
    
    int length = strlen(name) + 1;
    char* new_name = new char[length];
    strcpy_s(new_name, length,name);

  
    return new_name;
}







