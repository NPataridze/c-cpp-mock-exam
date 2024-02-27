#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char str[20];
    struct node* next;
};

struct node* insertBegin(struct node* head, char str[]){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("memory allocation failed. \n");
        exit(1);
    }
    
    strcpy(newNode->str, str);
    newNode->next = head;
    return newNode;
}

void printList(struct node* head){
    struct node* current = head;
    while (current != NULL){
        printf("%s ", current->str);
        current = current->next;
    }
    printf("\n");
}

int main(){
    int n;
    scacnf("%d", &n);

    struct node* head = NULL;

    for(int i = 0; i < n; i++){
        char str[20];
        scanf("%s", &str);
        head = insertBegin(head, str);
    }
     
    printList(head);

    struct node* current = head;
    while(current != NULL){
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}

