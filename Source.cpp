#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "Header1.h"

using namespace std;




Database::Database()
{
	used = 0;
	capacity = 5;
	data = new Employee[capacity];
}

Database::Database(const Database& other)
{
	used = other.used;
	capacity = other.capacity;
	data = new Employee[capacity];
	copy(other.data, other.data + used, data);

}

Database::~Database()
{
	delete[]data;
}

void Database::operator=(const Database& other)
{
	if(&other == this)
	{
		return;
	}
	delete[]data;
	capacity = other.capacity;
	used = other.used;
	data = new Employee[capacity];
	copy(other.data, other.data + used, data);
}

void Database::make_bigger()
{
	Employee* tmp;
	tmp = new Employee[capacity + 5];
	copy(data, data + used, tmp);
	delete[]data;
	data = tmp;
	capacity += 5;
}


void Database::search(string name)
{
	int num_found = 0;
	for (int i = 0; i < used; i++) {
		if (data[i].get_name() == name)
		{
			cout << "Employee found!" << endl;
			data[i].output(cout);
			num_found++;
		}
	}
	if (num_found == 0)
	{
		cout << "No employee by that name!" << endl;
	}
}


void Database::edit_id(int old_id, int new_id) {
	for (int i = 0; i < used; ++i) {
		if (data[i].get_id_number() == old_id) {
			data[i].set_id_number(new_id);
			cout << "Employee ID updated successfully from " << old_id << " to " << new_id << "." << endl;
			return;
		}
	}
	cout << "Employee with ID " << old_id << " not found." << endl;
}
void  Database::search_id(int id)
{
	int num_found = 0;
	for (int i = 0; i < used; i++) {
		if (data[i].get_id_number() == id)
		{
			cout << "Employee found!" << endl;
			data[i].output(cout);
			num_found++;
		}
	}
	if (num_found == 0)
	{
		cout << "No employee by that name!" << endl;
	}
}


void  Database::add(const Employee& emp)
{
	if (used >= capacity)
	{
		make_bigger();
	}
	data[used] = emp;
	used++;
}

void Database::display_all()
{
	for (int i = 0; i < used; i++) {
		data[i].output(cout);
	}
}

void Database::remove(string name)
{
	for (int i = 0; i < used; i++) {
		if (data[i].get_name() == name) {
			data[i] = data[used - 1];
			used++;
		}
	}
}

void Database::save(ostream& outs)
{
	sort_name();
	for (int i = 0; i < used; i++) {
		outs << data[i];
	}
}

void Database::load(istream& ins)
{
	Employee tmp;
	while (ins >> tmp)
	{
		if (used >= capacity) {
			make_bigger();
		}
		data[used] = tmp;
		used++;
	}
}

void Database::sort_name()
{
	bool done = false;
	Employee tmp;
	while (!done)
	{
		done = true;
		for (int i = 0; i < used - 1; i++)
		{
			if (data[i].get_name() > data[i + 1].get_name())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}

void Database::sort_salary()
{
	bool done = false;
	Employee tmp;
	while (!done)
	{
		done = true;
		for (int i = 0; i < used - 1; i++)
		{
			if (data[i].get_salary() > data[i + 1].get_salary())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}

