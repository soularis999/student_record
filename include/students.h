/***************************
 * the file defines the classes used in records system
 * *************************/

#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>

class Student {
    public:
        Student(const int _id, const std::string _name)
            : id(_id), name(_name) {}

        int get_id();
        std::string get_name();
    private:
        int id;
        std::string name;
};

class Course {
    public:
        Course(const int _id, const std::string _name, const short _credits)
            : id(_id), name(_name), credits(_credits) {}

        int get_id();
        std::string get_name();
        short get_credits();
    private:
        int id;
        std::string name;
        short credits;
};

enum grade_letter {A,B,C,D,F,N};

class Grade {
    public:
        Grade(const int _student_id, const int _course_id)
            : student_id(_student_id), course_id(_course_id) {}

        int get_student_id();
        int get_course_id();
        grade_letter get_mark();
        void set_mark(const grade_letter mark);
    private:
        int student_id;
        int course_id;
        grade_letter mark;
};




#endif // STUDENTS_H