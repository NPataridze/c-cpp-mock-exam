#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_spaces(char *s)
{
    // Get the length of the input string
    int len = strlen(s);

    // Count the number of spaces to determine the length of the new string
    int space_count = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            space_count++;
        }
    }

    // Calculate the length of the new string
    int new_len = len + space_count;

    // Allocate memory for the new string
    char *result = (char *)malloc((new_len + 1) * sizeof(char));
    if (result == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Replace spaces with length of previous word
    int index = 0;
    int prev_len = 0; // Length of the previous word
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            // Replace space with the length of the previous word
            result[index++] = nr2char(prev_len);
            // Reset previous word length for the next word
            prev_len = 0;
        }
        else
        {
            // Copy character from input string to result
            result[index++] = s[i];
            // Increment previous word length
            prev_len++;
        }
    }

    // Add length of last word to the end of the result
    result[index] = nr2char(prev_len);

    return result;
}
