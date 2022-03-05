#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20000
struct pereche
{

    char *camp, *valoare;

};
// Functie care verifica daca un camp este un cuvant
int check_word(char *p,int l)
{
    char aux[SIZE],delim[]=" ,?!.;\n",*q1,*q2;
    strcpy(aux,p);
    //q1 verifica daca primul caracter este delimitator
    //q2 verifica daca ultimul caracter este delimitator
    q1=strchr(delim,aux[0]);
    q2=strchr(delim,aux[l+1]);
    //daca exista delimitator si la inceput si la final atunci este cuvant
    if(q1!=NULL && q2!=NULL)
        return 0;
    //in caz contrar vedem cate caractere trebuie sa sarim
    while(q2==NULL)
    {
        l++;
        q2=strchr(delim,aux[l+1]);
    }
    return l;
}
// Stergerea unui cuvant dintr-un sir
void strdel(char *p, int n)
{
    char aux[SIZE];
    strcpy (aux, p+n);
    strcpy (p, aux);
}
// Inserarea unui cuvant intr-un sir
void strins(char *p, char *s)
{
    char aux[SIZE];
    strcpy(aux,s);
    strcat(aux,p);
    strcpy(p,aux);
}
// Citirea datelor de intrare
char * readstr(struct pereche *v,int n)
{
    int i;
    char camp[SIZE],valoare[SIZE],auxiliar[SIZE],c,*mesaj;
    mesaj=(char*)malloc(SIZE);

    for(i=0; i<n; i++)
    {
        scanf("%s",camp);//camp
        scanf("%s",valoare);//valoare
        v[i].camp=(char*)malloc(SIZE);
        v[i].valoare=(char*)malloc(SIZE);
        strcpy(v[i].camp,camp);
        strcpy(v[i].valoare,valoare);
    }
    // In variabila c se va citi caracterul '\n'
    scanf("%c",&c);
    fgets(auxiliar,SIZE,stdin);
    strcpy(mesaj,auxiliar);
    return mesaj;
}
int main()
{
    // Initializare variabile: n=nr de perechi,v este vectorul de campuri
    int n,i,lungime_camp,lungime_valoare,lungime_mesaj,check;
    char *pozitie_in_mesaj,*mesaj,*copiemesaj,delim[]=" ,?!.;\n",*q;
    struct pereche *v;
    // Citirea datelor de intrare + alocarea memoriei necesare
    scanf("%d",&n);
    v=malloc((n+1)*sizeof(struct pereche));
    mesaj=readstr(v,n);
    copiemesaj=(char*)malloc(SIZE);

    for(i=0; i<n; i++)
    {
        pozitie_in_mesaj=mesaj;
        lungime_camp=strlen(v[i].camp);
        lungime_valoare=strlen(v[i].valoare);
        strcpy(copiemesaj,mesaj);
        q=strtok(copiemesaj,delim);
        /* Verificam daca campul se afla la inceputul mesajului.
        Este necesar sa tratam cazul acesta separat intrucat nu se poate
        verifica daca caracterul dinaintea campului este separator */
        if(strcmp(q,v[i].camp)==0)
        {
            strdel(pozitie_in_mesaj,strlen(v[i].camp));
            strins(pozitie_in_mesaj,v[i].valoare);
            pozitie_in_mesaj+=lungime_valoare;
        }
        // Cautam campul in sir
        pozitie_in_mesaj=strstr(pozitie_in_mesaj,v[i].camp);
        while(pozitie_in_mesaj!=NULL)
        {
            // Verificam daca campul este cuvant (nu este inclus intr-un alt cuvant)
            check=check_word(pozitie_in_mesaj-1,lungime_camp);
            if(!check)
            {
                // Stergem campul de la pozitia respectiva
                strdel(pozitie_in_mesaj,strlen(v[i].camp));
                // Inseram Valoarea la adresa aceea
                strins(pozitie_in_mesaj,v[i].valoare);
                /* Este important sa nu aplicam functia de autofill
                pe cuvintele aparute in urma inlocuirii */
                pozitie_in_mesaj+=lungime_valoare;
            }
            else
                // check reprezinta si nr de caractere pe care trebuie sa le sarim
                pozitie_in_mesaj+=check;
            // Reluam cautarea urmatorului camp in mesaj
            pozitie_in_mesaj=strstr(pozitie_in_mesaj,v[i].camp);
        }
    }
    lungime_mesaj=strlen(mesaj);
    mesaj=(char*)realloc(mesaj,lungime_mesaj+1);
    // Afisarea mesajului final
    printf("%s",mesaj);
    // Eliberarea memoriei
    for(i=0; i<n; i++)
    {
        free(v[i].camp);
        free(v[i].valoare);
    }
    free(v);
    free(copiemesaj);
    free(mesaj);
    return 0;
}
