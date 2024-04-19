#pragma once
#ifndef DATABASE_H
#define DATABASE_H
#include "Header.h"

class Database
{
private:
	void make_bigger();
	int capacity;
	Employee* data;
	int used;

public:
	Database();
	~Database();
	Database(const Database& other);
	void operator =(const Database& other);
	void search(std::string name);
	void search_id(int id);
	void add(const Employee& emp);
	void display_all();
	void remove(std::string name);
	void save(std::ostream& outs);
	void load(std::istream& ins);
	void sort_name();
	void sort_salary();
	void edit_id(int old_id, int new_id);
};


#endif // !DATABASE_H
