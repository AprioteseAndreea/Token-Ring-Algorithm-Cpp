#pragma once
#include <iostream>
#include "Computer.h"
#include <vector>
#include<string>
using namespace std;

 class Token
{
private:
	 string sourceIPAddress;
	 string destinationIPAdress;
	 string message;

	 bool arrived;
	 bool itsFree;

	 vector<Computer> history;

public:
	Token();
	void setSourceIPAddress(string sourceIPAddress);
	void setDestinationIPAddress(string destinationIPAdress);
	void setMessage(string message);
	void setArrived();
	void setNotArrived();
	void setFree();
	void setNotFree();
	void setHistory(Computer c);
	void getHistory();
	void emptyHistory();
	string getSourceIPAddress();
	string getDestinationIPAddress();
	string getMessage();
	bool getArrived();
	bool getFree();
};

