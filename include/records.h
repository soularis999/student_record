/***************************
 * the file defines the classes used in records system
 * *************************/

#ifndef RECORDS_H
#define RECORDS_H

#include <fstream>
#include <string.h>
#include <unordered_map>    
#include "students.h"

// ******** Student ************* //
typedef std::function<void(std::shared_ptr<Student>)> StudentCallbackFunction;

class Students
{
public:
	Students();
	~Students();
    Students(const Students& s);
	
	void createStudent(const int id, const std::string name);
	void removeStudent(const int id);
	int  visitStudents(const StudentCallbackFunction& visitor);
	std::shared_ptr<Student> findStudent(const int id);
	
private:
	std::unordered_map<int, std::shared_ptr<Student> > * students;
};

// ******** Course ************* //
/*
void createCourse(const int id, const std::string name, const short credits);

void removeCourse(const int id);

int visitCourses(const std::function<void(Course)> visitor);

Course findCourse(const int id);
*/
// ******** Records ************* //
/*
void enrollStudent(const int student_id, const int course_id);

void removeStudent(const int student_id, const int course_id);

void gradeStudent(const int student_id, const int course_id, const grade_letter grade);

int visitCoursesForStudent(const int student_id, const std::function<void(Course, grade_letter)> visitor);

int visitStudentsForCourse(const int course_id, const std::function<void(Student, grade_letter)> visitor);
*/
#endif // RECORDS_H