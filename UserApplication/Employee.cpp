#include "Employee.h"
#include "CommandController.h"
#include <algorithm>
#include <iostream>

std::vector<int> Employee::ids;

void Employee::SetId()
{
	if ((int)(CommandController::employees.size()) == 0)
	{
		id = 0;
		Employee::ids.push_back(0);

		return;
	}

	for (int i = 0; i < 9999; i = i)
	{
		for (auto& elem : Employee::ids)
		{
			if (elem != i)
			{
				id = i;
				Employee::ids.push_back(i);

				return;
			}
			i++;
		}
	}
}

Employee::Employee()
{
	if (id == -1) SetId();

	firstName = "";
	lastName = "";
	address = "";
	city = "";
	monthlySalary = 2500.0f;
}

Employee::~Employee()
{
}

Employee::Employee(std::string fName, std::string lName, std::string addr, std::string c, float salary)
{
	if (id == -1) SetId();

	firstName = fName;
	lastName = lName;
	address = addr;
	city = c;
	monthlySalary = salary;
}

Employee::Employee(std::string fName, std::string lName, std::string addr, std::string c, float salary, int i)
{
	id = i;
	firstName = fName;
	lastName = lName;
	address = addr;
	city = c;
	monthlySalary = salary;
}

/*void Employee::LoadEmployees()
{

}*/

void Employee::SetFirstName(std::string value)
{
	firstName = value;
}

void Employee::SetLastName(std::string value)
{
	lastName = value;
}

void Employee::SetAddress(std::string value)
{
	address = value;
}

void Employee::SetCity(std::string value)
{
	city = value;
}

void Employee::SetMonthlySalary(float value)
{
	monthlySalary = value;
}

int Employee::GetId()
{
	return id;
}

std::string Employee::GetFirstName()
{
	return firstName;
}

std::string Employee::GetLastName()
{
	return lastName;
}

std::string Employee::GetAddress()
{
	return address;
}

std::string Employee::GetCity()
{
	return city;
}

float Employee::GetMonthlySalary()
{
	return monthlySalary;
}

