#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDepositScreen:protected clsScreen
{
private:
	static void _ShowClientDataLine(clsBankClient& client) {
		std::cout << std::left << std::setw(16) << "|" + client.GetAccountNumber();
		std::cout << std::left << std::setw(24) << "|" + client.GetFullName();
		std::cout << "|" << client.balance << std::endl;
	}
	static bool _PerformDepositOption() {
		std::string accountNumber;
		while (!clsBankClient::IsClientExist(accountNumber= clsInputValidate::AskForInput("Enter Account Number:"))) {
			std::cout << "Not Found" << std::endl;
		}
		clsBankClient client = clsBankClient::Find(accountNumber);
		_ShowClientDataLine(client);
		client.Deposit(clsInputValidate::ReadPostiveDouble("Deposit Amount:"));
		if (std::tolower(clsInputValidate::ReadChar("Are You Sure You Want To Perform Deposit (y/n):")) == 'y') {
			std::cout << "Deposit Complete" << std::endl;
			std::cout << "Current Balance:" <<client.balance<< std::endl;
			return true;
		}
			std::cout << "Deposit Cancelled" << std::endl;
			return false;

	}
public:
	static void ShowDepositOption() {
		system("cls");
		clsScreen::DrawScreen("Deposit");
		_PerformDepositOption();
	}

};

