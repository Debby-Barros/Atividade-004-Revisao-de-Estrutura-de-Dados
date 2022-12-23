#include<stdio.h>
#include<stdlib.h>

 
typedef struct no 
{
    int conteudo;
    struct no *esq;
    struct no *dir;

} no;
 

no* criar_no(int conteudo)
{
    no* novo = (no*) malloc(sizeof(no));
    novo->conteudo = conteudo;
    novo->esq = NULL;
    novo->dir = NULL;
 
    return novo;
}
 

no* inserir_no(no *no, int conteudo) 
{
    if (no == NULL) 
      no = criar_no(conteudo);

    else if (no->conteudo > conteudo) 
      no->esq = inserir_no(no->esq, conteudo);

    else
      no->dir = inserir_no(no->dir, conteudo);

    return no;
}
 

void exibir_pre_ordem(no *raiz)
{
  if (raiz == NULL) 
    return;

  printf("%d ",raiz->conteudo);
  exibir_pre_ordem(raiz->esq);
  exibir_pre_ordem(raiz->dir);
}
 

void exibir_in_ordem(no *raiz)
{
  if (raiz == NULL) 
    return;

  exibir_in_ordem(raiz->esq);
  printf("%d ",raiz->conteudo);
  exibir_in_ordem(raiz->dir);
}


void exibir_pos_ordem(no *raiz)
{
  if (raiz == NULL) 
    return;

  exibir_pos_ordem(raiz->esq);
  exibir_pos_ordem(raiz->dir);
  printf("%d ",raiz->conteudo);
}

 
int main(int argc, char *argv[])
{
    no *raiz = NULL;

    FILE *f = fopen("arquivo3.txt", "r");
    int i;
 
    while (fscanf(f, "%d", &i) == 1)
    {
      raiz = inserir_no(raiz, i);
    }
 
    fclose(f);

    printf("Pre-ordem: ");
    exibir_pre_ordem(raiz);
    printf("\n");
    printf("In-ordem: ");
    exibir_in_ordem(raiz);
    printf("\n");
    printf("Pos-ordem: ");
    exibir_pos_ordem(raiz);

    return 0;
}
