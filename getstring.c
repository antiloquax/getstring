#include <stdio.h>
#include <stdlib.h>

int getString(char **buf);

int main(void)
{
    char *buf = NULL;
    int len;
    
    printf("Enter a string: ");
    len = getString(&buf);
    printf("\n%d characters read.\n", len);
    printf("%s\n", buf);
    free(buf);
    return 0;
    }

/* Pass in a pointer to NULL. */
int getString(char **buf)
{
    int len = 0;
    size_t size = 1;
    *buf = malloc(size);
    char ch;
    
    while ((ch = getchar()) != '\n')
    {
        if (len == size)
        {
            size *= 2;
            *buf = realloc(*buf, size);
        }
        (*buf)[len++] = ch;
    }
    
    /* Make space for terminator. */
    if (len == size)
        *buf = realloc(*buf, size + 1);
    (*buf)[len] = '\0';
    return len;
}
