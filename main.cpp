#include <iostream>
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
int main() {
	std::cout << clsBankClient::IsClientExist("A121");
}