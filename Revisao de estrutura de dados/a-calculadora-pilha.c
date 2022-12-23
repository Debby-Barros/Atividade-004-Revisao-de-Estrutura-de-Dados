#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct pilha
{
    int topo;
    unsigned valor;
    int* vetor;

} pilha;
 

pilha * criar_pilha(unsigned valor)
{
    pilha *p;
    p = (pilha *) malloc(sizeof(pilha));
 
    if (!p) 
       return NULL;
 
    p->topo = -1;
    p->valor = valor;
    p->vetor = (int*) malloc(p->valor * sizeof(int));
 
    if (!p->vetor) 
       return NULL;
 
    return p;
}


void push(pilha* pilha, int num)
{
    pilha->vetor[++pilha->topo] = num;
}
 

int pop(pilha* pilha)
{
    if (!pilha_vazia(pilha))
        return pilha->vetor[pilha->topo--] ;
    
    return '$';
}


int pilha_vazia(pilha* pilha)
{
    return pilha->topo == -1 ;
}
 

int resultado(char* expressao)
{
    pilha* pilha = criar_pilha(strlen(expressao));
    int i;
 
    if (!pilha) 
        return -1;

    for (i = 0; expressao[i]; ++i)
    {
        if (expressao[i]==' ') 
            continue;
        
        else if (isdigit(expressao[i]))
        {
            int num=0;
            
            while (isdigit(expressao[i]))
            {
                num=num*10 + (int)(expressao[i]-'0');
                i++;
            }
            
            i--;

            push(pilha, num);
        }

        else
        {
            int valor1 = pop(pilha);
            int valor2 = pop(pilha);
             
            switch (expressao[i])
            {
            case '+': push(pilha, valor2 + valor1); break;
            case '-': push(pilha, valor2 - valor1); break;
            case '*': push(pilha, valor2 * valor1); break;
            case '/': push(pilha, valor2/valor1); break;
            }
        }
    }
    return pop(pilha);
}
 

int main()
{
    //100+200= 300/2 = 150*5 = 750+7 = 757
    char expressao[] = "100 200 + 2 / 5 * 7 +";
    printf ("O resultado da expressao eh: %d", resultado(expressao));
    return 0;
}