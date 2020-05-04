#pragma once
#include <string>
#include "Employee.h"

class CommandController
{
private:
	bool IdExists(int id);

public:
	CommandController();
	~CommandController();

	void CommandMain(char option);

	void ListEmployees();
	void AddEmployee();
	void EditEmployee();
	void RemoveEmployee();

	static std::vector<Employee*> employees;
};