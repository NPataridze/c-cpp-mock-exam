#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("allocation failure");
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    FILE* output = fopen("squares.txt", "w");
    if(output == NULL){
        printf("file didn't open\n");
        free(arr);
        return 1;
    }

    for(int i = n - 1; i >= 0; i--){
        fprintf(output, "%d  %d\n", arr[i], arr[i] * arr[i]);
    }

    fclose(output);
    free(arr);

    return 0;

}