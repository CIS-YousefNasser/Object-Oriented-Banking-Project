#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindUser :protected clsScreen
{
	static void _Print(clsUser user) {
		std::cout << "---------------------------------------------------\n";
		std::cout << "Username" << ":" << user.username << std::endl;
		std::cout << "Password" << ":" << user.password << std::endl;
		std::cout << "Full Name" << ":" << user.GetFullName() << std::endl;
		std::cout << "email" << ":" << user.email << std::endl;
		std::cout << "phone Number" << ":" << user.phoneNumber << std::endl;
		std::cout << "permissions" << ":" << user.permissions << std::endl;
		std::cout << "---------------------------------------------------\n";

	}
	static clsUser _GetAvaliableUsers() {
		std::string username;
		while (!clsUser::IsUserExist(username = clsInputValidate::AskForInput("Enter Username:")))
		{
			std::cout << "User With Username(" << username << ")" << std::endl;
		}
		return clsUser::Find(username);

	}
public:
	static void FindUserScreen() {
		clsScreen::DrawScreen("Find User");
		_Print(_GetAvaliableUsers());
	}
};

