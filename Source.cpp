#include <iostream>
#include <vector>
#include "Computer.h"
#include<fstream>
#include "Token.h"
using namespace std;

void readComputers(vector<Computer>& myComputers) {
	int numberOfComputers;

	cout << "Cate calculatore are reteaua? ";
	cin >> numberOfComputers;

	ifstream fin("Text.txt");
	for (int i = 0; i < numberOfComputers; i++) {
		string ipAddress;
		fin >> ipAddress;

		Computer currentComputer(ipAddress);
		myComputers.push_back(currentComputer);

	}
	
}
void transmitereMesaj(int pc1, int pc2, vector<Computer> myComputers) {
	string message;
	cout << "Introduceti mesajul: ";
	cin >> message;
	Token jeton;

	jeton.setSourceIPAddress(myComputers.at(pc1).getIPAddress());
	jeton.setDestinationIPAddress(myComputers.at(pc2).getIPAddress());
	jeton.setMessage(message);
	jeton.setNotArrived();
	jeton.setNotFree();
	for (int i = pc1; i < myComputers.size(); i++) {
		cout << "Calculatorul nr  : " <<i<< endl;
		if (!myComputers.at(i).getIPAddress()._Equal(jeton.getDestinationIPAddress())) {
			jeton.setHistory(myComputers.at(i));
			cout << "Am adaugat la istoric calc: " << i << endl;
			jeton.getHistory();

		}
		else {
			jeton.setArrived();

			cout << "Am ajuns la destinatie, iata mesajul: ";
			cout << jeton.getMessage() << endl;

			jeton.setHistory(myComputers.at(i));
			cout << "Am adaugat la istoric calc: " << i << endl;
			jeton.getHistory();

			jeton.setFree();

		}
		if (i == myComputers.size() - 1) {
			for (int j = 0; j < pc1; j++) {
				cout << "Calculatorul nr : " << j<<endl;

				if (!myComputers.at(j).getIPAddress()._Equal(jeton.getDestinationIPAddress())) {
					jeton.setHistory(myComputers.at(j));
					cout << "Am adaugat la istoric calc: " << j << endl;
					jeton.getHistory();
					jeton.setFree();


				}
				else {
					jeton.setArrived();

					cout << "Am ajuns la destinatie, iata mesajul: ";
					cout << jeton.getMessage() << endl;

					jeton.setHistory(myComputers.at(j));
					cout << "Am adaugat la istoric calc: " << j << endl;
					jeton.getHistory();
					jeton.setFree();
				}
			}
		}
		
		

	}
	
}

int main() {
	vector<Computer> myComputers;
	readComputers(myComputers);
	char ch;
	do
	{
		int pc1, pc2;
		cout << "Introduceti numarul calculatorului sursa: ";
		cin >> pc1;
		cout << "Introduceti numarul calculatorului destinatie: ";
		cin >> pc2;
		transmitereMesaj(pc1, pc2, myComputers);

		cout << "\nVreti sa mai trimiteti un alt mesaj? (tasteaza y sau n) \n";

		cin >> ch;
	} while (ch == 'Y' || ch == 'y');


	return 0;
}