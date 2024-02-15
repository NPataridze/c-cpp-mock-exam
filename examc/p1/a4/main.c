#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alternate(char *s1, char *s2)
{
    // Get the lengths of s1 and s2
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Allocate memory for the result string
    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Alternately copy characters from s1 and s2 into the result string
    /*int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2)
    {
        result[k++] = s1[i++];
        result[k++] = s2[j++];
    }

    // Copy the remaining characters of the longer string
    while (i < len1)
    {
        result[k++] = s1[i++];
    }
    while (j < len2)
    {
        result[k++] = s2[j++];
    }

    // Add null terminator to the end of the result string
    result[k] = '\0';*/

    return result;
}

int main()
{
    char s1[] = "onestring";
    char s2[] = "another";
    char *result = alternate(s1, s2);
    printf("Result: %s\n", result);

    // Free dynamically allocated memory
    free(result);

    return 0;
}
