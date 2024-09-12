#ifndef CHAINPROCESS
#define CHAINPROCESS

class ChainProcess {
    private:
        unsigned PID;
        unsigned address;
        ChainProcess* next;
    public:
        ChainProcess(unsigned PID, unsigned address);
        ChainProcess(unsigned PID, unsigned address, ChainProcess* next);
        ~ChainProcess();

        void set_PID(unsigned PID);
        void set_address(unsigned address);
        void set_next(ChainProcess* next);

        unsigned get_PID();
        unsigned get_address();
        ChainProcess* get_next();
};

#endif //CHAINPROCESS
