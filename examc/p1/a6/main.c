#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
struct circlist
{
    struct node *start;
};

void add(int x, struct circlist *list)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->value = x;

    if (list->start == NULL)
    {
        list->start = new_node;
        new_node->next = new_node;
    }
    else
    {
        struct node *current = list->start;
        while (current->next != list->start)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}