#include "Computer.h"
Computer::Computer() {
	IPAddress = nullptr;
}
Computer::Computer(string IPAddress) {
	this->IPAddress = IPAddress;
}
void Computer::setIPAddress(string IPAddress) {
	this->IPAddress = IPAddress;
}
string Computer::getIPAddress() {
	return this->IPAddress;

}