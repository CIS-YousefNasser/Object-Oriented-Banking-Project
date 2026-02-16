#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsUpdateClient:protected clsScreen
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
	static void _UpdateClientInfo() {
		std::string accountNumber;
		while (!(clsBankClient::IsClientExist(accountNumber = clsInputValidate::AskForInput("Enter Account Number:")))) {
			std::cout << "Please Enter a valid Account Number" << std::endl;
		}
		clsBankClient client = clsBankClient::find(accountNumber);
		_ReadClientInfo(client);
		switch (client.save()) {
		case clsBankClient::enSaveClient::svSuccesseded:
			std::cout << "Account Updated Successfully" << std::endl;
			break;
		case clsBankClient::enSaveClient::svFailedEmptyObject:
		default:
			std::cout << "Account Update Failed";
		}
	}
public:

	static void UpdateClientInfoScreen() {
		clsScreen::DrawScreen("Update Client Info");
		_UpdateClientInfo();
	}

};

