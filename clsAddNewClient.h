#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsAddNewClientScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& client) {
		std::cout << "Please Enter First Name:";
		client.firstName = clsInputValidate::ReadString();
		std::cout << "Please Enter Last Name:";
		client.lastName = clsInputValidate::ReadString();
		std::cout << "Please Enter Email:";
		client.email = clsInputValidate::ReadString();
		std::cout << "Please Enter Phone Number:";
		client.phoneNumber = clsInputValidate::ReadString();
		std::cout << "Please Enter Pincode:";
		client.pincode = clsInputValidate::ReadString();
		std::cout << "Please Enter Balance:";
		client.balance = clsInputValidate::ValidateDoubleNumber("Please enter a valid Balance");
	}
	static void _AddNewClient() {
		std::string accountNumber;
		while (clsBankClient::IsClientExist(accountNumber = clsInputValidate::AskForInput("Enter Account Number:"))) {
			std::cout << "Account Number Already Exists" << std::endl;
		}
		clsBankClient client = clsBankClient::GetNewClient(accountNumber);
		_ReadClientInfo(client);
		switch (client.Save()) {
		case clsBankClient::enSaveClient::svSuccesseded:
			std::cout << "Account Added Successfully" << std::endl;
			break;
		case clsBankClient::enSaveClient::svFailedEmptyObject:
			std::cout << "Add Attempt Failed" << std::endl;
			break;
		case clsBankClient::enSaveClient::svFailedAccountNumberExist:
			std::cout << "With This Number Already Exists " << std::endl;
			break;
		default:
			std::cout << "Account Add Attempt Failed" << std::endl;

		}
	}
public:
	static void AddNewClientScreen() {
		clsScreen::DrawScreen("Add New Client");
		_AddNewClient();

	}
};

