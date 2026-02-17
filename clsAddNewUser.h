#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsAddNewUser:protected clsScreen
{
private:
	enum enAllowAccess {
		all = -1, showOptionCode = 1, addOptionCode = 2, deleteOptionCode = 4, searchOptionCode = 8, updateOptionCode = 16, transactionsOptionCode = 32, usersMenuCode = 64

	};
	static short enAllowAccessToShort(enAllowAccess choice) {
		return static_cast<short>(choice);
	}
	static short GetPermissions() {
		short permission = 0;
		char choice;
		choice = clsInputValidate::ReadChar("Do you want to give permission to everything y / n:");
		if (toupper(choice) == 'Y') {
			permission = enAllowAccessToShort(enAllowAccess::all);
		}
		else {
			if (tolower(clsInputValidate::ReadChar("Allow user to Show Clients Data:")) == 'y') {
				permission = permission | enAllowAccessToShort(enAllowAccess::showOptionCode);//2^0
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Add New Clients:")) == 'y') {
				permission = permission | enAllowAccessToShort(enAllowAccess::addOptionCode);//2^1
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Delete A Clients:")) == 'y') {
				permission = permission | enAllowAccessToShort(enAllowAccess::deleteOptionCode);//2^2
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Find Clients:")) == 'y') {
				permission = permission | enAllowAccessToShort(enAllowAccess::searchOptionCode);//2^3
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Update Clients:")) == 'y') {
				permission = permission | enAllowAccessToShort(enAllowAccess::updateOptionCode);//2^4
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to use Transaction:")) == 'y') {
				permission = permission | enAllowAccessToShort(enAllowAccess::transactionsOptionCode);//2^5
			}
			if (tolower(clsInputValidate::ReadChar("Allow user to Manage users :")) == 'y') {
				permission = permission | enAllowAccessToShort(enAllowAccess::usersMenuCode);//2^6
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
	static void _AddNewUser() {
		std::string username;
		while (clsUser::IsUserExist(username = clsInputValidate::AskForInput("Enter Username:"))) {
			std::cout << "Username Already Exists" << std::endl;
		}
		clsUser user = clsUser::GetNewUser(username);
		_ReadUserInfo(user);
		switch (user.Save()) {
		case clsUser::enSaveUser::svSuccesseded:
			std::cout << "Account Added Successfully" << std::endl;
			break;
		case clsUser::enSaveUser::svFailedEmptyObject:
			std::cout << "Add Attempt Failed" << std::endl;
			break;
		case clsUser::enSaveUser::svFailedUsernameExist:
			std::cout << "Account With This Username Already Exists " << std::endl;
			break;
		default:
			std::cout << "Account Add Attempt Failed" << std::endl;

		}
	}
public:
	static void AddNewUserScreen() {
		clsScreen::DrawScreen("Add New User");
		_AddNewUser();

	}
};

