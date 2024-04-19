#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {

private:
    std::string name;
    int id_number;
    std::string address;
    double salary;
    int years_worked; 

public:
    Employee();
    Employee(std::string new_name, int new_id, std::string new_address, double new_salary, int new_years_worked); 
    std::string get_name() { return name; }
    int get_id_number() { return id_number; }
    std::string get_address() { return address; }
    double get_salary() { return salary; }
    int get_years_worked() { return years_worked; }
    void output(std::ostream& outs);
    void input(std::istream& ins);
    void set_id_number(int new_id) {
        id_number = new_id;
    }
};

std::ostream& operator<<(std::ostream&, Employee& tmp);
std::istream& operator>>(std::istream&, Employee& tmp);

#endif