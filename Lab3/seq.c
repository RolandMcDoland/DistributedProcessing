#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 4 literowe
aa5UYq6trT5u.
bahAZ9Hk7SCf6
ddoo3WocSpthU
jkmD2RlhoMyuA
zzm4NUIIb7VIk
kkv864igyJC9o

5 literowe
aaSPfLTmjh3fU

6 literowe
aaLTdQr7DyHuU 
*/

char *stro="aaLTdQr7DyHuU";


int main(int argc, char **argv)
{
    int size,rank;
    
    char cmp[7]={0};

    char salt[3]={0};
    salt[0]=stro[0];
    salt[1]=stro[1];

    /* Ten fragment kodu nalezy _jakos_ zrównoleglić */
    /* pewnie będzie potrzebna jakaś pętla... */

    for(char i='a';i<='z';i++)
    {
        cmp[0]=i;
        for(char j='a';j<='z';j++)
        {
            cmp[1]=j;
            for(char k='a';k<='z';k++)
            {
                cmp[2]=k;
                for(char l='a';l<='z';l++)
                {
                    cmp[3]=l;
                    for(char m='a';m<='z';m++)
                    {
                        cmp[4]=m;
                        for(char n='a';n<='z';n++)
                        {
                            cmp[5]=n;

                            char * x=crypt(cmp, salt);

                            if ((strcmp(x,stro))==0)
                            {
                                    /* w docelowej wersji przeslac odgadnięte hasło masterowi */
                                printf("Udalo sie: %s %s %s\n", cmp, x, stro);
                                exit(0);
                        }
                        }
                    }
                }
            }
        }
    }
    /* Koniec fragmentu kodu */
}
