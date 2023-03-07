/*****************************************************************//**
 * \file   ProfessionalEmployee.h
 * \brief  A class detailing a professional Employee
 * 
 * \author Mike
 * \date   March 2023
 *********************************************************************/
#pragma once
#ifndef PROFESSIONAL_EMPLOYEE_H
#define PROFESSIONAL_EMPLOYEE_H
#include "Employee.h"
class ProfessionalEmployee : public Employee
{
public:
	ProfessionalEmployee(std::string name, float montlySalary, float yearsWorked)
		:Employee(name)
	{
		this->MonthlySalary = montlySalary;
		this->YearsWorked = yearsWorked;
	};
	//divide the montly salary into weeks
	double Employee::WeeklySalary()
	{
		return MonthlySalary / 4;
	}
	//~52 weeks in a year
	double Employee::VacationDays()
	{
		if (YearsWorked < 1)
			return 14 / 52.17857;
		if (YearsWorked < 5)
			return 21 / 52.17857;
		if (YearsWorked < 10)
			return 28 / 52.17857;
	}
	double Employee::HealthcareContributions()
	{
		return WeeklySalary() / 10;
	}
	double MonthlySalary;
	double YearsWorked;
};

#endif