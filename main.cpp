#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
void ReadClientInfo(clsBankClient &client) {
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

void UpdateClientInfo() {
	std::string accountNumber;
	while (!(clsBankClient::IsClientExist(accountNumber=clsInputValidate::AskForInput("Enter Account Number:")) ) ) {
		std::cout << "Please Enter a valid Account Number" << std::endl;
	}
	clsBankClient client=clsBankClient::find(accountNumber);
	ReadClientInfo(client);
	switch (client.save()) {
	case clsBankClient::enSaveClient::svSuccesseded:
		std::cout << "Account Updated Successfully"<<std::endl;
		break;
	case clsBankClient::enSaveClient::svFailedEmptyObject:
	default:
		std::cout << "Account Update Failed";
	}
}
void AddNewClient() {
	std::string accountNumber;
	while ( clsBankClient::IsClientExist(accountNumber = clsInputValidate::AskForInput("Enter Account Number:")) ) {
		std::cout << "Account Number Already Exists" << std::endl;
	}
	clsBankClient client = clsBankClient::GetNewClient(accountNumber);
	ReadClientInfo(client);
	switch (client.save()) {
	case clsBankClient::enSaveClient::svSuccesseded:
		std::cout << "Account Added Successfully" << std::endl;
		break;
	case clsBankClient::enSaveClient::svFailedEmptyObject:
		std::cout << "Account Add Attempt Failed" << std::endl;
		break;
	case clsBankClient::enSaveClient::svFailedAccountNumberExist:
			std::cout <<"Account With This Number Already Exists "<<std::endl;
			break;
	default:
		std::cout << "Account Add Attempt Failed"<<std::endl;

	}
}
void DeleteClient() {
	std::string accountNumber;

	while (!(clsBankClient::IsClientExist(accountNumber = clsInputValidate::AskForInput("Enter Account Number:")))) {
		std::cout << "Please Enter a valid Account Number" << std::endl;
	}
	clsBankClient client = clsBankClient::find(accountNumber);
	client.Print();
	if (std::tolower(clsInputValidate::ReadChar("Do you want to delete this account (y/n):")) == 'y') {
		client.Delete();
		client.Print();
	}
	else
	std::cout << "Deletion Cancelled" << std::endl;
}
int main() {
	//testing
	DeleteClient();
	//changes in clsInputValidate.h-main.cpp-clsBankClient.h
}
