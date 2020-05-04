#pragma once
#include <string>
#include <vector>

class Employee
{
private:
	void SetId();

	int id = -1;
	std::string firstName;
	std::string lastName;
	std::string address;
	std::string city;

	float monthlySalary;

public:
	Employee();
	~Employee();
	Employee(std::string firstName, std::string lastName, std::string address, std::string city, float monthlySalary);
	Employee(std::string fName, std::string lName, std::string addr, std::string c, float salary, int id);

	//Mutators
	void SetFirstName(std::string value);
	void SetLastName(std::string value);
	void SetAddress(std::string value);
	void SetCity(std::string value);
	void SetMonthlySalary(float value);

	//Accessors
	int GetId();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetAddress();
	std::string GetCity();
	float GetMonthlySalary();
	//void LoadEmployees();

	static std::vector<int> ids;
};