#include <fstream>
#include <string.h>
#include <unordered_map>
#include "../../include/students.h"
#include "../../include/records.h"

using namespace std;

// ******** Students ************* //

Students::Students()
{
	this->students = new std::unordered_map<int, std::shared_ptr<Student> >();
}

Students::~Students()
{
    delete this->students;
}

Students::Students(const Students& s)
{
	this->students = new std::unordered_map<int, std::shared_ptr<Student> >();
    this->students->insert(s.students->begin(), s.students->end());
}

void Students::createStudent(const int id, const string name) 
{
    if(this->students->find(id) == this->students->end())
    {
        auto s = make_shared<Student>(id, name);
        this->students->insert(pair<int, shared_ptr<Student> >(id, s));
    }
    else
    {
        throw new runtime_error("another user already exists with id " + std::to_string(id));
    }
}


void Students::removeStudent(const int id) {
    auto iter = this->students->find(id);
    if(iter == this->students->end())
    {
        return;
    }
    this->students->erase(iter);
}

int Students::visitStudents(const StudentCallbackFunction& visitor) {
    int ct = 0;
    for (const auto& [key, val] : (*this->students))
    {
        visitor(val);
        ct++;
    }
    return ct;
}

shared_ptr<Student> Students::findStudent(const int id) {
    auto iter = this->students->find(id);
    if(iter != this->students->end())
    {
        return (*this->students)[id];
    }
    return shared_ptr<Student>(nullptr);
}
