// Petcu Eduard - Grupa 314CC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 17000
// Verificam daca cheia sau textul contin doar litere
int check(char key[],char text[])
{
    int lungime_key,lungime_text,i;
    lungime_key=strlen(key);
    lungime_text=strlen(text);
    // Verificam daca cheia este formata doar din litere
    for(i=0; i<lungime_key; i++)
        if(!isalpha(key[i]))
            return 1;
    // Verificam daca textul este format doar din litere
    for(i=0; i<lungime_text; i++)
        if(!isalpha(text[i]))
            return 1;
    return 0;
}
void multiplicare(char key[],char text[])
{
    char aux[SIZE];
    int lungime_key,lungime_text,lungime_initiala;
    lungime_key=strlen(key);
    lungime_initiala=lungime_key;
    lungime_text=strlen(text);

    // Copiem cheia intr-un sir de caractere alocat static auxiliar
    strcpy(aux,key);
    /* Multiplicam cheia originala in sirul auxiliar pana cand
    lungimea sirului auxiliar devine mai mare sau egala cu lungimea textului */
    while(lungime_key<lungime_text)
    {
        lungime_key+=lungime_initiala;
        strcat(key,aux);
    }
    /* Punem '\0' (care reprezinta sfarsitul sirului de caractere) astfel incat
    lungimea cheii sa nu depaseasca lungimea textului. */
    key[lungime_text]='\0';
}
char transformare(char text,char key)
{
    int schimbare_marime=0;
    char distanta;
    /* Am ales sa verific daca caracterul cheii este litera mica
    iar in caz contrar sa o modific in litera mica intrucat
    daca litera cheii este mare, atunci caracterul textului va
    trebui sa-si schimbe si marimea (sa devina litera mare daca era litera mica
    si vice-versa) */
    if(isupper(key))
    {
        key=tolower(key);
        schimbare_marime=1;
    }
    if(schimbare_marime==1)
    {
        if(isupper(text))
            text=tolower(text);
        else
            text=toupper(text);
    }
    distanta=key-'a';
    if(islower(text))
        // Daca in urma deplasarii litera va deveni mare
        if('z'-text<distanta)
        {
            //text='A';
            distanta=distanta-('z'-text)-1;
            text='A'+distanta;
        }
        else
            text=text+distanta;
    else
        // Daca in urma deplasarii litera va deveni mica
        if('Z'-text<distanta)
        {
            distanta=distanta-('Z'-text)-1;
            text='a'+distanta;
        }
        else
            text=text+distanta;
    return text;
}
void modificare_text(char key[],char text[])
{
    int lungime_text,i;
    lungime_text=strlen(text);
    // Aplicam transformarea fiecarui caracter al textului
    for(i=0; i<lungime_text; i++)
        text[i]=transformare(text[i],key[i]);
}
int main()
{
    char key[SIZE],plain_text[SIZE];
    scanf("%s",key);
    scanf("%s",plain_text);
    // Verificam daca cheia si textul contin doar litere
    if(check(key,plain_text))
    {
        printf("INVALID\n");
        return 0;
    }
    multiplicare(key,plain_text);
    modificare_text(key,plain_text);
    printf("%s\n",plain_text);
    return 0;
}
