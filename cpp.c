#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LIMIT   81

void ToUpper(char* );
int PuctCount(const char* );

int main(void)
{
    char line[LIMIT];
    char* find;

    fputs("Please enter a line:", stdout);
    fgets( line, LIMIT, stdin);
    find = strchr( line, '\n');
    if (find)
        *find = '\0';
    ToUpper(line);
    fputs( line, stdout);
    printf("That's line has %d puctuation characters.\n", PuctCount(line));

    return 0;
}

void ToUpper(char* str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PuctCount(const char* str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }

    return ct;
}
