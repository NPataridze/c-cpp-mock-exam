#include <stdio.h>

void print_odd_backwards(int nr)
{
    if (nr < 1)
    {
        return;
    }

    if (nr % 2 == 1)
    {
        printf("%d ", nr);
        print_odd_backwards(nr - 2);
    }
    else
    {
        print_odd_backwards(nr - 1);
    }
}

int main()
{
    int nr;
    scanf("%d", &nr);

    print_odd_backwards(nr);

    return 0;
}