#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
class clsShowUsersScreen:protected clsScreen
{
private:
	static void PrintUserData(clsUser& userData) {
		std::cout <<"\t"<< "|" << std::setw(15) << std::left << userData.username;
		std::cout << " |" << std::setw(23) << std::left << userData.GetFullName();
		std::cout << "|" << std::setw(15) << std::left << userData.phoneNumber;
		std::cout << "|" << std::setw(15) << std::left << userData.email;
		std::cout << "|" << std::setw(14) << std::left << userData.password;

		std::cout << "|" << userData.permissions;
		std::cout << std::endl;
	}
	static void _PrintUsersDetailsHeader(int usersCounter) {
		clsScreen::DrawScreen("Users List", " Users List (" + std::to_string(usersCounter) + ")" + "Users(s)");
		std::cout <<"\t" << "________________________________________________________________________________________________________" << std::endl;
		std::cout <<"\t" << "|Username\t |Client Name\t\t |Phone\t\t |Email\t\t |Password\t|permissions" << std::endl;
		std::cout << "\t" << "________________________________________________________________________________________________________" << std::endl;

	}
	static void _PrintAllUsersDetails() {
		std::vector<clsUser> usersData = clsUser::GetUsersData();
		if (usersData.size() < 1) {
			std::cout << "No Users Available" << std::endl;
			return;
		}
		_PrintUsersDetailsHeader(usersData.size());
		for (int i = 0; i < usersData.size(); i++) {
			PrintUserData(usersData[i]);
		}
		std::cout << "\t" << "________________________________________________________________________________________________________" << std::endl;

	}
public:
	static void ShowUsersList() {
		_PrintAllUsersDetails();
	}
};

