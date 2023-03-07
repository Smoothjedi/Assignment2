/*****************************************************************//**
 * \file   Assignment2.cpp
 * \brief  This file contains the 'main' function. Program execution begins and ends there.
 * 
 * \author Mike
 * \date   March 2023
 *********************************************************************/

#include <iostream>
#include "Single_Linked_List.h"
#include "NonProfessionalEmployee.h"
#include "ProfessionalEmployee.h"

int main()
{
	bool terminateFlag = false;
    Single_Linked_List* list = new Single_Linked_List();

	do
	{
		// Menu interface
		int userSelection = 0;
		std::cout << "***************** Assignment 2: Part 1 *******************" << std::endl;
		std::cout << "Part 1: Please select an option:" << std::endl;
		std::cout << " 1: Determine if the list is emtpy" << std::endl;
		std::cout << " 2: Add a value to the front of the list" << std::endl;
		std::cout << " 3: Add a value to the end of the list" << std::endl;
		std::cout << " 4: Remove a value from the list with an index" << std::endl;
		std::cout << " 5: View the first value in the list" << std::endl;
		std::cout << " 6: View the last value in the list" << std::endl;
		std::cout << " 7: Pop the first value in the list" << std::endl;
		std::cout << " 8: Pop the last value in the list" << std::endl;
		std::cout << " 9: Find a value in the list" << std::endl;

		std::cout << "***************** Assignment 2: Part 2 *******************" << std::endl;
		std::cout << "10: Make a new employee" << std::endl;

		std::cout << std::endl << "Any other value will exit" << std::endl;
		std::cin >> userSelection;

		switch (userSelection)
		{		
		case 1:
		{
			system("cls");
			// Call to append the value to the end of the array
			bool empty = list->empty();
			if (empty) std::cout << "The list is empty! " << std::endl;
			else std::cout << "The list is populated!: " << std::endl;
			break;
		}

		case 2:
		{
			system("cls");
			int valueToAdd = 0;
			std::cout << "Please enter a value to add: " << std::endl;
			std::cin >> valueToAdd;
			// Call to append the value to the end of the array
			list->push_front(valueToAdd);

			break;
		}
		case 3:
		{
			system("cls");
			int valueToAdd = 0;
			std::cout << "Please enter a value to add: " << std::endl;
			std::cin >> valueToAdd;
			// Call to append the value to the end of the array
			list->push_back(valueToAdd);

			break;
		}
		case 4:
		{
			system("cls");
			int index = -1;
			std::cout << "Please enter the index of the value you would like to remove: " << std::endl;
			std::cin >> index;
			// Call to append the value to the end of the array
			bool success = list->remove(index);
			if (success) 
				std::cout << "Removal successful! Please select 1 to view the new contents: " << std::endl;
			else std::cout << "Removal failure!" << std::endl;

			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "The first value is: " << list->front() << std::endl;
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "The last value is: " << list->back() << std::endl;
			break;
		}	
		case 7:
		{
			system("cls");
			std::cout << "The first value was: " << list->pop_front() << std::endl;
			break;
		}
		case 8:
		{
			system("cls");
			std::cout << "The last value was: " << list->pop_back() << std::endl;
			break;
		}		
		case 9:
		{
			system("cls");
			int value = -1;
			std::cout << "Please enter the value you want to find: " << std::endl;
			std::cin >> value;
			std::cout << "The index returned was: " << list->find(value) << std::endl;
			break;
		}
		case 10:
		{
			Employee* newEmployee;
			system("cls");
			std::string name;
			std::cout << "Please enter the name of your employee: " << std::endl;
			std::cin >> name;
			int employeeType = 0;
			std::cout << "Please enter whether they are 1) Professional or 2) NonProfessional" << std::endl;
			std::cin >> employeeType;

			if (employeeType == 1)
			{
				float monthlySalary;
				std::cout << "Please enter the monthly salary" << std::endl;
				std::cin >> monthlySalary;
				float years;
				std::cout << "How long have they been at your company in years" << std::endl;
				std::cin >> years;

				newEmployee = new ProfessionalEmployee(name, monthlySalary, years);
			}
			else if (employeeType == 2)
			{
				float hourlyRate;
				std::cout << "Please enter the hourly rate" << std::endl;
				std::cin >> hourlyRate;
				float hoursPerWeek;
				std::cout << "How many hours do they work per week" << std::endl;
				std::cin >> hoursPerWeek;

				newEmployee = new NonProfessionalEmployee(name, hourlyRate, hoursPerWeek);
			}
			else 
			{
				break;
			}
				
			std::cout << "Your employee, " << newEmployee->Name <<", has a weekly salary of " << newEmployee->WeeklySalary() << "." << std::endl;
			std::cout << newEmployee->Name << " gains " << newEmployee->VacationDays() << " vacation days a week. " << std::endl;
			std::cout << newEmployee->Name << " pays " << newEmployee->HealthcareContributions() << " per week for health care." << std::endl;
			delete newEmployee;
			break;
		}
		default:
		{
			terminateFlag = true;
		}
		}
	} while (!terminateFlag);

	delete list;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
