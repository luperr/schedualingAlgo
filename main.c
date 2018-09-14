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

void fcfs(struct process *processQue){
/*
 Takes in the number of process and the proccess info: then using
 the first come first serve method prints out each step of the process execution

 make a que of structs arraganged by lowest arrival time if 2 have the same arrival time lowest PID first 

the execute in that order.
while process[0].cycles > 0
    process1.cycles -= 1


print out:
*/


    for(int i = 0; i < 3; i++){
        printf("%d\n", processQue[i].id);
    }

    printf("FCFS\n");
    printf("time\tPID\n");
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
                for(int a = 0; a < processes; a++){
                    processQue[i].id = id;
                    processQue[i].arrival = arrival;
                    processQue[i].cycles = cycles;
                    processQue[i].turnaround = 0;
                    processQue[i].cyclesWaiting = 0;
            }
        }
    }

    fcfs(processQue);

    fclose(processFile);
    return 0;
}