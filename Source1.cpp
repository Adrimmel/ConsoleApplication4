#include <iostream>
#include "Header.h"
#include <string>
Employee::Employee()
{
	id_number = 0;
	salary = 0;
	years_worked = 0;
}

Employee::Employee(std::string new_name, int new_id, std::string new_address, double new_salary, int new_years_worked)
{
    name = new_name;
    id_number = new_id;
    address = new_address;
    salary = new_salary;
    years_worked = new_years_worked;
}


void Employee::output(std::ostream& outs)
{
    if (outs.rdbuf() == std::cout.rdbuf()) {
        outs << "Name: " << name << std::endl;
        outs << "ID number: " << id_number << std::endl;
        outs << "Address: " << address << std::endl;
        outs << "Salary: " << salary << std::endl;
        outs << "Years worked at company: " << years_worked << std::endl;
    }
    else {
        outs << name << std::endl;
        outs << id_number << std::endl;
        outs << address << std::endl;
        outs << salary << std::endl;
        outs << years_worked << std::endl;
    }
}

void Employee::input(std::istream& ins)
{
    if (ins.rdbuf() == std::cin.rdbuf())
    {
        if (ins.peek() == '\n') ins.ignore();
        std::cout << "Name: ";
        std::getline(ins, name);
        std::cout << "Enter ID number: ";
        ins >> id_number;
        std::cout << "Enter address: ";
        if (ins.peek() == '\n') ins.ignore();
        std::getline(ins, address);
        std::cout << "Enter salary: ";
        ins >> salary;
        std::cout << "Enter number of years: ";
        ins >> years_worked;
    }
    else {
        if (ins.peek() == '\n') ins.ignore();
        std::getline(ins, name);
        ins >> id_number;
        if (ins.peek() == '\n') ins.ignore();
        std::getline(ins, address);
        ins >> salary;
        ins >> years_worked;
    }
}


std::ostream& operator <<(std::ostream& outs, Employee& tmp) {
    tmp.output(outs);
    return outs;
}

std::istream& operator >>(std::istream& ins, Employee& tmp) {
    tmp.input(ins);
    return ins;
}