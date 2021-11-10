void sortProcessBy(string sortBy, Process arr[], int n) {
    // Sort processes according to arrival time
    // or Pid using selection sort
    int sB = 1; // one for arrival time
    if(sortBy == "PID") sB = 0; //zero  for PID

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++) {
            //selecting smallest element
            if(sB) {
                if (arr[j].AT < arr[minIndex].AT) {
                    minIndex = j;
                }

            }else {
                if (arr[j].PID < arr[minIndex].PID) {
                    minIndex = j;
                }
            }
        }
        Process temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
