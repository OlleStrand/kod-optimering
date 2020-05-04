#include "CommandController.h"
#include <iostream>

CommandController::CommandController()
{
}


CommandController::~CommandController()
{
}

std::vector<Employee*> CommandController::employees;

void CommandController::CommandMain(char option)
{
	switch (option)
	{
	case 'a':
		CommandController::ListEmployees();
		break;

	case 'b':
		CommandController::AddEmployee();
		break;

	case 'c':
		CommandController::EditEmployee();
		break;

	case 'd':
		CommandController::RemoveEmployee();
		break;

	default:
		std::cout << "This option is not available.\n";
		break;
	}
}

void CommandController::ListEmployees()
{
	std::cout << "\nEmployees: \n";
	if ((int)(CommandController::employees.size()) > (0)) {
		for (Employee* e : CommandController::employees)
		{
			if (e == nullptr) continue;

			std::cout << e->GetId() << " " << e->GetFirstName() << " " << e->GetLastName()
				<< " in " << e->GetCity() << " on " << e->GetAddress()
				<< " gets paid $" << e->GetMonthlySalary() << "\n";
		}
	}

	system("pause");
}

void CommandController::AddEmployee()
{
	std::cout << "\nAdd new Employee: \n";

	std::string firstName, lastName, address, city;
	float salary;
	char input;

	std::cout << "Enter Firstname: ";
	std::cin >> firstName;

	std::cout << "Enter Lastname: ";
	std::cin >> lastName;

	std::cout << "Enter Address: ";
	std::cin >> address;

	std::cout << "Enter City: ";
	std::cin >> city;

	std::cout << "Enter Salary: $";
	std::cin >> salary;

	bool validInput = false;
	do
	{
		Employee* emp = new Employee(firstName, lastName, address, city, salary);
		std::cout << emp->GetId() << " " << emp->GetFirstName() << " " << emp->GetLastName()
			<< " in " << emp->GetCity() << " on " << emp->GetAddress()
			<< " gets paid $" << emp->GetMonthlySalary() << "\n";
		std::cout << "Are you sure you want to add this employee? (y / n) ";
		std::cin >> input;

		if (input == 'y') {
			CommandController::employees.push_back(emp);
			validInput = true;
		}
		else if (input == 'n') {
			std::cout << "\nOk! Deleting this employee \n";
			validInput = true;
		}
	} while (!validInput);

	system("pause");
}

void CommandController::EditEmployee()
{
	std::cout << "\nEdit Employee: \n";

	std::string firstName, lastName, address, city;
	int id;
	float salary;
	char input;

	std::cout << "Enter ID of Employee: ";
	std::cin >> id;

	if (!IdExists(id)) {
		std::cout << "Employee with id " << id << " doesn't exist.\n";
		system("pause");
		return; 
	}

	std::cout << "Enter New Firstname: ";
	std::cin >> firstName;

	std::cout << "Enter New Lastname: ";
	std::cin >> lastName;

	std::cout << "Enter New Address: ";
	std::cin >> address;

	std::cout << "Enter New City: ";
	std::cin >> city;

	std::cout << "Enter New Salary: $";
	std::cin >> salary;

	bool validInput = false;
	do
	{
		Employee* emp = new Employee(firstName, lastName, address, city, salary, id);

		std::cout << "These are the changed values \n";
		std::cout << CommandController::employees[id]->GetFirstName() << " -> " << emp->GetFirstName() << "\n";
		std::cout << CommandController::employees[id]->GetLastName() << " -> " << emp->GetLastName() << "\n";
		std::cout << CommandController::employees[id]->GetCity() << " -> " << emp->GetCity() << "\n";
		std::cout << CommandController::employees[id]->GetAddress() << " -> " << emp->GetAddress() << "\n";
		std::cout << CommandController::employees[id]->GetMonthlySalary() << " -> " << emp->GetMonthlySalary() << "\n";

		std::cout << "Are you sure you want to update this employee? (y / n) ";
		std::cin >> input;

		if (input == 'y') {
			CommandController::employees[id] = emp;
			validInput = true;
		}
		else if (input == 'n') {
			std::cout << "\nOk! Not changing a thing \n";

			validInput = true;
		}
	} while (!validInput);
}

bool CommandController::IdExists(int id)
{
	if ((int)(CommandController::employees.size()) > (0))
	{
		for (Employee* e : CommandController::employees)
		{
			if (e == nullptr)
				return false;

			if (e->GetId() == id)
				return true;
		}
	}
	return false;
}

void CommandController::RemoveEmployee()
{
	std::cout << "\nRemove Employee: \n";
	int id;
	char input;

	std::cout << "Enter ID of Employee: ";
	std::cin >> id;

	if (!IdExists(id)) {
		std::cout << "Employee with id " << id << " doesn't exist.\n";
		system("pause");
		return;
	}
	
	bool validInput = false;
	do
	{
		std::cout << CommandController::employees[id]->GetId()
			<< " " << CommandController::employees[id]->GetFirstName()
			<< " " << CommandController::employees[id]->GetLastName()
			<< " in " << CommandController::employees[id]->GetCity()
			<< " on " << CommandController::employees[id]->GetAddress()
			<< " gets paid $" << CommandController::employees[id]->GetMonthlySalary() << "\n";

		std::cout << "Are you sure you want to Remove this employee? (y / n) ";
		std::cin >> input;
		if (input == 'y') {
			CommandController::employees[id] = nullptr;
			validInput = true;
		}
		else if (input == 'n') {
			std::cout << "\nOk! Employee not removed.\n";
			validInput = true;
		}
	} while (!validInput);
}
