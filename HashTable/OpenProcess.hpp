#ifndef OPENPROCESS
#define OPENPROCESS

class OpenProcess {
    private:
        unsigned PID;
        unsigned address;
    public:
        OpenProcess(unsigned PID, unsigned address);
        ~OpenProcess();

        void set_PID(unsigned PID);
        void set_address(unsigned address);

        unsigned get_PID();
        unsigned get_address();
};

#endif // OPENPROCESS