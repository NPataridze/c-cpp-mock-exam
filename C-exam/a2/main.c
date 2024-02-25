#include <stdio.h>

int count1s(unsigned char x)
{
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        if (x & (1 << i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    unsigned char x = 0b10101010;
    printf("%d: %d\n", x, count1s(x));
}