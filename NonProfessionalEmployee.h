/*****************************************************************//**
 * \file   NonProfessionalEmployee.h
 * \brief  A class detailing a non professional employee
 * 
 * \author Mike McDonough
 * \date   March 2023
 *********************************************************************/
#pragma once
#ifndef NONPROFESSIONAL_EMPLOYEE_H
#define NONPROFESSIONAL_EMPLOYEE_H
#include "Employee.h"
class NonProfessionalEmployee : public Employee
{
public:
	NonProfessionalEmployee(std::string name, float hourlyRate, float hoursWorkedPerWeek)
		:Employee(name)
	{
		this->HourlyRate = hourlyRate;
		this->HoursWorkedPerWeek = hoursWorkedPerWeek;
	}
	double Employee::WeeklySalary()
	{
		return HourlyRate * HoursWorkedPerWeek;
	}
	double Employee::VacationDays()
	{
		return HoursWorkedPerWeek * .005;
	}
	double Employee::HealthcareContributions()
	{
		return WeeklySalary() / 20;
	}

	double HourlyRate;
	double HoursWorkedPerWeek;
};

#endif