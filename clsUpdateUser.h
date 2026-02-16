#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsUpdateUser :protected clsScreen
{
private:
	enum enAllowAccess {
		all = -1, showOptionCode = 1, addOptionCode = 2, deleteOptionCode = 4, searchOptionCode = 8, updateOptionCode = 16, transactionsOptionCode = 32, usersMenuCode = 64

	};
	static short enAllowAccessToInt(enAllowAccess choice) {
		return static_cast<short>(choice);
	}
	static short GetPermissions() {
		short permission = 0;
		char choice;
		choice = clsInputValidate::ReadChar("Do you want to give permission to everything y / n:");
		if (toupper(choice) == 'Y') {
			permission = enAllowAccessToInt(enAllowAccess::all);
		}
		else {
			if (tolower(clsInputValidate::ReadChar("Allow user to Show Clients Data:")) == 'y') {
				permission = permission | enAllowAccessToInt(enAllowAccess::showOptionCode);//2^0
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Add New Clients:")) == 'y') {
				permission = permission | enAllowAccessToInt(enAllowAccess::addOptionCode);//2^1
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Delete A Clients:")) == 'y') {
				permission = permission | enAllowAccessToInt(enAllowAccess::deleteOptionCode);//2^2
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Find Clients:")) == 'y') {
				permission = permission | enAllowAccessToInt(enAllowAccess::searchOptionCode);//2^3
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Update Clients:")) == 'y') {
				permission = permission | enAllowAccessToInt(enAllowAccess::updateOptionCode);//2^4
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to use Transaction:")) == 'y') {
				permission = permission | enAllowAccessToInt(enAllowAccess::transactionsOptionCode);//2^5
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Manage users :")) == 'y') {
				permission = permission | enAllowAccessToInt(enAllowAccess::usersMenuCode);//2^6
			}
		}

		return permission;
	}
	bool IsAllowedAccess(short userPermissonNumber, short choiceNumber) {
		return ((choiceNumber & userPermissonNumber) == choiceNumber);
	}
	static void _ReadUserInfo(clsUser& user) {
		user.firstName = clsInputValidate::AskForInput("Please Enter First Name:");
		user.lastName = clsInputValidate::AskForInput("Please Enter Last Name:");
		user.email = clsInputValidate::AskForInput("Please Enter Email:");
		user.phoneNumber = clsInputValidate::AskForInput("Please Enter Phone Number:");
		user.password = clsInputValidate::AskForInput("Please Enter Password:");
		user.permissions = GetPermissions();
	}
	static void _UpdateUserInfo() {
		std::string username;
		while (!(clsUser::IsUserExist(username = clsInputValidate::AskForInput("Enter Username:")))) {
			std::cout << "Please Enter a valid Username" << std::endl;
		}
		clsUser user = clsUser::Find(username);
		_ReadUserInfo(user);
		switch (user.Save()) {
		case clsUser::enSaveUser::svSuccesseded:
			std::cout << "Account Updated Successfully" << std::endl;
			break;
		case clsUser::enSaveUser::svFailedEmptyObject:
		default:
			std::cout << "Account Update Failed";
		}
	}
public:

	static void UpdateUserInfoScreen() {
		clsScreen::DrawScreen("Update User Info");
		_UpdateUserInfo();
	}

};

