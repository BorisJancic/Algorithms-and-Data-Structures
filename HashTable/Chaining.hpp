#include "HashTable.hpp"
#include "ChainProcess.hpp"

#ifndef CHAINING
#define CHAINING

class Chaining: public HashTable {
    private:
        ChainProcess** table;
        bool* memory_free;
    public:
        Chaining(unsigned N, unsigned P);
        ~Chaining();

        void Insert(unsigned PID) override;
        void Search(unsigned PID) override;
        void Write(unsigned PID, unsigned ADDR, int x) override;
        void Read(unsigned PID, unsigned ADDR) override;
        void Delete(unsigned PID) override;
        void Print(unsigned m) override;
};

#endif // CHAINING