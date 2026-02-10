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
	enum enMode { emptyMode = 0, updateMode = 1 };
	enMode _mode;
	std::string _accountNumber;
	std::string _pincode;
	double _balance;
	static clsBankClient _ConvertLinetoBankClientObject(std::string line, std::string Delimiter = "#//#") {
		std::vector<std::string> data;
		data = clsString::Split(line, Delimiter);
		return clsBankClient(enMode::updateMode, data[0], data[1], data[2], data[3], data[4], data[5], stod(data[6]));
	}
	static std::string _GetAccountNumberFromLine(std::string line, std::string Delimiter = "#//#") {
		std::vector<std::string> data;
		data = clsString::Split(line, Delimiter);
		return data[4];
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

	void Print() {
		std::cout << "\n---------------------------------------------------\n";
		std::cout << std::left << std::setw(25) << "Account Number" << ":" << _accountNumber << std::endl;
		std::cout << std::left << std::setw(25) << "pincode" << ":" << _pincode << std::endl;
		std::cout << std::left << std::setw(25) << "First Name" << ":" << firstName << std::endl;
		std::cout << std::left << std::setw(25) << "Last Name" << ":" << lastName << std::endl;
		std::cout << std::left << std::setw(25) << "Full Name" << ":" << GetFullName() << std::endl;
		std::cout << std::left << std::setw(25) << "email" << ":" << email << std::endl;
		std::cout << std::left << std::setw(25) << "phone Number" << ":" << phoneNumber << std::endl;
		std::cout << "\n---------------------------------------------------\n";

	}
	static clsBankClient GetEmptyClient() {
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}
	bool IsEmpty() {
		return _mode == enMode::emptyMode;
	}
	static clsBankClient find(std::string accountNumber) {
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
		clsBankClient client = find(accountNumber);
		if (!(client.IsEmpty()) && client.pincode == pincode)
			return client;
		return GetEmptyClient();
	}
	static bool IsClientExist(std::string accountNumber) {
		return !(find(accountNumber).IsEmpty());
	}
};

