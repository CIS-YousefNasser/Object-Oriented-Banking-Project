#pragma once
#include <iostream>
class clsScreen
{
public:
	static void DrawScreen(std::string title,std::string subtitle="") {
		std::cout << "\t\t\t\t    ___________________________________________\n" << std::endl;
		std::cout << "\t\t\t\t\t\t     " << title << std::endl;
		if (subtitle != "") {
			std::cout << "\t\t\t\t\t\t " << subtitle << std::endl;
		}
		std::cout << "\t\t\t\t    ___________________________________________\n" << std::endl;
	}
};

