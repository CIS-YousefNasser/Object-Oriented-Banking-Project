#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsDate.h"
#include "clsPeriod.h"
class clsInputValidate
{
public:
	static bool IsNumberBetween(int number, int from, int to) {
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(double number, double from, double to) {
		return (number >= from && number <= to);
	}
	static bool IsNumberBetween(float number, float from, float to) {
		return (number >= from && number <= to);
	}
	static bool IsDateBetween(const clsDate& date, clsDate startDate, clsDate endDate) {
		if (clsDate::IsDate1AfterDate2(startDate, endDate))
			clsDate::SwapDates(startDate, endDate);
		return !(clsDate::IsDate1BeforeDate2(date, startDate) || clsDate::IsDate1AfterDate2(date, endDate));
	}
	static bool IsValidDate(clsDate date) {
		return (date.year > 0 && (date.month <= 12 && date.month > 0) && (date.day > 0 && date.day <= clsDate::NumberOfDaysInAMonth(date.year, date.month)));
	}

	static int ValidateIntNumber(string errorMessage, string message = "") {
		int x;
		std::cout << message;
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
		}
		return x;
	}
	static double ValidateDoubleNumber(string errorMessage,string message="") {
		double x;
		std::cout << message;
		while (!(cin >> x)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << errorMessage << endl;
		}
		return x;
	}
	static int ReadNumberBetween(int from, int to, string message) {
		int input = ValidateIntNumber("Error:Please enter a valid number");

		while (input > to || input < from) {
			std::cout << message;
			input = ValidateIntNumber("Error:Please enter a valid number");
		}
		return input;
	}
	static std::string ReadString() {
		std::string input;
		getline(std::cin >> ws, input);
		return input;
	}
	static std::string AskForInput(std::string message) {
		std::cout << message;
		return ReadString();
	}
	static double ReadPostiveDouble(std::string message) {
		double number;
		while ((number = ValidateDoubleNumber("Please Enter A Number:",message)) < 0) {
			std::cout << "Please Enter a postive Number" << std::endl;
		}
		return number;
	}
	static int ReadPostiveInt(std::string message) {
		int number;
		while ((number = ValidateIntNumber("Please Enter A Number:", message)) < 0) {
			std::cout << "Please Enter a postive Number" << std::endl;
		}
		return number;
	}
	static char ReadChar(std::string message) {
		char input;
		std::cout << message;
		cin >> input;
		return input;
	}
};

