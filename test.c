#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static int id = 0;

typedef struct proceso {
    int procesador;
    int id_proceso;
    int prioridad;
    char estado[10];
} proceso;

proceso* scheduling[10];

void asignaEstado(proceso* p) {
    if (strcmp(p->estado, "Nuevo") == 0) {
        strcpy(p->estado, "Listo");
    } else if (strcmp(p->estado, "Listo") == 0) {
        strcpy(p->estado, "Corriendo");
    } else if (strcmp(p->estado, "Corriendo") == 0) {
        strcpy(p->estado, "Terminado");
    }
}

void ingresaProceso() {
    if (id < 10) {
        proceso* nuevoProceso = malloc(sizeof(proceso));
        nuevoProceso->procesador = 0;
        nuevoProceso->id_proceso = rand();
        nuevoProceso->prioridad = id;
        strcpy(nuevoProceso->estado, "Nuevo");
        
        scheduling[id] = nuevoProceso;
        id++;
    } else {
        printf("No hay espacio disponible para más procesos.\n");
    }
}

int terminaProceso() {
    int i;
    for (i = 0; i < id; i++) {
        if (strcmp(scheduling[i]->estado, "Terminado") == 0) {
            free(scheduling[i]);
            break;
        }
    }
    return i;
}

void recorreCola() {
    int i;
    for (i = 0; i < id; i++) {
        asignaEstado(scheduling[i]);
    }
}

void mostrarScheduler() {
    int i;
    for (i = 0; i < id; i++) {
        printf("[%d]-> {%d;%d;%d;\"%s\"}\n", i, scheduling[i]->procesador, scheduling[i]->id_proceso, scheduling[i]->prioridad, scheduling[i]->estado);
    }
}

int main() {
    srand(time(NULL));

    // Inicializar scheduler
    int i;
    for (i = 0; i < 10; i++) {
        scheduling[i] = NULL;
    }

    // Ingresar procesos
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();
    ingresaProceso();

    // Ejecutar recorrido inicial
    recorreCola();
    mostrarScheduler();

    // Ingresar más procesos
    ingresaProceso();
    ingresaProceso();

    // Ejecutar recorrido
    recorreCola();
    mostrarScheduler();

    // Terminar procesos
    int lugarLiberado = terminaProceso();
    printf("Lugar liberado: %d\n", lugarLiberado);

    // Ejecutar recorrido final
    recorreCola();
    mostrarScheduler();

    return 0;
}
