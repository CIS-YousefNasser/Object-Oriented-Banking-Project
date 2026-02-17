#pragma once
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
class clsUser:public clsPerson
{
private:
	enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
	enMode _mode;
	int _permissions;
	std::string _username;
	std::string _password;
	bool _markForDeletion = false;

	static clsUser _ConvertLinetoUserObject(std::string line, std::string Delimiter = "#//#") {
		std::vector<std::string> data;
		data = clsString::Split(line, Delimiter);
		return clsUser(enMode::updateMode, data[0], data[1], data[2], data[3], data[4], data[5], stod(data[6]));
	}
	static std::string _GetUsernameFromLine(std::string line, std::string delimiter = "#//#") {
		std::vector<std::string> data;
		data = clsString::Split(line, delimiter);
		return data[4];
	}

	static std::string _ConvertUserObjectToDataLine(clsUser& client, std::string delimiter = "#//#") {
		std::string line;
		line += client.firstName + delimiter;
		line += client.lastName + delimiter;
		line += client.email + delimiter;
		line += client.phoneNumber + delimiter;
		line += client._username+ delimiter;
		line += client.password + delimiter;
		line += std::to_string(client.permissions);
		return line;

	}
	void _AddNewUserLineToFile(const std::string& line) {
		std::ofstream file;
		file.open("Users.txt", std::ios::app);
		if (file.is_open()) {
			file << line << std::endl;
		}
		file.close();
	}
	static std::vector<clsUser> _LoadUserDataFromFile() {
		std::vector<clsUser>usersData;
		std::ifstream file;
		std::string line;
		file.open("Users.txt", std::ios::in);
		if (file.is_open()) {
			while (std::getline(file, line)) {
				usersData.push_back(_ConvertLinetoUserObject(line));
			}
		}
		file.close();
		return usersData;
	}
	static void _SaveUsersDataToFile(std::vector<clsUser>& usersData) {
		std::ofstream file;
		std::string line;
		file.open("Users.txt", std::ios::out);
		if (file.is_open()) {
			for (clsUser& user : usersData) {
				if (user._markForDeletion) {
					continue;
				}
				file << _ConvertUserObjectToDataLine(user) << std::endl;
			}
		}
		file.close();
	}
	void _Update() {
		std::vector<clsUser>usersData = _LoadUserDataFromFile();
		for (clsUser& user : usersData) {
			if (user.GetUsername() == this->GetUsername()) {
				user = *this;
			}
		}
		_SaveUsersDataToFile(usersData);
	}
	void _AddUser() {
		_AddNewUserLineToFile(_ConvertUserObjectToDataLine(*this));
	}
public:
	clsUser(enMode mode, std::string firstName, std::string lastName, std::string email,
		std::string phoneNumber, std::string username,std::string password, int permissons)
		:clsPerson(firstName, lastName, email, phoneNumber) {
		_mode = mode;
		_username = username;
		_permissions = permissons;
		_password = password;
	}
	void SetUsername(std::string username) {
		_username = username;
	}
	std::string GetUsername() {
		return _username;
	}
	void SetPassword(std::string password) {
		_password = password;
	}
	std::string GetPassword() {
		return _password;
	}
	void SetPermissions(int permissions) {
		_permissions = permissions;
	}
	int GetPermissions() {
		return _permissions;
	}

	__declspec(property(put = SetUsername, get = GetUsername))std::string username;
	__declspec(property(put = SetPassword, get = GetPassword))std::string password;
	__declspec(property(put = SetPermissions, get = GetPermissions))int permissions;
	static clsUser GetEmptyUser() {
		return clsUser(enMode::emptyMode,"","","", "", "", "",0);
	}
	bool IsEmpty() {
		return _mode == enMode::emptyMode;
	}
	static clsUser Find(std::string username) {
		std::ifstream file;
		std::string line;
		std::string userUsername;
		file.open("Users.txt", std::ios::in);
		if (file.is_open()) {
			while (std::getline(file, line)) {
				userUsername = _GetUsernameFromLine(line);
				if (userUsername == username) {
					clsUser user = _ConvertLinetoUserObject(line);
					file.close();
					return user;
				}

			}
		}
		file.close();
		return GetEmptyUser();
	}
	static clsUser Find(std::string username, std::string password) {
		clsUser user = Find(username);
		if (!(user.IsEmpty()) && user._password == password)
			return user;
		return GetEmptyUser();
	}
	static bool IsUserExist(std::string username) {
		return !(Find(username).IsEmpty());
	}
	static clsUser GetNewUser(std::string username) {
		return clsUser(clsUser::addNewMode, "", "", "", "", username, "", 0);
	}
	enum enSaveUser { svFailedEmptyObject = 0, svSuccesseded = 1, svFailedUsernameExist = 2 };
	enSaveUser Save() {
		switch (_mode) {
		case enMode::emptyMode:
			if (IsEmpty())
				return enSaveUser::svFailedEmptyObject;

		case enMode::updateMode:
			_Update();
			return enSaveUser::svSuccesseded;
		case enMode::addNewMode:
			if (IsUserExist(this->_username)) {
				return enSaveUser::svFailedUsernameExist;
			}
			else {
				_AddUser();
				_mode = enMode::updateMode;
				return enSaveUser::svSuccesseded;
			}
		default:
			return enSaveUser::svFailedEmptyObject;
		}
	}
	bool Delete() {
		if (!IsUserExist(this->GetUsername())) {
			return false;
		}
		std::vector<clsUser> usersData = _LoadUserDataFromFile();
		for (clsUser& user : usersData) {
			if (this->GetUsername() == user.GetUsername()) {
				user._markForDeletion = true;
				*this = GetEmptyUser();
			}
		}
		_SaveUsersDataToFile(usersData);
		return true;
	}
	static std::vector<clsUser> GetUsersData() {
		return _LoadUserDataFromFile();
	}
	bool IsAllowedAccess(int permissions) {
		if ((this->_permissions & permissions) == permissions)
			return true;
		return false;
	}
};

