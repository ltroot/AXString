#include "AXString.hpp"
#include <iostream>

int main()
{
	axian::AXString<char> str("hellooooo");
	str.append(" ").append("KerKer");
	std::cout << str << std::endl;

	return 0;
}
