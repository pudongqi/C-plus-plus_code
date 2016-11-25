#include<iostream>
#include <string>
using namespace std;

class Course
{
public:
    string courseName;
    string* students;
    int numberOfStudents;
    int capacity;
    Course(const string& name, int capacity);
    ~Course();
    string getCourseName() const;
    void addStudent(const string& name);
    void dropStudent(const string& name);
    string* getStudents() const;
    int getNumberOfStudents() const;
};

Course::Course(const string& name, int capacity)
{
    numberOfStudents = 0;
    this -> courseName = name;
    this -> capacity = capacity;
    students = new string[capacity];
}

Course::~Course()
{
    delete [] students;
    numberOfStudents = 0;
    capacity = 0;
}

string Course::getCourseName() const
{
  return courseName;
}

void Course::addStudent(const string& name)
{
    students[numberOfStudents++] = name;
}

void Course::dropStudent(const string& name)
{
    int temp = -1;
    for (int i = 0; i < numberOfStudents; i++)
	{
		if (name == students[i])
        {
            temp = i;
            break;
        }
	}
    if (temp != -1)
    {
       for (int i = temp; i < numberOfStudents - 1; i++)
       {
           students[i] = students[i + 1];
       }
       numberOfStudents--;
    }
}

string* Course::getStudents() const
{
  return students;
}

int Course::getNumberOfStudents() const
{
  return numberOfStudents;
}

int main()
{
    Course course("English", 10);
    course.addStudent("a");
    course.addStudent("b");
    course.addStudent("c");
    course.addStudent("d");
    cout << "Number of students in " << course.getCourseName() << " is: "
        << course.getNumberOfStudents() << endl;
    course.dropStudent("a");
    string* students = course.getStudents();
    for (int i = 0; i < course.getNumberOfStudents(); i++)
    {
        cout << students[i] << endl;
    }
    return 0;
}
