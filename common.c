#include <stdio.h>
#include <stdlib.h>

const char* read_line(FILE* file, char* buffer, int len)
{
    if (file == NULL)
    {
        printf("Error: file pointer is null.");
        return NULL;
    }

    char ch = getc(file);
    int count = 0;
    while((ch != '\n') && (ch != EOF))
    {
        if(count == len)
        {
            printf("Line too long");
        }

        buffer[count] = ch;
        count++;
        ch = getc(file);
    }

    buffer[count] = '\0';

}

int pos_first_substring(char* str, char* sub)
{
    int i = 0;
    int lenstr = strlen(str);
    int lensub = strlen(sub);

    if(lensub > lenstr)
    {
        return -1;
    }

    for(int i = 0; i < (lenstr-lensub); i++)
    {
        if(strncmp(str+i, sub, lensub) == 0)
        {
            return i;
        }
    }

    return -1;
}

int pos_last_substring(char* str, char* sub)
{
    int i = 0;
    int pos = -1;
    int lenstr = strlen(str);
    int lensub = strlen(sub);

    if(lensub > lenstr)
    {
        return -1;
    }

    for(int i = 0; i < (lenstr-lensub) + 1; i++)
    {
        if(strncmp(str+i, sub, lensub) == 0)
        {
            pos = i;
        }
    }

    return pos;
}

int pos_first_digit(char* str, char digit)
{
    int i = 0;
    int pos = -1;
    while(str[i] != '\0')
    {
        if(str[i] == digit)
        {
            pos = i;
            break;
        }
        i++;
    }
    return pos;
}

int pos_last_digit(char* str, char digit)
{
    int i = 0;
    int pos = -1;
    while(str[i] != '\0')
    {
        if(str[i] == digit)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}