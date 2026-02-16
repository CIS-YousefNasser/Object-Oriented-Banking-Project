#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

class clsBankClient :public clsPerson
{
private:
	enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
	enMode _mode;
	std::string _accountNumber;
	std::string _pincode;
	double _balance;
	bool _markForDeletion =false;

	static clsBankClient _ConvertLinetoBankClientObject(std::string line, std::string Delimiter = "#//#") {
		std::vector<std::string> data;
		data = clsString::Split(line, Delimiter);
		return clsBankClient(enMode::updateMode, data[0], data[1], data[2], data[3], data[4], data[5], stod(data[6]));
	}
	static std::string _GetAccountNumberFromLine(std::string line, std::string delimiter = "#//#") {
		std::vector<std::string> data;
		data = clsString::Split(line, delimiter);
		return data[4];
	}
	
	 static std::string _ConvertClientObjectToDataLine(clsBankClient &client, std::string delimiter = "#//#") {
		std::string line;
		line += client.firstName + delimiter;
		line += client.lastName + delimiter;
		line += client.email + delimiter;
		line += client.phoneNumber + delimiter;
		line += client.GetAccountNumber() + delimiter;
		line += client.pincode + delimiter;
		line += std::to_string(client.balance);
		return line;

	}
	 void _AddNewClientLineToFile(const std::string &line) {
		std::ofstream file;
		file.open("Clients.txt", std::ios::app);
		if (file.is_open()) {
			file << line << std::endl;
		}
		file.close();
	}
	static std::vector<clsBankClient> _LoadClientDataFromFile() {
		std::vector<clsBankClient>clientsData;
		std::ifstream file;
		std::string line;
		file.open("Clients.txt", std::ios::in);
		if (file.is_open()) {
			while (std::getline(file, line)) {
				clientsData.push_back(_ConvertLinetoBankClientObject(line));
			}
		}
		file.close();
		return clientsData;
	}
	static void _SaveClientDataToFile(std::vector<clsBankClient> &clientsData) {
		std::ofstream file;
		std::string line;
		file.open("Clients.txt", std::ios::out);
		if (file.is_open()) {
			for (clsBankClient& client : clientsData) {
				if (client._markForDeletion) {
					continue;
				}
				file << _ConvertClientObjectToDataLine(client) <<std::endl;
			}
		}
		file.close();
	}
	void _Update() {
		std::vector<clsBankClient>clientsData = _LoadClientDataFromFile();
		for (clsBankClient& client : clientsData) {
			if (client.GetAccountNumber() == this->_accountNumber) {
				client = *this;
			}
		}
	_SaveClientDataToFile(clientsData);
	}
	void _AddClient() {
			_AddNewClientLineToFile(_ConvertClientObjectToDataLine(*this));
	}
public:
	clsBankClient(enMode mode, std::string firstName, std::string lastName, std::string email,
		std::string phoneNumber, std::string accountNumber, std::string pincode, double balance)
		:clsPerson(firstName, lastName, email, phoneNumber) {
		_mode = mode;
		_pincode = pincode;
		_accountNumber = accountNumber;
		_balance = balance;
	}
	std::string GetAccountNumber() {
		return _accountNumber;
	}
	void SetPincode(std::string pincode) {
		_pincode = pincode;
	}
	std::string GetPincode() {
		return _pincode;
	}
	void SetBalance(double balance) {
		_balance = balance;
	}
	double GetBalance() {
		return _balance;
	}
	__declspec(property(put = SetPincode, get = GetPincode))std::string pincode;
	__declspec(property(put = SetBalance, get = GetBalance))double balance;
	static clsBankClient GetEmptyClient() {
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}
	bool IsEmpty() {
		return _mode == enMode::emptyMode;
	}
	static clsBankClient Find(std::string accountNumber) {
		std::ifstream file;
		std::string line;
		std::string clientAccountNumber;
		file.open("Clients.txt", std::ios::in);
		if (file.is_open()) {
			while (std::getline(file, line)) {
				clientAccountNumber = _GetAccountNumberFromLine(line);
				if (clientAccountNumber == accountNumber) {
					clsBankClient client = _ConvertLinetoBankClientObject(line);
					file.close();
					return client;
				}

			}
		}
		file.close();
		return GetEmptyClient();
	}
	static clsBankClient find(std::string accountNumber, std::string pincode) {
		clsBankClient client = Find(accountNumber);
		if (!(client.IsEmpty()) && client.pincode == pincode)
			return client;
		return GetEmptyClient();
	}
	static bool IsClientExist(std::string accountNumber) {
		return !(Find(accountNumber).IsEmpty());
	}
	static clsBankClient GetNewClient(std::string accountNumber) {
		return clsBankClient(clsBankClient::addNewMode, "", "", "", "", accountNumber, "", 0);
	}
	enum enSaveClient { svFailedEmptyObject = 0, svSuccesseded=1,svFailedAccountNumberExist=2};
	enSaveClient Save() {
		switch (_mode) {
		case enMode::emptyMode:
			if (IsEmpty())
				return enSaveClient::svFailedEmptyObject;

		case enMode::updateMode:
			_Update();
			return enSaveClient::svSuccesseded;
		case enMode::addNewMode:
			if (IsClientExist(this->_accountNumber)) {
				return enSaveClient::svFailedAccountNumberExist;
			}
			else {
				_AddClient();
				_mode = enMode::updateMode;
				return enSaveClient::svSuccesseded;
			}
		default:
			return enSaveClient::svFailedEmptyObject;
		}
	}
	bool Delete() {
		if (!IsClientExist(this->_accountNumber)) {
			return false;
		}
		std::vector<clsBankClient> clientsData = _LoadClientDataFromFile();
		for (clsBankClient& client : clientsData) {
			if (this->_accountNumber == client._accountNumber) {
				client._markForDeletion = true;
				*this = GetEmptyClient();
			}
		}
		_SaveClientDataToFile(clientsData);
		return true;
	}
    static std::vector<clsBankClient> GetClientsData(){
		return _LoadClientDataFromFile();
	}
	void Deposit(double amount) {
		balance += amount;
	    Save();
	}
	void Withdraw(double amount) {
		balance -= amount;
		Save();
	}
	static double TotalBalances() {
		std::vector<clsBankClient> clientsData = _LoadClientDataFromFile();
		double totalBalance=0;
		for (clsBankClient& client : clientsData) {
			totalBalance+=client.balance;
		}
		return totalBalance;
	}
};

