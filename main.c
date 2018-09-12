#include <stdio.h>

void fcfs(){
/*
 Takes in the number of process and the proccess info: then using
 the first come first serve method prints out each step of the process execution
 */
}

void srt(){
/*
input: number of process, process info array
do sortest remaining time maaaaaan
*/
}

void rr2(){
/*
input: number of process, process info array
round robin with a process time of 2
*/
}

void rr4(){
/*
input: number of process, process info array
round robin with a time for 4
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
    FILE *process = fopen(argv[0], "r");

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