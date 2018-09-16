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

int compareCycle(const void *a, const void *b){
    struct process *ia = (struct process *)a;
    struct process *ib = (struct process *)b;
    int same = (ia -> cycles - ib -> cycles);
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

void srt(struct process *processQue, int processes){
    int time = 0;
    int sum = 0;
    int n = 0;
    qsort(processQue, processes, sizeof(struct process), compare);
    for(int i=0; i < processes; i++){
        sum += processQue[i].cycles;
    }

    printf("SRT\n");
    printf("time\tPID\n");
    while(sum > 0){
        for(int i = 0; i < processes; i++){
            if(processQue[i].arrival == time && time > 1){
                qsort(processQue, processes, sizeof(struct process), compareCycle);
            }
        }
        printf("%d\t%d\n", time, processQue[n].id);
        processQue[n].cycles -= 1;
        if (processQue[n].cycles == 0){
            n++;
        }
        if(n > 4)
            n = 0;
        else if(n > 4 && processQue[n].cycles == 0){
            break;
        }
        time++;
        sum--;
    }
}

void rr(struct process *processQue, int processes, int quantum){\
    int time = 0;
    int active = 0;
    int sum = 0;
    qsort(processQue, processes, sizeof(struct process), compare);
    
    for(int i=0; i < processes; i++){
        sum += processQue[i].cycles;
    }
    printf("RR(%d)\n", quantum);
    printf("time\tPID\n");
    while(sum > 0){
        if(processQue[active].arrival <= time && processQue[active].cycles != 0){
            printf("%d\t%d\n",time, processQue[active].id);
            for(int j=0; j < quantum; j++){
                processQue[active].cycles -= 1;
            }
        }
        active += 1;
        if(active > (processes - 1))
            active = 0;  

         time++;     
        sum -= 1;
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

    struct process pfcfs[processes];
    struct process psrt[processes];
    struct process prr2[processes];
    struct process prr4[processes];

    for(int i = 0; i < processes; i++){
        pfcfs[i].id = processQue[i].id;
        psrt[i].id = processQue[i].id;
        prr2[i].id = processQue[i].id;
        prr4[i].id = processQue[i].id;
        pfcfs[i].arrival = processQue[i].arrival;
        psrt[i].arrival = processQue[i].arrival;
        prr2[i].arrival = processQue[i].arrival;
        prr4[i].arrival = processQue[i].arrival;
        pfcfs[i].cycles = processQue[i].cycles;
        psrt[i].cycles = processQue[i].cycles;
        prr2[i].cycles = processQue[i].cycles;
        prr4[i].cycles = processQue[i].cycles;
        pfcfs[i].turnaround = processQue[i].turnaround;
        psrt[i].turnaround = processQue[i].turnaround;
        prr2[i].turnaround = processQue[i].turnaround;
        prr4[i].turnaround = processQue[i].turnaround;
        pfcfs[i].cyclesWaiting = processQue[i].cyclesWaiting;
        psrt[i].cyclesWaiting = processQue[i].cyclesWaiting;
        prr2[i].cyclesWaiting = processQue[i].cyclesWaiting;
        prr4[i].cyclesWaiting = processQue[i].cyclesWaiting;
    }

    //need to fix 
    fcfs(pfcfs, processes);
    printf("\n\n");
    srt(psrt, processes);
    printf("\n\n");
    rr(prr2, processes, 2);
    printf("\n\n");
    rr(prr4, processes, 4);

    fclose(processFile);
    return 0;
}