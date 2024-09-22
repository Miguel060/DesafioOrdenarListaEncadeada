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

void ordenarPares(le *ld, par *lp) {
    le *aux = ld->prox;
    le *aux2 = aux->prox;
    while (aux->prox != NULL) {
        if (aux->valor == aux2->valor) {
            inserirPar(lp, aux->valor, aux2->valor);
            aux->valor = 0;
            aux2->valor = 0;
            aux = aux->prox;
            aux2 = aux->prox;
        } else {
            if (aux2->prox != NULL) {
                aux2 = aux2->prox;
            } else {
                aux = aux->prox;
                aux2 = aux->prox;
            }
        }
    }
}

void imprimirPares(par *lp) {
    par *aux;
    aux = lp;
    int cont = 0;
    printf("PARES:\n");
    while (aux != NULL) {
        if (aux->valor1 != 0) {
            printf("(%d,%d) ", aux->valor1, aux->valor2);
            cont++;
        }
        aux = aux->prox;
    }
    printf("\n%d Pares", cont);
    printf("\n");
}

void imprimirLista(le *ld) {
    le *aux;
    aux = ld->prox;
    while (aux != NULL) {
        printf("Valor:%d ", aux->valor);
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
    ordenarPares(ld, lp);
    imprimirPares(lp);

    free(ld);
    return 0;
}
