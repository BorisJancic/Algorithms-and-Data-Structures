#include "HashTable.hpp"
#include "OpenProcess.hpp"

#ifndef OPENADDRESSING
#define OPENADDRESSING

class OpenAddressing: public HashTable {
    private:
        OpenProcess** table;
    public:
        OpenAddressing(unsigned N, unsigned P);
        ~OpenAddressing();

        void Insert(unsigned PID) override;
        void Search(unsigned PID) override;
        void Write(unsigned PID, unsigned ADDR, int x) override;
        void Read(unsigned PID, unsigned ADDR) override;
        void Delete(unsigned PID) override;
        void Print(unsigned m) override;
};

#endif // OPENADDRESSING