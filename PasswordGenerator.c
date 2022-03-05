// Petcu Eduard - 314 CC
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MOD 94
#define CODMAX 10
char *generare_parola(int seed,int n)
{
    int i;
    char *sir=(char*)(malloc(n+1));
    for(i=0; i<n; i++)
        // Caracterele generate au codurile ASCII intre 32 si 125
        sir[i]=(rand()%MOD+32);
    return sir;
}

char *codificare0(char c)
{
    /* rezultat0 este pointerul rezultat in urma codificarii0
    retine este un sir de caractere in care
    retinem frecventa unui caracter */
    char *rezultat0,retine[CODMAX];
    int nrcifre=0,ultima_cifra,nrfrecventa,i;
    static int frecventa[MOD];

    rezultat0=(char*)malloc(CODMAX);
    rezultat0[0]=c;
    nrfrecventa=frecventa[c-32];
    /* In situatia in care frecventa unui caracter are mai multe
    cifre, trebuie sa retinem toate aceste cifre
    intr-un sir de caractere */
    do
    {
        ultima_cifra=nrfrecventa%10;
        retine[nrcifre]=(char)ultima_cifra+'0';
        nrcifre++;
        nrfrecventa/=10;
    }
    while(nrfrecventa>0);
    /* Cifrele preluate in sirul retine[] apar in ordine inversa
    (de la cifra unitatilor la cifra cea mai semnificativa), deci este necesara
    inversarea acestui sir */
    for(i=1; i<=nrcifre; i++)
        rezultat0[i]=retine[nrcifre-i];
    rezultat0[nrcifre+1]='\0';
    frecventa[c-32]++;
    return rezultat0;
}
char *codificare1(char c)
{
    /* count numara bitii egali cu 1
    72=01001000
    32=00100000 */
    char *rezultat1;
    int x,copiex,operator1=72,operator2=32,count=0;
    rezultat1=(char*)malloc(CODMAX);
    x=(int)c;
    /* Inversam bitii de pe pozitia 3 si 6 facand XOR
    cu numarul 72 */
    x=x^operator1;
    copiex=x;
    // Numaram bitii egali cu 1
    while(copiex)
    {
        if(copiex&1)
            count++;
        copiex=copiex>>1;
    }
    // Operatia de SAU logic cu masca 00100000
    x=x|operator2;
    // Setarea la 0 a LSB
    x&=~1;
    rezultat1[0]=(char)x;
    rezultat1[1]=(char)count+'0';
    rezultat1[2]='\0';
    return rezultat1;
}
char *codificare2(char c)
{
    char *rez2;
    rez2=(char*)malloc(CODMAX);
    if(c>='a' && c<='z')
        c-=32;
    rez2[0]=c;
    rez2[1]='\0';
    return rez2;
}
void transformare(char *sir,int n)
{
    // numar=codificarea care se genereaza in for (0,1 sau 2)
    int numar,i;
    char *(*pointer[3])(char),*pointer_rezultat;

    pointer[0] = &codificare0;
    pointer[1] = &codificare1;
    pointer[2] = &codificare2;

    for(i=0; i<n; i++)
    {
        numar=rand()%3;
        pointer_rezultat=pointer[numar](sir[i]);
        printf("%s",pointer_rezultat);
        free(pointer_rezultat);
    }
}
int main()
{
    int seed,n;
    char *sir;

    scanf("%d%d",&seed,&n);
    srand(seed);
    sir=generare_parola(seed,n);
    transformare(sir,n);

    printf("\n");
    free(sir);
    return 0;
}
