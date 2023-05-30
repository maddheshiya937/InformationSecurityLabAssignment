#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *encrypt(char *text, int s)
{
    int len = strlen(text);
    char *result = (char *)malloc(len + 1);

    // traversing and encoding
    for (int i = 0; i < len; i++)
    {

        if (text[i] == ' ')
        {
            result[i] = '0';
        }
        else if ((text[i] & 32) == 0) // check for uppercase
            result[i] = (char)((int)(text[i] + s - 'A') % 26 + 65);
        else
            result[i] = (char)((int)(text[i] + s - 'a') % 26 + 97);
    }
    result[len] = '\0';
    return result;
}

char *decrypt(char *text, int s)
{
    int len = strlen(text);
    char *result = (char *)malloc(len + 1);

    // traverse text
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '0')
        {
            result[i] = ' ';
        }
        else if ((text[i] & 32) == 0)
            result[i] = (char)((int)(text[i] - s - 'A' + 26) % 26 + 'A');
        else
            result[i] = (char)((int)(text[i] - s - 'a' + 26) % 26 + 'a');
    }
    result[len] = '\0';
    return result;
}

int main()
{
    char *text = (char *)malloc(100);
    printf("Enter the message: ");
    scanf("%[^\n]", text);
    int s = 3;
    printf("Text : %s\n", text);
    char *msg = encrypt(text, s);
    printf("Cipher: %s\n", msg);
    printf("Decrypted: %s\n", decrypt(msg, s));
    return 0;
}