#include <iostream>
using namespace std;
#include "Process.cpp"
#include "AlgorithmData.cpp"
#include "selectionSort.cpp"

void start();
int Process ::count = 0; // count number of process & auto alocate process ID
void calculateCT(Process ps[], int n);


/* below function is heart ❤️ of the program
    which calculates complition time CT of ALL PROCESS */
void calculateCT(Process ps[], int n) {
    ps[0].CT = ps[0].BT; // for process 0 CT will always be its Burst time 
    int tiker = 0; // calculate idle time if no process arrives...
    for (int i = 1; i < n; i++) { // i started from one(2nd process) because for process 0 CT will always be its Burst time 
        check:
        if(ps[i].AT <= ps[i-1].CT || ps[i].AT <= ps[i-1].CT+tiker) {
            ps[i].CT = ps[i-1].CT + ps[i].BT + tiker;
            tiker = 0;
        }
        else {
            tiker++; // tiker ++ in case of IDLE STATE of CPU
            goto check;
        }
    }
}

void start() {
    // input process detail and start execution
    int n;
    cout << "Enter Number of Process : ";
    cin >> n;
    Process Ps[n]; // array of process or pull of process
    cout << "Enter AT and BT separate by spaces\n";
    for (int i = 0; i < n; i++) {
        cout <<"For PID " << i << " : ";
        Ps[i].getData();
    }// input process data

    sortProcessBy("AT", Ps, n); // to sort process according to arrival time
    calculateCT(Ps, n); // calculate complition time of Processes
    sortProcessBy("PID", Ps, n);
    
    
    //below is row for data output
    printf("\n\n%s %5s %5s %5s %5s %5s\n", "PID", "AT", "BT", "CT", "TAT", "WT");
    for (int i = 0; i < n; i++) {
        Ps[i].calculateInfo(); // calculates TAT, WaitingTime, etc
        Ps[i].printInfo();     // Print data  (AT,BT,CT,TAT, etc...) of processes one by one
    }
    AlgorithmData FCFS_DATA;
    // below line prints algorithm data i.e. avrage TAT , avrage waiting time 
    FCFS_DATA.printAlgoData(Ps, n);
}

int main() {
    start();
    return 0;
}