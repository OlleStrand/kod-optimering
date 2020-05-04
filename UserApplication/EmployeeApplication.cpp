#include <iostream>
#include "CommandController.h"
#include "Employee.h"
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1252);

	Employee* emp1 = new Employee("Wilmer", "Söderberg", "Valldammsgatan 81", "Valdemarsvik", 4500);
	CommandController::employees.push_back(emp1);
	Employee* emp2 = new Employee("Teodor", "Eliasson", "Klövervägen 43", "Valdemarsvik", 4600);
	CommandController::employees.push_back(emp2);
	Employee* emp3 = new Employee("Ludvig", "Holm", "Bygget 56B", "Valdemarsvik", 4250);
	CommandController::employees.push_back(emp3);
	Employee* emp4 = new Employee("Lova", "Nyman", "Löberödsvägen 1", "Valdemarsvik", 4500);
	CommandController::employees.push_back(emp4);

	//Infinite program loop
	std::cout << "Welcome to the simple Employee management system!";
	while (true)
	{
		CommandController controller;
		char option;

		std::cout << "\nThese are your options:\n\n"
			<< "a: List all Employees\n"
			<< "b: Add new Employee\n"
			<< "c: Edit Employee\n"
			<< "d: Remove Employee\n";

		std::cout << "\nEnter option: ";
		std::cin >> option;
		controller.CommandMain(option);
	}
}