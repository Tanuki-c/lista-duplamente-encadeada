#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista {
    int info;
    struct lista *prox;
    struct lista *ant;
};

typedef struct lista Lista;

Lista* inicializaLista() {
    return NULL;
}

bool vazia(Lista *pL) {
    return (pL == NULL);
}

Lista* inserir(Lista *pL, int valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo != NULL) {
        novo->info = valor;
        novo->prox = pL;
        novo->ant = NULL;

        if (pL != NULL) {
            pL->ant = novo;
        }

        return novo;
    }
    return pL;
}

void imprimir(Lista *pL) {
    while (pL != NULL) {
        printf(" %d ", pL->info);
        pL = pL->prox;
    }
    printf("\n\nFim da Lista Duplamente Encadeada! \n\n");
}

Lista* buscar(Lista *pL, int valor) {
    while (pL != NULL) {
        if (pL->info == valor)
            return pL;
        pL = pL->prox;
    }
    return NULL;
}

Lista* remover(Lista *pL, int valor) {
    Lista *p = pL;
    while (p != NULL && p->info != valor) {
        p = p->prox;
    }

    if (p == NULL) {
        return pL;
    }

    if (p->ant == NULL) {
        pL = p->prox;
    } else {
        p->ant->prox = p->prox;
    }

    if (p->prox != NULL) {
        p->prox->ant = p->ant;
    }

    free(p);
    return pL;
}

void libera(Lista *pL) {
    Lista *p = pL;
    while (p != NULL) {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

int main() {
    Lista *L = inicializaLista();
    Lista *Q;

    if (vazia(L)) {
        printf("Lista Vazia! \n");
    } else {
        printf("Lista com elementos! \n");
    }

    L = inserir(L, 1000);
    L = inserir(L, 100);
    L = inserir(L, 10);
    L = inserir(L, 1);

    printf("Imprimindo a Lista... \n\n");
    imprimir(L);

    Q = buscar(L, 10);
    if (Q != NULL) {
        printf("\nElemento %d encontrado! \n", Q->info);
    } else {
        printf("\nElemento nao encontrado! \n\n");
    }

    printf("Removendo um valor da Lista! \n");
    L = remover(L, 10);

    printf("Imprimindo a Lista... \n\n");
    imprimir(L);

    libera(L);

    return 0;
}