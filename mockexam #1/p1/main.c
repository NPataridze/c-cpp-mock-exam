#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    
    for(int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for(int j = 1; j <= i; j++)
        {
            printf("%c", ch++);
        }
        printf("\n");
    }



   /* int row;
    for(row = 1; row <= n; row++){
        for(int j = 1; j <= row; j++){
            printf("%c", 'A' + j - 1);
        }
        printf("\n");
    }*/
    return 0;
}