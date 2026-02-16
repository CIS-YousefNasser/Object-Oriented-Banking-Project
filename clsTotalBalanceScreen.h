#pragma once
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTotalBalanceScreen:protected clsScreen
{
private:
	static void _TotalBalanceHeader(const std::vector<clsBankClient>& vClient) {
		clsScreen::DrawScreen("Total Balance", "Amount of clients(" + std::to_string(vClient.size()) + ")");
		std::cout << "\t\t" << "_________________________________________________________________________" << std::endl;
		std::cout << "\t\t" << "|Accout Number\t|Client Name\t\t|Balance" << std::endl;
		std::cout << "\t\t" << "_________________________________________________________________________" << std::endl;

	}
	static void _ShowClientDataLine(clsBankClient& client) {
		std::cout << "\t\t" << std::left << std::setw(16) << "|" + client.GetAccountNumber();
		std::cout << std::left << std::setw(24) << "|" + client.GetFullName();
		std::cout << "|" << client.balance << std::endl;
	}
	static void _ShowTotalBalanceScreen() {
		std::vector<clsBankClient>vClient = clsBankClient::GetClientsData();
		if (vClient.size() < 1) {
			std::cout << "No Clients Available" << std::endl;
			return;
		}
		_TotalBalanceHeader(vClient);

		for (clsBankClient& client : vClient)
			_ShowClientDataLine(client);
		std::cout << "\t\t" << "_________________________________________________________________________" << std::endl;
		std::cout << std::right << std::setw(80) << "Total Balance:" << clsBankClient::TotalBalances() << std::endl;


	}
public:
	
	static void ShowTotalBalanceScreen() {
		system("cls");
		_ShowTotalBalanceScreen();
	}

};
