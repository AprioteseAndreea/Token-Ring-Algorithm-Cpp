#include "Token.h"
Token::Token() {
	sourceIPAddress = "";
	destinationIPAdress = "";
	message = "";
	arrived = false;
	itsFree = true;
}
void Token::setSourceIPAddress(string sourceIPAddress) {
	this->sourceIPAddress = sourceIPAddress;
}
void Token::setDestinationIPAddress(string destinationIPAdress) {
	this->destinationIPAdress = destinationIPAdress;
}
void Token::setMessage(string message) {
	this->message = message;
}
void Token::setArrived() {
	this->arrived = true;
}
void Token::setNotArrived() {
	this->arrived = false;
}
void Token::setFree()
{
	itsFree = true;
}
void Token::setNotFree()
{
	this->itsFree = false;
}
void Token::setHistory(Computer c) {
	this->history.push_back(c);
}
void Token::getHistory()
{
	for (Computer c : history) {
		cout << c.getIPAddress() << endl;
	}
}
void Token::emptyHistory()
{
	history.clear();
}
string Token::getSourceIPAddress() {
	return this->sourceIPAddress;
}
string Token::getDestinationIPAddress() {
	return this->destinationIPAdress;
}
string Token::getMessage() {
	return this->message;
}
bool Token::getArrived() {
	return this->arrived;
}
bool Token::getFree() {
	return this->itsFree;
}