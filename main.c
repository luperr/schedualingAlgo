#include <stdio.h>
#include <stdlib.h>

struct process{
    int id;
    int arrival;
    int cycles;
    int cyclesWaiting;
    int turnaround;
};

int compare(const void *a, const void *b){
    struct process *ia = (struct process *)a;
    struct process *ib = (struct process *)b;
    int same = (ia -> arrival - ib -> arrival);
        if (same = 0)
            return (ia -> id - ib -> id);
        else
            same;
}

void fcfs(struct process *processQue, int processes){
    int time = 0;
  
    qsort(processQue, processes, sizeof(struct process), compare);

    printf("FCFS\n");
    printf("time\tPID\n");
    for(int i = 0; i < processes ; i++){
        int jcycles = processQue[i].cycles;
        for(int a = 0; a < jcycles; a ++){
            printf("%d\t%d\n", time, processQue[i].id);
            processQue[i].cycles -= 1;
            time++;
        }
    }
}

void srt(){
/*
input: number of process, process info array
do sortest remaining time maaaaaan
*/
}

struct process checkForNewProcess(int processes, struct process *processQue, struct process *activeQue, int time){
    for(int i = 0; i < processes; i++){
        if(processQue[i].arrival == time){
            for(int j = 0; j < processes; j++)
            if(activeQue[j].id == 0){
                activeQue[j] = processQue[i];
                break;
            }  
        }
    }
    return *activeQue;
}

void rr(struct process *processQue, int processes, int quantum){\
    int time = 0;

    qsort(processQue, processes, sizeof(struct process), compare);

    struct process activeQue[processes];
    for(int i = 0; i < processes; i++){
        activeQue[i].id = 0;
    }

    //append to active que
    //make a call to this at the end of every a process ends or quantom is up...

    printf("RR(%d)\n", quantum);
    printf("time\tPID\n");
    *activeQue = checkForNewProcess(processes, processQue, activeQue, time);
   
   int a = 20;
    while(a > 0){
        for(int i = 0; i < quantum; i++){
            printf("%d\t%d\n",time, activeQue[0].id);
            time++;
            activeQue[0].cycles -= 1;
            if(activeQue[0].cycles <= 0){
                break;
            }
        }
        struct process temp = activeQue[0];
        for(int i = 0; i < (processes - 1); i++){
            activeQue[i] = activeQue[i+1];
        }
        activeQue[processes] = temp;
        *activeQue = checkForNewProcess(processes, processQue, activeQue, time);
        a--;
    }
}



void avgWait(){
    /*
    calulates the average wait time of all the process
    */
}

void avgTurnaround(){
/*
    calculates the average turn around time for each process
*/
}

void remove_newline(char string[], int length) {
    for (int i = 0; i < length; i++) {
        if (string[i] == '\n') {
            string[i] = '\0';
            return;
        }
    }
}

int main(int argc, char *argv[]){
    FILE *processFile = fopen(argv[1], "r");
    int processes, id, arrival, cycles;

    //Make sure only One command line argument is entered
    if(argc > 2){
        printf("please only enter one comand line arguement\n");
        exit(0);
    }

    if(processFile){
        fscanf(processFile, "%d", &processes);
    }

    struct process processQue[processes];

    if(processFile){
        char buffer[50];
        fgets(buffer, 50, processFile);
        for(int i = 0; i < processes; i++){
            fscanf(processFile, "%d %*c %d %*c %d", &id, &arrival, &cycles);
            //add in error handling
                for(int a = 0; a < processes; a++){
                    processQue[i].id = id;
                    processQue[i].arrival = arrival;
                    processQue[i].cycles = cycles;
                    processQue[i].turnaround = 0;
                    processQue[i].cyclesWaiting = 0;
            }
        }
    }

    //fcfs(processQue, processes);

    rr(processQue, processes, 2);
    //rr(processQue, processes, 4);

    fclose(processFile);
    return 0;
}