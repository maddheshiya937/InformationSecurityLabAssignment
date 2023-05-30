#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* generateKey(char* str, char* key)
{
    int x = strlen(str);
    int y = strlen(key);

    char* newKey=(char*)malloc(x+1);
    for (int i = 0; i<x; i++)
    {
        newKey[i] = key[i%y];
    }
    newKey[x]='\0';
    return newKey;
}

char* encrypt(char* str, char* key){
    int len = strlen(str);
    char* cipher_text=(char*)malloc(len+1);
    char* newKey=generateKey(str,key); 

    for (int i = 0; i < len; i++){
        char x = (str[i] + newKey[i]) %26;
        cipher_text[i]=x+'A';
    }
    cipher_text[len]='\0';
    return cipher_text;
}
char* decrypt(char* str, char* key){
    int len = strlen(str);
    char* cipher_text=(char*)malloc(len+1);
    char* newKey=generateKey(str,key); 

    for (int i = 0; i < len; i++){
        char x = (str[i] - newKey[i]+26) %26;
        cipher_text[i]=x+'A';
    }
    cipher_text[len]='\0';
    return cipher_text;
}
int main(){
    char *text=(char*)malloc(100);
    char *key=(char*)malloc(100);
    printf("Enter the message: ");
    scanf("%[^\n]",text);
    printf("Enter a key : ");
    scanf("%s",key);
    printf("Text : %s\n",text);
    char *msg= encrypt(text,key);
    printf("Cipher: %s\n",msg);
    printf("Decrypted: %s\n",decrypt(msg,key));
    return 0;
}