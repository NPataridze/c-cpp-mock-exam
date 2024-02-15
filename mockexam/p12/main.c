#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct river{
    char name[40];
    int length;
    int drainage_area;
};

int compare(const void *a, const void *b){
    const struct river* river1 = (const struct river*)a;
    const struct river* river2 = (const struct river*)b;
    return(river1->length - river2->length);
}

int main(){
    FILE* input = fopen("data.txt", "r");
    if(input == NULL){
        return 1;
    }

    struct river rivers[30];
    int num_rivers = 0;

    while(fscanf(input, "%s %d %d", rivers[num_rivers].name, &rivers[num_rivers].length, &rivers[num_rivers].drainage_area) == 3){
        num_rivers++;
    }

    fclose(input);

    qsort(rivers, num_rivers, sizeof(struct river), compare);

    FILE* output = fopen("output.txt", "w");
    if(output == NULL){
        return 1;
    }

    for(int i = 0; i < num_rivers; i++){
        fprintf(output, "%s %d %d\n", rivers[i].name, rivers[i].length, rivers[i].drainage_area);
    }

    fclose(output);

    printf("check out file 'output.txt'\n");

    return 0;

}