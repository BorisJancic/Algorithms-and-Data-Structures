#ifndef HASHTABLE
#define HASHTABLE

class HashTable {
    protected:
        int* memory;
        unsigned page_size;
        unsigned table_size;
        unsigned current_size;
        
        unsigned hash(unsigned k, unsigned i);

    public:
        HashTable(unsigned N, unsigned P);
        virtual ~HashTable();

        virtual void Insert(unsigned PID) = 0;
        virtual void Search(unsigned PID) = 0;
        virtual void Write(unsigned PID, unsigned ADDR, int x) = 0;
        virtual void Read(unsigned PID, unsigned ADDR) = 0;
        virtual void Delete(unsigned PID) = 0;
        virtual void Print(unsigned m) = 0;
};

#endif // HASHTABLE