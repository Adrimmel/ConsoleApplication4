#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include "Header1.h"
using namespace std;

int menu();
int main() 

{
    Database database;
    Employee emp;
    string filename;
    cout << "Enter name of file: ";
    getline(cin, filename);
    filename += ".txt"; // Добавляем расширение файла
    ofstream fout(filename.c_str()); // Открываем файл для записи
    fout.close(); // Закрываем файл после создания

    ifstream fin(filename.c_str());
    if (!fin.fail())
    {
        database.load(fin);
        fin.close();
        int choice = 0;
        while (choice != 8)
        {

			int choice = menu();
			switch (choice)
			{
			case 1: {
				cin >> emp;
				database.add(emp);
				break;
			}
			case 2: {
				system("cls");
				string name;
				cout << "Enter name: ";
				if (cin.peek() == '\n') cin.ignore();
				getline(cin, name);
				database.search(name);
				break;
			}
			case 3:
			{
				system("cls");
				int id;
				bool isValidInput = true;

				do {
					cout << "Enter ID:";
					if (!(cin >> id)) {
						cout << "Invalid input. Please enter a valid number." << endl;
						isValidInput = false;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						isValidInput = true;
					}
				} while (!isValidInput);

				database.search_id(id);
				break;
			}
			case 4:
			{
				system("cls");
				cout << "All the employees: " << endl;
				database.display_all();
				break;
			}
			case 5:
			{
				system("cls");
				string name;
				cout << "Enter name to delete";
				if (cin.peek() == '\n')cin.ignore();
				getline(cin, name);
				database.remove(name);
				break;
			}
			case 6:
			{
				system("cls");
				database.sort_salary();
				cout << "Sorted by salary" << endl;
				database.display_all();
				break;
			}

			case 7:
			{
				system("cls");
				database.sort_name();
				cout << "Sorted by name" << endl;
				database.display_all();
			}

			case 9:
			{
				system("cls");
				int id, new_id;
				bool isValidInput = true;

				do {
					cout << "Enter ID to edit: ";
					if (!(cin >> id)) {
						cout << "Invalid input for ID. Please enter a valid number." << endl;
						isValidInput = false;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						isValidInput = true;
					}
				} while (!isValidInput);

				do {
					cout << "Enter new ID: ";
					if (!(cin >> new_id)) {
						cout << "Invalid input for new ID. Please enter a valid number." << endl;
						isValidInput = false;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						isValidInput = true;
					}
				} while (!isValidInput);

				database.edit_id(id, new_id);
				break;
			}

			case 8: {
				break;
			}

			default: {
				system("cls");
				cout << "error" << endl;
				break;
			}
			}
        }
    }
    return 0;
}

int menu() {
	int choice;
	cout << "1)Add" << endl;
	cout << "2) Search by name" << endl;
	cout << "3)Search by ID" << endl;
	cout << "4) Display all" << endl;
	cout << "5)Remove" << endl;
	cout << "6)Sort by salary" << endl;
	cout << "7)Sort by name" << endl;
	cout << "8)Exit" << endl;
	cout << "9)Edit" << endl;
	cin >> choice;
	return choice;
}

