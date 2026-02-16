#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsDeleteUser:protected clsScreen
{
private:
	static void _Print(clsUser& user) {
		std::cout << "---------------------------------------------------\n";
		std::cout << "Username" << ":" << user.username << std::endl;
		std::cout << "Password" << ":" << user.password << std::endl;
		std::cout << "Full Name" << ":" << user.GetFullName() << std::endl;
		std::cout << "email" << ":" << user.email << std::endl;
		std::cout << "phone Number" << ":" << user.phoneNumber << std::endl;
		std::cout << "permissions" << ":" << user.permissions << std::endl;
		std::cout << "---------------------------------------------------\n";

	}
	static void _DeleteUser() {
		std::string username;

		while (!(clsUser::IsUserExist(username = clsInputValidate::AskForInput("Enter username:")))) {
			std::cout << "Please Enter a valid Username" << std::endl;
		}
		if (username == "Admin") {
			std::cout << "Admin cannot be deleted" << std::endl;
			return;
		}
		clsUser user = clsUser::Find(username);
		_Print(user);
		if (std::tolower(clsInputValidate::ReadChar("Do you want to delete this account (y/n):")) == 'y') {
			user.Delete();
			_Print(user);
		}
		else
			std::cout << "Deletion Cancelled" << std::endl;
	}
public:

	static void DeleteUserScreen() {
		clsScreen::DrawScreen("Delete User");
		_DeleteUser();
	}

};

