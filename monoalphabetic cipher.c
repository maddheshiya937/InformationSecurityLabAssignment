#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char normalChar[]
        = { 'K', 'X', 'V', 'M', 'C', 'N', 'O', 'P', 'H',
            'Q', 'R', 'S', 'Z', 'Y', 'I', 'J', 'A', 'D',
            'L', 'E', 'G', 'W', 'B', 'U', 'F', 'T' };

char codedChar[]
        = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
            'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
            'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };

char* encrypt(char* text){
    int len=strlen(text);
    char* result=(char*)malloc(len+1);
    for(int i=0;i<len;i++){
        if(text[i]==' '){
            result[i]='0';
        }else if ((text[i] & 32) == 0) //check for uppercase
            result[i]= codedChar[text[i]-'A'];
        else
            result [i]= (char)(codedChar[text[i]-'a']+32);
    }
    result[len]='\0';
    return result;
}

char* decrypt(char* text){
    int len=strlen(text);
    char* result=(char*)malloc(len+1);
    for(int i=0;i<len;i++){
        if(text[i]=='0'){
            result[i]=' ';
        }else if ((text[i] & 32) == 0) //check for uppercase
            result[i]= normalChar[text[i]-'A'];
        else
            result [i]= (char)(normalChar[text[i]-'a']+32);
    }
    result[len]='\0';
    return result;
}
int main(){
    char *text=(char*)malloc(100);
    printf("Enter the message: ");
    scanf("%[^\n]",text);
    printf("Text : %s\n",text);
    char *msg= encrypt(text);
    printf("Cipher: %s\n",msg);
    printf("Decrypted: %s\n",decrypt(msg));
    return 0;
}