#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>



int main(){
    char str[256], ress[256]="", copy[256]="", copyy[256]="";
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    FILE *in= fopen("input.txt", "r");
    char *word, *wordban, *res;
    int i,j, max=0;


    fgets(str,256,in);
    puts(str);
    /////////////////////
    FILE *out= fopen("output.txt", "w");
    fclose(out);
    out= fopen("output.txt", "a");
    fputs("Исходная строка:\n", out);
    fputs(str, out);
    word =  strtok(str, " ");

    while (word!=NULL){


            if (strcmp(word, ".")!=0)
                    strcat(ress, " ");
            strcat(ress, word);
            word = strtok(NULL, " ");
    }


    res=ress+1;
    puts(res);
    fputs("\n\nСтрока без лишних пробелов:\n", out);
    fputs(res, out);

    /////////////////

    for (i=strlen(res)-1;  res[i] != ' ' &&  i>-1; --i);

    wordban=res+i+1;
    if (wordban[strlen(res)-i-2]=='.')  wordban[strlen(res)-i-2]='\0';

    word =  strtok(res, " ");



    while (word!=NULL){

            if (word!=NULL && strcmp(word, wordban)!=0){
                strcat(copy, word);
                strcat(copy, " "); }
            word= strtok(NULL, " ");

    }
    copy[strlen(copy)-1]='\0';
    puts(copy);
    fputs("\n\nСлова, не равные последнему слову:\n", out);
    fputs(copy, out);

    //////////////////

    memset(ress,0,256);
    word =  strtok(copy, " ");
    int count=0, OtherCount=0;
    char letter;
    while (word!=NULL){
            OtherCount=0;
            for (i=0; i<strlen(word); ++i){
                letter=word[i];
                count=0;
                for (j=0;j<strlen(word);++j){
                    if (letter==word[j]) count++;
                }
                if (count>=2) OtherCount++;
            }
            if (OtherCount==strlen(word)){
                strcat(ress, word);
                strcat(ress, " ");
            }
            word= strtok(NULL, " ");

    }
    copy[strlen(ress)-1]='\0';
    puts(ress);
    fputs("\n\nВ каждом слове каждая буква встречается не менее двух раз:\n", out);
    fputs(ress, out);


}








