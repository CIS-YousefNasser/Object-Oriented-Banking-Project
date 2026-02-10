#pragma once
#include <string>
class clsPerson
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _email;
	std::string _phoneNumber;
public:
	clsPerson(std::string firstName, std::string lastName, std::string email, std::string phoneNumber) {
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phoneNumber = phoneNumber;
	}
	void SetFirstName(std::string firstName) {
		_firstName = firstName;
	}
	void SetLastName(std::string lastName) {
		_lastName = lastName;

	}
	void SetEmailName(std::string email) {
		_email = email;

	}
	void SetPhoneNumber(std::string phoneNumber) {
		_phoneNumber = phoneNumber;
	}
	std::string GetFirstName() {
		return _firstName;
	}
	std::string GetLastName() {
		return _lastName;
	}
	std::string GetEmail() {
		return _email;
	}
	std::string GetPhoneNumber() {
		return _phoneNumber;
	}
	std::string GetFullName() {
		return _firstName + " " + _lastName;
	}
	__declspec(property(put = SetFirstName, get = GetFirstName))std::string firstName;
	__declspec(property(put = SetLastName, get = GetLastName))std::string lastName;
	__declspec(property(put = SetEmail, get = GetEmail))std::string email;
	__declspec(property(put = SetPhoneNumber, get = GetPhoneNumber))std::string phoneNumber;
};

