#include "OpenProcess.hpp"

OpenProcess::OpenProcess(unsigned PID, unsigned address) {
    set_PID(PID);
    set_address(address);
}
OpenProcess::~OpenProcess() { }

void OpenProcess::set_PID(unsigned PID) { this->PID = PID; }
void OpenProcess::set_address(unsigned address) { this->address = address; }

unsigned OpenProcess::get_PID() { return PID; }
unsigned OpenProcess::get_address() { return address; }
