#pragma once
#include <windows.h>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainMenuScreen.h"
class clsLogin:protected clsScreen
{
private:

	static void _ReadUserData(std::string &username,std::string &password) {
		username=clsInputValidate::AskForInput("Please Enter Username:");
		password = clsInputValidate::AskForInput("Please Enter password:");
	}
	static void _LoginHeader() {
		clsScreen::DrawScreen("Login");
	}
	static void _WelcomeScreen() {
		clsScreen::DrawScreen("Welcome!");

	}
	static void _InvalidScreen() {
		clsScreen::DrawScreen("Invalid!");

	}
	static void _WaitAndClear() {
		Sleep(1000);
		system("cls");
	}
public:

	static void LoginScreen() {
		bool loginFailed = false;
		std::string username;
		std::string password;
		do {
			
			if (loginFailed) {
				system("cls");
				_InvalidScreen();
				_WaitAndClear();
			}
			// for testing purposes only. 
			std::cout << "Admin username:Admin,password:1234" << std::endl;
			// In production, these should be hashed and hidden.
			_LoginHeader();
			_ReadUserData(username,password);
			
			if ((currentUser=clsUser::Find(username, password)).IsEmpty()) {
				loginFailed = true;
			}
			else
			{
				loginFailed = false;
			}
			
			
		} while (loginFailed);
		 system("cls");
		_WelcomeScreen();
		_WaitAndClear();
		clsMainMenuScreen::MainMenuScreen();
	}
};

