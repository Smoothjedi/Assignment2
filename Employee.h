/*****************************************************************//**
 * \file   Employee.h
 * \brief  Base class for an employee
 * 
 * \author Mike McDonough
 * \date   March 2023
 *********************************************************************/
#pragma once

#include <string>
class Employee
{
public:
	Employee(std::string name)
	{
		this->Name = name;
	};
	virtual double WeeklySalary() =0;
	virtual double HealthcareContributions() = 0;
	virtual double VacationDays() = 0;
	std::string Name;
};

