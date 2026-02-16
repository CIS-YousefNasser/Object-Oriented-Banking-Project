#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewUser.h"
#include "clsShowUsersScreen.h"
#include "clsDeleteUser.h"
#include "clsUpdateUser.h"
#include "clsFindUser.h"
class clsManageUserScreen:protected clsScreen
{
private:
	enum enManageUserMenu {
		usersList = 1, addNewUser = 2, deleteUser = 3, updateUser = 4, findUser = 5, returnToMain = 6,
	};
	static enManageUserMenu _NumberToManageUserEnum(int choice) {
		return static_cast<enManageUserMenu>(choice);
	}
	static void _ReturnToManageUserScreen() {
		system("pause");
		system("cls");
	}
	static void _ManageUserMenuScreen() {
		clsScreen::DrawScreen("Manage User");
		std::cout << "\t\t\t\t\t      " << "[1] List User" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[2] Add User" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[3] Delete User" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[4] Update User" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[5] Find User" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[6] Return to main menu" << std::endl;
		std::cout << "\t\t\t\t    " << "___________________________________________\n" << std::endl;
	}
	static int _GetManageUserChoice() {
		std::cout << "\t\t\t\t    Choose A Number Between[1-6]:";
		int number = clsInputValidate::ReadNumberBetween(1, 6, "Please Enter a Number Between[1-6]:");
		return number;
	}
	static void _ShowUsersOption() {
		clsShowUsersScreen::ShowUsersList();
		_ReturnToManageUserScreen();
	}

	static void _AddNewUserOption() {
		clsAddNewUser::AddNewUserScreen();
		_ReturnToManageUserScreen();
	
	}
	static void _DeleteUserOption() {
		clsDeleteUser::DeleteUserScreen();
		_ReturnToManageUserScreen();
	}
	static void _UpdateUserOption() {
		clsUpdateUser::UpdateUserInfoScreen();
		_ReturnToManageUserScreen();
	}
	static void _FindUserOption() {
		clsFindUser::FindUserScreen();
		_ReturnToManageUserScreen();
	}
	
	static enManageUserMenu _PerformManageUserOptions() {
		enManageUserMenu choice = _NumberToManageUserEnum(_GetManageUserChoice());
		system("cls");

		switch (choice) {

		case enManageUserMenu::usersList:
			_ShowUsersOption();
			break;
		case enManageUserMenu::addNewUser:
			_AddNewUserOption();
			break;
		case enManageUserMenu::deleteUser:
			_DeleteUserOption();
			break;
		case enManageUserMenu::updateUser:
			_UpdateUserOption();
			break;
		case enManageUserMenu::findUser:
			_FindUserOption();
			break;
		}
		return choice;
	}
public:
	static void ShowUserScreen() {

		do {
			_ManageUserMenuScreen();
		} while (_PerformManageUserOptions() != enManageUserMenu::returnToMain);
	}
};

