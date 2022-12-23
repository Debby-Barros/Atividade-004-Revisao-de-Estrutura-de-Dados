#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int valor;
  struct no *prox;

} no;


no * criar_no(int valor)
{
  no *p;
  p = (no *) malloc(sizeof(no));
  p->valor = valor;
  p->prox = NULL;
  return p;
}


no * push(no **topo, no *no)
{
  if (*topo == NULL)
    *topo = no;
  
  else 
  {
    no->prox = *topo;
    *topo = no;
  }

  return *topo;
}


no * pop(no **topo)
{
  no *aux = *topo;

  if (aux == NULL)
  {
    printf("PILHA VAZIA!");
    return NULL;
  } 
 
  else 
  {
    aux = *topo;
    *topo = (*topo)->prox;
    return aux;
  }
}


void imprimir(no *topo){
  no *aux = topo;
  
  if (aux == NULL)
    printf("PILHA VAZIA!");

  while (aux != NULL)
  {
    printf("%d ", aux->valor);
    aux = aux->prox;
  }
}


int main(int argc, char *argv[])
{
    no *topo = NULL;
    FILE *f = fopen("arquivo.txt", "r");
    int i;

    while (fscanf(f, "%d", &i) == 1)
        topo = push(&topo, criar_no(i));
    
    fclose(f);
    imprimir(topo);

    return 0;
}

