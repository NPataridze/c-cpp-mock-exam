#include <stdio.h>

int main(){
    FILE* file = fopen("generate.txt", "wb");

    if(file == NULL){
        return 1;
    }

    for(char letter = 'a'; letter <= 'j'; letter++)
    {
        fprintf(file, "%c %c%c\n", letter, letter, letter);
    }

    fclose(file);
    

    return 0;
}