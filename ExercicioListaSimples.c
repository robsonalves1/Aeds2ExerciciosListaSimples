#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elementos[MAX];
    int ultimo;
} LISTA;

LISTA *cria() {
    LISTA *l = malloc(sizeof(LISTA));

    if (!l) {
        perror(NULL);
        exit(1);
    }

    l->ultimo = 0;
}

// 1.2
int estaCheia(LISTA *l) {
    return l->ultimo == MAX;
}

// 1.2
int estaVazia(LISTA *l) {
    return l->ultimo == 0;
}

void inserePosicao(LISTA *l, int posicao, int elem) {
    if (estaCheia(l)) {
        printf("Fila Cheia");
        exit(1);
    }

    for (int i = l->ultimo; i > posicao; i--) {
        l->elementos[i] = l->elementos[i - 1];
    }

    l->elementos[posicao] = elem;
    l->ultimo++;
}

// 1.2
void insereFinal(LISTA *l, int elem) {
    if (estaCheia(l)) {
        printf("Fila Cheia");
        exit(1);
    }

    l->elementos[l->ultimo] = elem;
    l->ultimo++;
}

int removePosicao(LISTA *l, int posicao) {
    if (estaVazia(l)) {
        printf("Fila vazia");
        exit(1);
    }

    int removido = l->elementos[posicao];

    for (int i = posicao; i < l->ultimo - 1; i++) {
        l->elementos[i] = l->elementos[i + 1];
    }

    l->ultimo--;

    return removido;
}


void destroi(LISTA *l) {
    free(l);
}

int tamanho(LISTA *l) {
    return l->ultimo;
}

// 1.1
void recupera(LISTA *l) {
    while (tamanho(l) > 0) {
        printf("%d \n", removePosicao(l, l->ultimo - 1));
    }
}

// 1.3
void imprime(LISTA *l) {
    while (tamanho(l) > 0) {
        printf("%d ", removePosicao(l, 0));
    }
}

int main() {
    LISTA *l = cria();

    insereFinal(l, 3);
    insereFinal(l, 7);
    insereFinal(l, 1);
    insereFinal(l, 9);

    recupera(l);

    destroi(l);

    return 1;
}