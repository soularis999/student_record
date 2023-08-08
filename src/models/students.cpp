#include "string"
#include "../../include/students.h"

using namespace std;

// ******** Student ************* //

int Student::get_id() {
    return this->id;
}

string Student::get_name() {
    return this->name;
}

// ******** Course ************* //

int Course::get_id() {
    return this->id;
}

string Course::get_name() {
    return this->name;
}

short Course::get_credits() {
    return this->credits;
}

// ******** Grade ************* //

int Grade::get_student_id() {
    return this->student_id;
}

int Grade::get_course_id() {
    return this->course_id;
}

grade_letter Grade::get_mark() {
    return this->mark;
}

void Grade::set_mark(const grade_letter mark) {
    this->mark = mark;
}
