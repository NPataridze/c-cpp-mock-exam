#include <stdio.h>

void total_time(int mins[], int secs[], int n, int *sum_mins, int *sum_secs){
    int total_secs = 0;

    for(int i = 0; i < n; i++){
        total_secs += mins[i] * 60 + secs[i];
    }
    *sum_mins = total_secs / 60;
    *sum_secs = total_secs % 60; 
}

int main(){
    int mins[] = {3, 4, 2};
    int secs[] = {20, 35, 45};

    int n = sizeof(mins) / sizeof(mins[0]);

    int sum_mins;
    int sum_secs;

    total_time(mins, secs, n, &sum_mins, &sum_secs);

    printf("total time mins: %d secs: %d \n", sum_mins, sum_secs);

    return 0;
}