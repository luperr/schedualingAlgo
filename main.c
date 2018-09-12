#include <stdio.h>

void fcfs(){

}

void srt(){

}

void rr2(){

}

void rr4(){

}

void avgWait(){

}

void avgTurnaround(){

}

int main(int argc, char *argv[]){
    FILE *process = fopen(argv[0], "r");

    
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