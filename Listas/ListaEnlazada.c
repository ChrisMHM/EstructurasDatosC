#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void ImprimirLista(struct Nodo *ptrLista) {
    while (ptrLista != NULL) {
        if (ptrLista->siguiente == NULL)
            printf("%d\n", ptrLista->dato);
        else
            printf("%d -> ", ptrLista->dato);
        ptrLista = ptrLista->siguiente;
    }
}

void ImprimirListaR(struct Nodo *ptrLista) {
    if (ptrLista != NULL) {
        if (ptrLista->siguiente == NULL)
            printf("%d\n", ptrLista->dato);
        else
            printf("%d -> ", ptrLista->dato);
        ImprimirListaR(ptrLista->siguiente);
    }
}

int TamanioLista(struct Nodo *ptrLista) {
    int cont = 0;

    while (ptrLista != NULL) {
        cont++;
        ptrLista = ptrLista->siguiente;
    }
    
    printf("\nTamanio lista: %d", cont);
    return cont;
}

int TamanioListaR(struct Nodo *ptrLista) {
    if (ptrLista != NULL)
        return TamanioListaR(ptrLista->siguiente) + 1;
    else 
        return 0;
}

int Suma(struct Nodo *ptrLista) {
    int suma = 0;

    while (ptrLista != 0)
    {
        suma += ptrLista->dato;
        ptrLista = ptrLista->siguiente;
    }
    
    return suma;
}

int SumaR(struct Nodo *ptrLista) {
    if (ptrLista != NULL)
    {
        return SumaR(ptrLista->siguiente) + ptrLista->dato;
    }
    
    return 0;
}

int Max(struct Nodo *ptrLista) {
    int max = INT_MIN;

    while (ptrLista) {
        if (ptrLista->dato > max)
            max = ptrLista->dato;

        ptrLista = ptrLista->siguiente;
    }
    
    return max;
}

// Busqueda lineal

struct Nodo * Busqueda(struct Nodo *ptrLista, int key) {
    //int posicion = 1;

    while (ptrLista != NULL) {
        if (ptrLista->dato == key)
            return ptrLista;
        
        // posicion++;
        ptrLista = ptrLista->siguiente;
    }
    
    return NULL;
}

struct Nodo* BusquedaR(struct Nodo *ptrLista, int key) {
    // int posicion = 1;

    if (ptrLista == NULL)
        return NULL;
    else if (ptrLista->dato == key)
        return ptrLista;

    return BusquedaR(ptrLista->siguiente, key);
}

struct Nodo * BusquedaM(struct Nodo *ptrLista, int key) {
    struct Nodo *primero = ptrLista;
    struct Nodo *ptrAux = NULL;

    while(ptrLista != NULL) {
        if(ptrLista->dato == key) {
            ptrAux->siguiente = ptrLista->siguiente;
            ptrLista->siguiente = primero;
            return ptrLista;
        }

        ptrAux = ptrLista;
        ptrLista = ptrLista->siguiente;
    }

    return NULL;
}

/*******************************************************************************
 * Insertar elemento
********************************************************************************/

struct Nodo * Insertar(struct Nodo *ptrLista, int index, int datoU) {
    int i;

    if(ptrLista == NULL) {
        ptrLista = (struct Nodo *)malloc(sizeof(struct Nodo));
        ptrLista->dato = datoU;
        ptrLista->siguiente = NULL;
        return ptrLista;
    }

    if (index < 0 || index > TamanioLista(ptrLista)) {
        printf("\nError: indice no valido.");
        return NULL;
    }

    struct Nodo *ptrElemento;
    ptrElemento = (struct Nodo *)malloc(sizeof(struct Nodo));
    ptrElemento->dato = datoU;

    if (index == 0) {
        ptrElemento->siguiente = ptrLista;
        ptrLista = ptrElemento;
    } else {
        for (i = 0; i < index - 1; i++) {
            ptrLista = ptrLista->siguiente;
        }

        ptrElemento->siguiente = ptrLista->siguiente;
        ptrLista->siguiente = ptrElemento;
    }

    return ptrLista;
}


/*******************************************************************************
 * Crear lista
********************************************************************************/

/*******************************************************************************
    Funcion main
********************************************************************************/

int main() {
    struct Nodo *primero;
    struct Nodo *segundo;
    // struct Nodo *tercero;
    // struct Nodo *cuarto;
    // struct Nodo *resultado;
    int key;

    primero = NULL;
    // primero = (struct Nodo *)malloc(sizeof(struct Nodo));
    /*
    segundo = (struct Nodo *)malloc(sizeof(struct Nodo));
    tercero = (struct Nodo *)malloc(sizeof(struct Nodo));
    cuarto = (struct Nodo *)malloc(sizeof(struct Nodo));

    primero->dato = 10;
    primero->siguiente = segundo;

    segundo->dato = 20;
    segundo->siguiente = tercero;

    tercero->dato = 40;
    tercero->siguiente = cuarto;

    cuarto->dato = 100;
    cuarto->siguiente = NULL;

    // ImprimirLista(primero);
    
    ImprimirListaR(primero);
    printf("\nTamanio lista: %d", TamanioListaR(primero));
    printf("\nTamanio lista recursivo: %d", TamanioListaR(primero));
    printf("\nSuma de los elementos: %d", Suma(primero));
    printf("\nSuma de los elementos recursivo: %d", SumaR(primero));
    printf("\nValor maximo de la lista: %d", Max(primero));

    printf("\nIngresa numero a buscar: ");
    scanf("%d", &key);

    printf("\nNumero ingresado %d", key);
    resultado = Busqueda(primero, key);
    printf("\n****** Busqueda lineal iterativa *****");
    if(resultado == NULL) {
        printf("\nNumero no encontrado.");
    } else {
        printf("\nNumero %d encontrado", key);
    }

    resultado = BusquedaR(primero, key);
    printf("\n****** Busqueda lineal recursiva *****");
    if(resultado == NULL) {
        printf("\nNumero no encontrado.");
    } else {
        printf("\nNumero %d encontrado", key);
    }

    resultado = BusquedaM(primero, key);
    printf("\n****** Busqueda lineal mejorada *****");
    if(resultado == NULL) {
        printf("\nNumero no encontrado.");
    } else {
        printf("\nNumero %d encontrado", key);
    } */
    int elemento;
    int index;

    printf("\nElemento: ");
    scanf("%d", &elemento);
    printf("Posicion: ");
    scanf("%d", &index);
    primero = Insertar(primero, index, elemento);

    printf("\n");
    ImprimirLista(primero);

    int opcion = 0;
    while (opcion != -1){
    }
    

    printf("\n");


    return 0;
}