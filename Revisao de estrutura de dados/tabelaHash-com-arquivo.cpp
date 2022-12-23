#include<stdio.h>
#include<stdlib.h>
 

using namespace std;
 
int m = 11;
int tabela1[11];
 

int funcao_hash(int k)
{
    return k % m;
}
 

int linear_hash(int k)
{
    int r = funcao_hash(k);
    int i = 0;
 
    while(i < m)
    {
        if (tabela1[r + i] == -1)
        {
            tabela1[r + i] = k;
            return i;
        }

        i += 1;
    }
}


void imprimir()
{
    printf("\n--------------TABELA-----------------\n");
    
    for(int i = 0; i < 11; i++)
    {
        if (tabela1[i]!=-1) 
            printf("%d %d\n", i, tabela1[i]);
        
        else 
            printf("%d ---\n", i);
    }
    
    printf("\n--------------------------------------\n");
}


void inicializar_tabela()
{
    for(int i = 0; i < 11; i++)
    {
        tabela1[i] = -1;
    }
}

 
int main(int argc, char *argv[])
{
    inicializar_tabela();

    FILE *f = fopen("arquivo2.txt", "r");
    int i;
 
    while (fscanf(f, "%d", &i) == 1)
    {
        linear_hash(i);
    }

    fclose(f);
    imprimir();
   
    return 0;
}
