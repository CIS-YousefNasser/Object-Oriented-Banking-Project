#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
class clsTransactionScreen:protected clsScreen
{
private:
	enum enTransactionsMenu {
		deposit = 1, withdraw = 2, totalBalances = 3, returnToMainMenu = 4
	};
	static enTransactionsMenu _NumberToTransactionMenuChoicesEnum(int choice) {
		return static_cast<enTransactionsMenu>(choice);
	}
	static void _ReturnToTransactionScreen() {
		system("pause");
		system("cls");
	}
	static void _TransactionsMenuScreen() {
		clsScreen::DrawScreen("Transactions");
		std::cout << "\t\t\t\t\t      " << "[1] Deposit" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[2] Withdraw" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[3] Show Total Balance" << std::endl;
		std::cout << "\t\t\t\t\t      " << "[4] Return to main menu" << std::endl;
		std::cout << "\t\t\t\t    " << "___________________________________________\n" << std::endl;
	}
	static int _GetTransactionChoice() {
		std::cout << "\t\t\t\t    Choose A Number Between[1-4]:";
		int number = clsInputValidate::ReadNumberBetween(1, 4, "Please Enter a Number Between[1-4]:");
		return number;
	}
	static void _ShowDepositOption() {
		clsDepositScreen::ShowDepositOption();
		_ReturnToTransactionScreen();
	}
	static void _ShowWithDrawScreen() {
		clsWithdrawScreen::ShowWithdrawOption();
		_ReturnToTransactionScreen();
	}
	static void _ShowTotalBalance() {
		clsTotalBalanceScreen::ShowTotalBalanceScreen();
		_ReturnToTransactionScreen();
	}
	static enTransactionsMenu _PerformTransactionOptions() {
		enTransactionsMenu choice = _NumberToTransactionMenuChoicesEnum(_GetTransactionChoice());
		switch (choice) {

		case enTransactionsMenu::deposit:
			_ShowDepositOption();
			break;
		case enTransactionsMenu::withdraw:
			_ShowWithDrawScreen();
			break;
		case enTransactionsMenu::totalBalances:
			_ShowTotalBalance();
			break;
		}
		return choice;
	}
public:
	
	static void TransactionScreen() {
		do {
			_TransactionsMenuScreen();
		} while (_PerformTransactionOptions() != enTransactionsMenu::returnToMainMenu);
	}

};

