#pragma once
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
class clsDeleteClient:protected clsScreen
{
private:
	static void _Print(clsBankClient &client) {
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
	static void _DeleteClient() {
		std::string accountNumber;

		while (!(clsBankClient::IsClientExist(accountNumber = clsInputValidate::AskForInput("Enter Account Number:")))) {
			std::cout << "Please Enter a valid Account Number" << std::endl;
		}
		clsBankClient client = clsBankClient::Find(accountNumber);
		_Print(client);
		if (std::tolower(clsInputValidate::ReadChar("Do you want to delete this account (y/n):")) == 'y') {
			client.Delete();
			_Print(client);
		}
		else
			std::cout << "Deletion Cancelled" << std::endl;
	}
public:

	static void DeleteClientScreen() {
		clsScreen::DrawScreen("Delete Client");
		_DeleteClient();
	}

};

