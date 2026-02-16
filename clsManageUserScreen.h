#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewUser.h"
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
	static void _ShowDepositOption() {
	
		_ReturnToManageUserScreen();
	}
	static void _AddNewUserOption() {

		_ReturnToManageUserScreen();
	
	}
	static void _DeleteUserOption() {

		_ReturnToManageUserScreen();
	}
	static void _UpdateUserOption() {

		_ReturnToManageUserScreen();
	}
	static void _FindUserOption() {

		_ReturnToManageUserScreen();
	}
	
	static enManageUserMenu _PerformManageUserOptions() {
		enManageUserMenu choice = _NumberToManageUserEnum(_GetManageUserChoice());
		switch (choice) {

		case enManageUserMenu::usersList:
			std::cout << "coming soon" << std::endl;
			break;
		case enManageUserMenu::addNewUser:
			clsAddNewUser::AddNewUserScreen();
			break;
		case enManageUserMenu::deleteUser:
			std::cout << "coming soon" << std::endl;
			break;
		case enManageUserMenu::updateUser:
			std::cout << "coming soon" << std::endl;
			break;
		case enManageUserMenu::findUser:
			std::cout << "coming soon" << std::endl;
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

