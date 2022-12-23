#include <iostream>
using namespace std;
 
typedef struct no 
{
    string valor;
    no *esq= NULL, *dir = NULL;   
    
    no (string x)
    {
        valor = x;
    }

} no;
 

int mudar_para_int(string s)
{
    int num = 0;    
    
    if (s[0]!='-')
    {
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
    }
    else
    {
        for (int i=1; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
      
      num = num*-1;
    }  
    return num;
}
 

int resultado(no* raiz)
{
    if (!raiz) return 0;

    if (!raiz->esq && !raiz->dir)
        return mudar_para_int(raiz->valor);

    int esq = resultado(raiz->esq);
    int dir = resultado(raiz->dir);

    if (raiz->valor=="+")
        return esq+dir;
 
    if (raiz->valor=="-")
        return esq-dir;
 
    if (raiz->valor=="*")
        return esq*dir;

    if (raiz->valor=="/")
        return esq/dir;
}


int main()
{
    no *raiz = new no ("+");
    raiz->esq = new no ("*");
    raiz->esq->esq = new no ("5");
    raiz->esq->dir = new no ("-4");
    raiz->dir = new no ("-");
    raiz->dir->esq = new no ("100");
    raiz->dir->dir = new no ("20");
    
    cout << "O resultado da expressao eh: " << resultado(raiz) << endl;
 
    return 0;
}
