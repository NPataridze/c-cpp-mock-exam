#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool valid_password(const char* pass){
    int length = 0;
    int digit_count = 0;
    int letter_count = 0;
    int uppercase_count = 0;

    for(int i = 0; pass[i] != '\0'; i++){
        length++;
        if(isdigit(pass[i])){
            digit_count++;
        }
        if(isalpha(pass[i])){
            letter_count++;
        }
        if(isupper(pass[i])){
            uppercase_count++;
        }
    }
    return length >= 8 && digit_count >= 3 && letter_count >= 6 && uppercase_count >= 1;
}

int main(){
    char pass[100];
    scanf("%s", &pass);

    if(valid_password(pass)){
        printf("good d");
    }else{
        printf("bad d try again");
    }

    return 0;
}