#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL)
    {
        return 1;
    }

    // memory allocation for each row
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = (int *)malloc(m * sizeof(int));
        if (matrix[i] == NULL)
        {
            for (int j = 0; j < m; j++)
            {
                free(matrix[i]);
            }
            free(matrix);
            return 1;
        }
    }

    // enter elements of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // printing the outside frame
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                printf("%d ", matrix[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    // free dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}