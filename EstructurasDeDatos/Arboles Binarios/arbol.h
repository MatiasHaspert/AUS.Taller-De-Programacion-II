typedef struct nodo
{
    int dato;
    struct nodo *h_izq,*h_der;

}arbol;


void inserta (arbol **,int );
void suprime (arbol **,int );
int es_miembro (arbol *,int );
int suprime_menor(arbol **);
void inorder(arbol *);
void preorder(arbol *);
void postorder(arbol *);