#pragma once
#include <iostream>
using namespace std;
class Computer
{
private:
	string IPAddress;
public:
	Computer();
	Computer(string IPAddress);
	void setIPAddress(string IPAddress);
	string getIPAddress();
	
};

