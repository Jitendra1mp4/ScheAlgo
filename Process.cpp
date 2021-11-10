class Process {
    // class that contains all info about a Process
    public:
    int PID,
    // Process Id
    AT,
    // arrival time
    BT,
    // Burst time
    CT,
    //complition time
    TAT,
    // turn around time
    WaitingTime,
    ResponseTime;  // it isn't computed for FCFS algo
    static int count ; // automatically increases for each process
    Process() { // constructor
        CT = 0; //iinitially CT of each process will be zero
    }
    void getData() {
        // input AT  & BT ;
        cin >> AT >> BT;
        PID = count; // automatically give a PId to each Process
        count++;

    }
    void calculateInfo() {
        // calculate TAT and waiting time
        TAT = CT - AT;
        WaitingTime = TAT - BT;
    }
    void printInfo() {
        //  print all info about a Process
        printf(" %-5d %-5d %-5d %-5d %-5d %-5d\n",
            PID, AT, BT, CT, TAT, WaitingTime);
    }
};