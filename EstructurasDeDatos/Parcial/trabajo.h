#define MAXCT 15
#define CANT 3
#define TRUE 1
#define FALSE 0

typedef struct nodo
{
    char nombre[MAXCT];
    struct nodo *siguiente;

}legislador;

/*PROTOTIPOS DE LAS FUNCIONES*/
void inserta(legislador **, char []);
void insertarDato (legislador **, legislador *, char []);
legislador *CrearNodo (char []);
void inserInic (legislador **, char []);
void mostrar (legislador *);
void suprime (legislador **,char []);
int miembro (legislador **, char []);
void liberarLista (legislador **);