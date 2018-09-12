#include <stdio.h>

struct process{
    int id;
    int arrival;
    int cycles;
    int cyclesWaiting;
    int turnaround;
    // active?
};

//still not sold on this one
struct output{
    char algo[5];
};

void fcfs(){
/*
 Takes in the number of process and the proccess info: then using
 the first come first serve method prints out each step of the process execution

 make a que of structs arraganged by lowest arrival time if 2 have the same arrival time lowest PID first 

the execute in that order.
while process[0].cycles > 0
    process1.cycles -= 1


print out:
*/
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

int main(int argc, char *argv[]){
    FILE *process = fopen(argv[1], "r");
    //input argumejnts need to be handled
    if(argc > 1){
        printf("please only enter one comand line arguement");

    }
    ///turn each line of the file into an struct
    //for all line except the first make a sruct

    //Probably change to a struct
    printf("FCFS\n");
    printf("time\tPID\n");
    //fcfs();
    printf("SRT\n");
    printf("time\tPID\n");
    //srt();
    printf("RR(2)\n");
    printf("time\tPID\n");
    //rr2();
    printf("RR(4)\n");
    printf("time\tPID\n");
    //rr4();

    fclose(process);

    return 0;
}