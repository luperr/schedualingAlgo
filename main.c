#include <stdio.h>
#include <stdlib.h>

struct process{
    int id;
    int arrival;
    int cycles;
    int cyclesWaiting;
    int turnaround;
    // active?
};

void fcfs(struct process *processQue, int processes){
    int time = 1;
    int compare(const void *a, const void *b){
        struct process *ia = (struct process *)a;
        struct process *ib = (struct process *)b;
        int same = (ia -> arrival - ib -> arrival);
        if (same = 0)
            return (ia -> id - ib -> id);
        else
            same;
    }

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

void rr(){
/*
input: number of process, process info array and a quanta 2 or 4
round robin with a process time of 2
*/
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

    fcfs(processQue, processes);

    fclose(processFile);
    return 0;
}