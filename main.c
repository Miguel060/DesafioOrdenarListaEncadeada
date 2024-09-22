#include <stdio.h>
#include <stdlib.h>

typedef struct st_no {
    int valor;
    struct st_no *prox;
    struct st_no *ant;
} le;

le *cauda;
int contPares = 0;
int contElementos = 0;
int valor1;
int valor2;

typedef struct st_par {
    int valor1;
    int valor2;
    int contador;
    struct st_par *prox;
    struct st_par *ant;
} par;

void iniciarLista(le *ld) {
    ld->prox = NULL;
}

void iniciarListaPares(par *lp) {
    lp->prox = NULL;
}

int v_vazia(le *ld) {
    if (ld->prox == NULL) {
        return 1;
    }
    return 0;
}

int v_vaziaPares(par *lp) {
    if (lp->prox == NULL) {
        return 1;
    }
    return 0;
}

void inserirFim(le *ld, int valor) {
    le *novo = (le *) malloc(sizeof(le));
    if (!novo) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->valor = valor;
    if (v_vazia(ld)) {
        ld->prox = novo;
        novo->prox = NULL;
        novo->ant = NULL;
    } else {
        le *aux;
        aux = ld->prox;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        novo->prox = NULL;
    }
    cauda = novo;
}

void inserirPar(par *lp, int valor1, int valor2) {
    par *novo = (par *) malloc(sizeof(par));
    if (!novo) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    par *aux;
    if (v_vaziaPares(lp)) {
        lp->prox = novo;
        novo->valor1 = valor1;
        novo->valor2 = valor2;
        novo->prox = NULL;
        novo->ant = NULL;
    } else {
        aux = lp->prox;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        novo->valor1 = valor1;
        novo->valor2 = valor2;
        novo->prox = NULL;
    }
}

void ordenarPares(par *lp) {
    le *aux = cauda;
    le *aux2 = cauda->ant;
    do {
        valor1 = aux->valor;
        valor2 = aux2->valor;
        if(valor1==valor2) {
            inserirPar(lp, valor1, valor2);
            aux2 = aux2->ant;
        }else {
            aux = aux->ant;
        }
    }while(aux2->ant != NULL);
}

void imprimir(par *lp) {
    par *aux;
    aux = lp;
    while (aux != NULL) {
        printf("Valor: %d,%d\n", aux->valor1, aux->valor2);
        aux = aux->prox;
    }
    printf("\n");
}


int main(void) {
    le *ld = (le *) malloc(sizeof(le));
    par *lp = (par *) malloc(sizeof(par));
    if (!lp) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    if (!ld) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    iniciarLista(ld);
    iniciarListaPares(lp);
    inserirFim(ld, 10);
    inserirFim(ld, 20);
    inserirFim(ld, 20);
    inserirFim(ld, 10);
    inserirFim(ld, 10);
    inserirFim(ld, 30);
    inserirFim(ld, 50);
    inserirFim(ld, 10);
    inserirFim(ld, 20);
    ordenarPares(lp);
    imprimir(lp);

    free(ld);
    return 0;
}
