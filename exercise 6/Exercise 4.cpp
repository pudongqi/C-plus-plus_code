#include <iostream>
#include <string.h>
#include <string>
#include<algorithm>
using namespace std;

class Person
{
public:
    string name, address, phone, email;
    Person();
    Person(string& name, string& address, string& phone, string& email);
    void Name(string& name);
    void Address(string& address);
    void Phone(string& phone);
    void Email(string& email);
    virtual void toString();
};

Person::Person()
{
    this -> name = "a";
    this -> address = "a";
    this -> phone = "a";
    this -> email = "a";
}

Person::Person(string& name, string& address, string& phone, string& email)
{
    this -> name = name;
    this -> address = address;
    this -> phone = phone;
    this -> email = email;
}

void Person::Name(string& name)
{
    this-> name = name;
}

void Person::Address(string& address)
{
    this-> address = address;
}

void Person::Phone(string& phone)
{
    this-> phone = phone;
}

void Person::Email(string& email)
{
    this-> email = email;
}

void Person::toString()
{
    cout << "person: " << this -> name << endl;
    cout << "address: " << this -> address << endl;
    cout << "phone number: " << this -> phone << endl;
    cout << "email address: " << this -> email << endl;
}

class Student: public Person
{
private:
    string classstatus;
public:
    Student();
    Student(string& classstatus);
    Student(string& name, string& address, string& phone, string& email, string& classstatus);
    void ClassStatus(string& classstatus);
    void toString();
};

Student::Student()
{
    this -> classstatus = "freshman";
}

Student::Student(string& classstatus)
{
    this -> classstatus = classstatus;
}

Student::Student(string& name, string& address, string& phone, string& email, string& classstatus)
{
    Name(name);
    Address(address);
    Phone(phone);
    Email(email);
    this -> classstatus = classstatus;
}

void Student::ClassStatus(string& classstatus)
{
    this -> classstatus = classstatus;
}

void Student::toString()
{
    cout << "Student: " << this -> name << endl;
    cout << "address: " << this -> address << endl;
    cout << "phone number: " << this -> phone << endl;
    cout << "email address: " << this -> email << endl;
    cout << "class status: " << this -> classstatus << endl;
}

class Employee: public Person
{
private:
    string office,datehired;
    int salary;
public:
    Employee(string& office, int salary, string& datehired);
    Employee(string& name, string& address, string& phone, string& email, string& office, int salary, string& datehired);
    void Office(string& office);
    void Salary(int salary);
    void DateHired(string& datehired);
    void toString();
};

Employee::Employee(string& office, int salary, string& datehired)
{
    Office(office);
    Salary(salary);
    DateHired(datehired);
}

Employee::Employee(string& name, string& address, string& phone, string& email, string& office, int salary, string& datehired)
{
    Name(name);
    Address(address);
    Phone(phone);
    Email(email);
    Office(office);
    Salary(salary);
    DateHired(datehired);
}

void Employee::Office(string& office)
{
    this -> office = office;
}

void Employee::Salary(int salary)
{
    this -> salary = salary;
}

void Employee::DateHired(string& datehired)
{
    this -> datehired = datehired;
}

void Employee::toString()
{
    cout << "Employee: " << this -> name << endl;
    cout << "address: " << this -> address << endl;
    cout << "phone number: " << this -> phone << endl;
    cout << "email address: " << this -> email << endl;
    cout << "office: " << this -> office << endl;
    cout << "salary: " << this -> salary << endl;
    cout << "datehired: " << this -> datehired << endl;
}

class MyDate
{
private:
    int year, month, day;
};

int main()
{
    string name = "Nick";
    string address = "HuBei";
    string phone = "1234567";
    string email = "666666@163.com";
    Person person(name, address, phone, email);
    person.toString();
    cout << endl;

    name = "Anny";
    address = "BeiJing";
    phone = "222333";
    email = "777777@163.com";
    string classstatus = "sophomore";
    Student student(name, address, phone, email, classstatus);
    student.toString();
    cout << endl;

    name = "Ven";
    address = "Anhui";
    phone = "987654";
    email = "888888@163.com";
    string office = "school";
    int salary = 5000;
    string datehired = "2014/07/01";
    Employee employee(name, address, phone, email, office, salary, datehired);
    employee.toString();
    cout << endl;
    return 0;
}
