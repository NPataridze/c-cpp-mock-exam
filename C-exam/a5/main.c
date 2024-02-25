#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input = fopen("input_grades.txt", "r");
    if (input == NULL)
    {
        return 1;
    }
    FILE *output = fopen("average.txt", "w");
    if (output == NULL)
    {
        fclose(input);
        return 1;
    }

    int matric, grade1, grade2;
    while (fscanf(input, "%d %d %d", &matric, &grade1, &grade2) == 3)
    {
        double avg_grade = (grade1 + grade2) / 2;
        fprinf(output, "%d %lf\n", matric, avg_grade);
    }

    fclose(input);
    fclose(output);

    return 0;
}