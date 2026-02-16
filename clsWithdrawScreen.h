#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsWithdrawScreen :protected clsScreen
{
private:
	static void _ShowClientDataLine(clsBankClient& client) {
		std::cout << std::left << std::setw(16) << "|" + client.GetAccountNumber();
		std::cout << std::left << std::setw(24) << "|" + client.GetFullName();
		std::cout << "|" << client.balance << std::endl;
	}
	static double GetWithdrawAmount(clsBankClient& client) {
		double withdrawAmount;
		do {
			withdrawAmount = clsInputValidate::ReadPostiveDouble("Withdraw Amount:");
			if (client.balance < withdrawAmount)
				std::cout << "The amount you entered is bigger than what the account has" << std::endl;
		} while (client.balance < withdrawAmount);
		return withdrawAmount;
	}
	static bool _PerformWithdrawOption() {
		std::string accountNumber;
		while (!clsBankClient::IsClientExist(accountNumber = clsInputValidate::AskForInput("Enter Account Number:"))) {
			std::cout << "Not Found" << std::endl;
		}
		clsBankClient client = clsBankClient::Find(accountNumber);
		_ShowClientDataLine(client);
		client.Withdraw(GetWithdrawAmount(client));
		if (std::tolower(clsInputValidate::ReadChar("Are You Sure You Want To Perform Withdraw (y/n):")) == 'y') {
			std::cout << "Withdraw Complete!" << std::endl;
			std::cout << "Current Balance:" << client.balance << std::endl;
			return true;
		}
		std::cout << "Withdraw Cancelled" << std::endl;
		return false;


	}
public:
	static void ShowWithdrawOption() {
		system("cls");
		clsScreen::DrawScreen("Withdraw");
		_PerformWithdrawOption();
	}

};

