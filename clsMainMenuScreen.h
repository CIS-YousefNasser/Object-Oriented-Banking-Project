#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>
class clsShowClients:protected clsScreen
{
private:
	static void _ClientsListHeader(const std::vector<clsBankClient>& vClient) {
		clsScreen::DrawScreen("Clients List", "Amount of clients(" + std::to_string(vClient.size()) + ")");
		std::cout << std::right << std::setw(5) << " ________________________________________________________________________________________________________________" << std::endl;
		std::cout << std::right << std::setw(5) << " |Accout Number\t |Client Name\t\t |Phone\t\t\t |Email\t\t\t |pincode\t|Balance" << std::endl;
		std::cout << std::right << std::setw(5) << " ________________________________________________________________________________________________________________" << std::endl;

	}
	static void _FullClientDataLine(clsBankClient& client) {
		std::cout << std::left << std::setw(16) << " |" + client.GetAccountNumber();
		std::cout << std::left << std::setw(24) << " |" + client.GetFullName();
		std::cout << std::left << std::setw(24) << " |" + client.phoneNumber;
		std::cout << std::left << std::setw(24) << " |" + client.email;
		std::cout << std::left << std::setw(16) << " |" + client.pincode;
		std::cout << "|" << client.balance << std::endl;

	}
public:
	static void ShowClientsList() {
		std::vector<clsBankClient>vClient = clsBankClient::GetClientsData();
		if (vClient.size() < 1) {
			std::cout << "No Clients Available" << std::endl;
			return;
		}
		_ClientsListHeader(vClient);

		for (clsBankClient& client : vClient)
			_FullClientDataLine(client);
		std::cout << std::right << std::setw(5) << " ________________________________________________________________________________________________________________" << std::endl;


	}

};

