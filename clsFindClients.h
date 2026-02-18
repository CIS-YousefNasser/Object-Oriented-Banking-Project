#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsFindClients:protected clsScreen
{
	static void _Print(clsBankClient client) {
		std::cout << "---------------------------------------------------\n";
		std::cout << "Account Number" << ":" << client.GetAccountNumber() << std::endl;
		std::cout << "pincode" << ":" << client.pincode << std::endl;
		std::cout << "First Name" << ":" << client.firstName << std::endl;
		std::cout << "Last Name" << ":" << client.lastName << std::endl;
		std::cout << "Full Name" << ":" << client.GetFullName() << std::endl;
		std::cout << "email" << ":" << client.email << std::endl;
		std::cout << "phone Number" << ":" << client.phoneNumber << std::endl;
		std::cout << "Balance" << ":" << client.balance << std::endl;
		std::cout << "---------------------------------------------------\n";

	}
	static clsBankClient _GetAvaliableClient() {
		std::string accountNumber;
	while (!clsBankClient::IsClientExist(accountNumber=clsInputValidate::AskForInput("Enter Client Account Number:")))
	{
		std::cout << "Client With Account Number(" << accountNumber << ")" << std::endl;
	}
		return clsBankClient::Find(accountNumber);

	}
public:
	static void FindClientScreen() {
		clsScreen::DrawScreen("Find Clients");
		_Print(_GetAvaliableClient());
	}
};

