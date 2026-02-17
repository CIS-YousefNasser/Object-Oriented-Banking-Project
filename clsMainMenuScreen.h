#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Windows.h"
#include "clsShowClients.h"
#include "clsAddNewClient.h"
#include "clsUpdateClient.h"
#include "clsDeleteClient.h"
#include "clsFindClients.h"
#include "clsTransactionScreen.h"
#include "clsManageUserScreen.h"
#include "Global.h"
class clsMainMenuScreen:protected clsScreen
{
private:
	enum enAllowAccess {
		all = -1, showOptionCode = 1, addOptionCode = 2, deleteOptionCode = 4, searchOptionCode = 8, updateOptionCode = 16, transactionsOptionCode = 32, usersMenuCode = 64,logout=128

	};
	static short enAllowAccessToShort(enAllowAccess choice) {
		return static_cast<short>(choice);
	}
	static void ReturnToMainMenu() {
		system("pause");
		system("cls");
	}
	static void _ShowClientListScreen() {
		clsShowClients::ShowClientsList();
		ReturnToMainMenu();
	}
	static void _AddClientsScreen() {
		clsAddNewClientScreen::AddNewClientScreen();
		ReturnToMainMenu();
	}
	static void _DeleteClientsScreen() {
		clsDeleteClient::DeleteClientScreen();
		ReturnToMainMenu();
	}
	static void _UpdateClientInfoScreen() {
		clsUpdateClient::UpdateClientInfoScreen();
		ReturnToMainMenu();
	}
	static void _FindClientsScreen() {
		clsFindClients::FindClientScreen();
		ReturnToMainMenu();
	}
	static void _TransactionsScreen() {
		clsTransactionScreen::TransactionScreen();
		ReturnToMainMenu();
	}
	static void _ManageUsersScreen() {
		clsManageUserScreen::ShowUserScreen();
		ReturnToMainMenu();
	}
	static short _GetMainMenuChoice(short &to) {
		std::cout << "\t\t\t\t    Choose A Number Between[1-"<<to<<"]:";
		short number=clsInputValidate::ReadNumberBetween(1,to,"Please Enter a Number Between[1-"+std::to_string(to)+"]:");
		return number;
	}
	static enAllowAccess _NumberToEnumAllowAccess(short choice, std::vector<short>& vOptions) {
		return static_cast<enAllowAccess>(vOptions[choice-1]);
	}
	
	static enAllowAccess _PerformMainMenuOptions(short &to, std::vector<short> &vOptions) {
		enAllowAccess choice = _NumberToEnumAllowAccess(_GetMainMenuChoice(to),vOptions);
		system("cls");
		switch (choice) {
		case enAllowAccess::showOptionCode:
			_ShowClientListScreen();
			break;
		case enAllowAccess::addOptionCode:
			_AddClientsScreen();
			break;
		case enAllowAccess::deleteOptionCode:
			_DeleteClientsScreen();
			break;
		case enAllowAccess::updateOptionCode:
			_UpdateClientInfoScreen();
			break;
		case enAllowAccess::searchOptionCode:
			_FindClientsScreen();
			break;
		case enAllowAccess::transactionsOptionCode:
			_TransactionsScreen();
			break;
		case enAllowAccess::usersMenuCode:
			_ManageUsersScreen();
			break;
		case enAllowAccess::logout:
			break;
		default:
			std::cout << "Error In Perform Main Menu Options" << std::endl;
		}
		return choice;

	}
	static void Logout() {
		currentUser.GetEmptyUser();
	}

public:
	static void MainMenuScreen() {
		std::vector<short> vOptions;
		bool collectedOptions=false;
		short numberOfMenu;
		do {
			numberOfMenu = 0;
			clsScreen::DrawScreen("Main Menu");
			if (currentUser.IsAllowedAccess(enAllowAccessToShort(enAllowAccess::showOptionCode))) {
				std::cout << "\t\t\t\t\t      " << "[" << ++numberOfMenu << "] Show Client List" << std::endl;
				if (!collectedOptions) {
					vOptions.push_back(enAllowAccessToShort(enAllowAccess::showOptionCode));
				}
			}
			if (currentUser.IsAllowedAccess(enAllowAccessToShort(enAllowAccess::addOptionCode))) {
				std::cout << "\t\t\t\t\t      " << "[" << ++numberOfMenu << "] Add New Client" << std::endl;
				if (!collectedOptions) {
					vOptions.push_back(enAllowAccessToShort(enAllowAccess::addOptionCode));
				}
				

			}
			if (currentUser.IsAllowedAccess(enAllowAccessToShort(enAllowAccess::deleteOptionCode))) {
				std::cout << "\t\t\t\t\t      " << "[" << ++numberOfMenu << "] Delete Client" << std::endl;
				if (!collectedOptions) {
					vOptions.push_back(enAllowAccessToShort(enAllowAccess::deleteOptionCode));
				}
				
			}
			if (currentUser.IsAllowedAccess(enAllowAccessToShort(enAllowAccess::updateOptionCode))){
				std::cout << "\t\t\t\t\t      " << "[" << ++numberOfMenu << "] Update Client Info" << std::endl;
				if (!collectedOptions) {
                 vOptions.push_back(enAllowAccessToShort(enAllowAccess::updateOptionCode));
				}
				

			}
			if (currentUser.IsAllowedAccess(enAllowAccessToShort(enAllowAccess::searchOptionCode))){
				std::cout << "\t\t\t\t\t      " << "[" << ++numberOfMenu << "] Find Client" << std::endl;
				if (!collectedOptions) {
					vOptions.push_back(enAllowAccessToShort(enAllowAccess::searchOptionCode));
				}
				

			}
			if (currentUser.IsAllowedAccess(enAllowAccessToShort(enAllowAccess::transactionsOptionCode))){
				std::cout << "\t\t\t\t\t      " << "[" << ++numberOfMenu << "] Transactions" << std::endl;
				if (!collectedOptions) {
                 vOptions.push_back(enAllowAccessToShort(enAllowAccess::transactionsOptionCode));
				}
				

			}
			if (currentUser.IsAllowedAccess(enAllowAccessToShort(enAllowAccess::usersMenuCode))){
				std::cout << "\t\t\t\t\t      " << "[" << ++numberOfMenu << "] Manage Users" << std::endl;
				if (!collectedOptions) {
					vOptions.push_back(enAllowAccessToShort(enAllowAccess::usersMenuCode));
				}
				
			}
			
				std::cout << "\t\t\t\t\t      " << "[" <<++numberOfMenu << "] Logout" << std::endl;
				if (!collectedOptions) {
					vOptions.push_back(enAllowAccessToShort(enAllowAccess::logout));

			}
			
			std::cout << "\t\t\t\t    " << "___________________________________________\n" << std::endl;
			collectedOptions = true;
		} while (_PerformMainMenuOptions(numberOfMenu,vOptions) != enAllowAccess::logout);

		Logout();
	}
};

