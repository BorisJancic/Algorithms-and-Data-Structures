#include "ChainProcess.hpp"

ChainProcess::ChainProcess(unsigned PID, unsigned address) {
    set_PID(PID);
    set_address(address);
    set_next(nullptr);
}
ChainProcess::ChainProcess(unsigned PID, unsigned address, ChainProcess* next) {
    set_PID(PID);
    set_address(address);
    set_next(next);
}

ChainProcess::~ChainProcess() {}

void ChainProcess::set_PID(unsigned PID) { this->PID = PID; }
void ChainProcess::set_address(unsigned address) { this->address = address; }
void ChainProcess::set_next(ChainProcess* next) { this->next = next; }

unsigned ChainProcess::get_PID() { return PID; }
unsigned ChainProcess::get_address() { return address; }
ChainProcess* ChainProcess::get_next() { return next; }