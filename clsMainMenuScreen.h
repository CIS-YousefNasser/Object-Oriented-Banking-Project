#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Windows.h"
#include "clsShowClients.h"
#include "clsAddNewClient.h"
#include "clsUpdateClient.h"
#include "clsDeleteClient.h"
#include "clsFindClients.h"
class clsMainMenuScreen:protected clsScreen
{
private:
	enum enMainMenuOptions {
		showClientList=1,addNewClient=2,deleteClient=3,updateClientInfo=4,findClient=5,Transactions=6,manageUsers=7,logout=8
	};
	
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
		std::cout << "Feature coming soon" << std::endl;
		ReturnToMainMenu();
	}
	static void _ManageUsersScreen() {
		std::cout << "Feature coming soon" << std::endl;
		ReturnToMainMenu();
	}
	static enMainMenuOptions _NumberToMainMenuOptions(int number) {
		return static_cast<enMainMenuOptions>(number);
	}
	static int _GetMainMenuChoice() {
		std::cout << "\t\t\t\t    Choose A Number Between[1-8]:";
		int number=clsInputValidate::ReadNumberBetween(1,8,"Please Enter a Number Between[1-8]:");
		return number;
	}
	
	static enMainMenuOptions _PerformMainMenuOptions() {
		enMainMenuOptions choice = _NumberToMainMenuOptions(_GetMainMenuChoice());
		system("cls");
		switch (choice) {
		case enMainMenuOptions::showClientList:
			_ShowClientListScreen();
			break;
		case enMainMenuOptions::addNewClient:
			_AddClientsScreen();
			break;
		case enMainMenuOptions::deleteClient:
			_DeleteClientsScreen();
			break;
		case enMainMenuOptions::updateClientInfo:
			_UpdateClientInfoScreen();
			break;
		case enMainMenuOptions::findClient:
			_FindClientsScreen();
			break;
		case enMainMenuOptions::Transactions:
			_TransactionsScreen();
			break;
		case enMainMenuOptions::manageUsers:
			_ManageUsersScreen();
			break;
		case enMainMenuOptions::logout:
			break;
		default:
			std::cout << "Error In Perform Main Menu Options" << std::endl;
		}
		return choice;

	}

public:
	static void MainMenuScreen() {
		do {
			clsScreen::DrawScreen("Main Menu");
			std::cout << "\t\t\t\t    ___________________________________________\n" << std::endl;
			std::cout << "\t\t\t\t\t\t " << "Main Menu Options" << std::endl;
			std::cout << "\t\t\t\t    " << "___________________________________________\n" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[1] Show Client List" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[2] Add New Client" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[3] Delete Client" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[4] Update Client Info" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[5] Find Client" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[6] Transactions" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[7] Manage Users" << std::endl;
			std::cout << "\t\t\t\t\t      " << "[8] Logout" << std::endl;
			std::cout << "\t\t\t\t    " << "___________________________________________\n" << std::endl;

		} while (_PerformMainMenuOptions() != enMainMenuOptions::logout);
	}
};

