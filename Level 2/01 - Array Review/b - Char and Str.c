#include <stdio.h>
#define SIZE 20

int getLength(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    // THIS IS AN ARRAY OF CHARACTERS
    char str1[SIZE] = {'h', 'e', 'l', 'l', 'o'};

    // THIS IS A STRING
    char str2[SIZE] = "hello"; // char str1[] = {'h', 'e', 'l', 'l', 'o', '\0'}; //both has NULL TERMINATOR
    char str0[SIZE];

    printf("Get string input: ");
    fgets(str0, SIZE, stdin);
    int i = 0;
    while (str0[i] != '\0')
    {
        if (str0[i] == '\n')
        { // remove newline
            str0[i] = '\0';
            break;
        }
        i++;
    }
    printf("Your input: %s\n", str0);

    while (str2[i] != '\0')
    {
        i++;
    }
    printf("Original string: %s\n", str2);
    printf("Reverse string: ");

    int len = i;
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str2[i]);
    }
    printf("\n");

    printf("Length of input: %d\n", getLength(str0));
    return 0;
}
