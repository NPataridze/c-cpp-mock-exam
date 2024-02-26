#include <stdio.h>

int substitute_vowels(char *s, char ch){
    int replacements = 0;

    char *ptr = s;
    while(*ptr != '\0'){
        if(*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u'){
            *ptr = ch;
            replacements++;
        }
    ptr++;
    }
    return replacements;
}

int main(){
    char s[] = "This is a sentence";
    printf("%s\n", s);

    int n = substitute_vowels(s, 'o');
    printf("%s\n", s);
    printf("%d\n", n);

    return 0;
}