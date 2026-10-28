#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elementos[MAX];
    int ultimo;
} LISTA;

LISTA *cria() {
    LISTA *l = malloc(sizeof(MAX));

    if (!l) {
        perror(NULL);
        exit(1);
    }

    l->ultimo = 0;
}

int estaCheia(LISTA *l) {
    return l->ultimo == MAX;
}

int estaVazia(LISTA *l) {
    return l->ultimo == 0;
}

void inserePosicao(LISTA *l, int posicao, int elem) {
    if (estaCheia(l)) {
        printf("Lista Cheia");
        exit(1);
    }

    for (int i = l->ultimo; i > posicao; i--) {
        l->elementos[i] = l->elementos[i - 1];
    }

    l->elementos[posicao] = elem;
    l->ultimo++;
}

void insereFim(LISTA *l, int elem) {
    if (estaCheia(l)) {
        printf("Lista Cheia");
        exit(1);
    }

    l->elementos[l->ultimo] = elem;
    l->ultimo++;
}

int removePosicao(LISTA *l, int posicao) {
    if (estaVazia(l)) {
        printf("Lista vazia");
        exit(1);
    }

    int removido = l->elementos[posicao];

    for (int i = posicao; i < l->ultimo; i++) {
        l->elementos[i] = l->elementos[i + 1];
    }

    l->ultimo--;

    return removido;
}

void destroi(LISTA *l) {
    free(l);
}

int main() {

    return 1;
}