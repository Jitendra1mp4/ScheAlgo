class AlgorithmData {
    float avrageTAT,
    avrageWaitingTime,
    avrageResponseTime;

    float calAvrageTAT(Process plist[], int n) {
        float total = 0;
        for(int i = 0; i < n; i++) {
            total += plist[i].TAT;
        }
        avrageTAT = total/n;
        return avrageTAT;

    }
    float calAvrageWaitingTime(Process plist[], int n) {
        float total = 0;
        for(int i = 0; i < n; i++) {
            total += plist[i].WaitingTime;
        }
        avrageWaitingTime = total/n;
        return avrageWaitingTime;
    }
    public:
    void printAlgoData(Process ps[], int n) {
        cout <<"\naverage turn around time: "<< calAvrageTAT(ps, n) << endl;
        cout <<"avarage waiting time : "<< calAvrageWaitingTime(ps, n) <<endl << endl;
    }

    void getGanttChart() {}
};
