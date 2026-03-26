#include "abp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitarias.h"

ABP* criarABP() {
    ABP* novaABP = (ABP*)malloc(sizeof(ABP));
    novaABP->raiz = NULL;
    novaABP->comp = 0;
    novaABP->nodos = 0;
    return novaABP;
}

ABP* inserirABP(ABP* arvore2, char* nome, float horas) {
    arvore2->nodos++;
    arvore2->raiz = insereNodoABP(arvore2->raiz, nome, horas, arvore2);
    return arvore2;
}

NodoABP* insereNodoABP(NodoABP *raiz, char* nome, float horas, ABP* arvore2) {
    if (raiz == NULL) { //caso a arvore esteja vazia
        NodoABP* novo = (NodoABP*)malloc(sizeof(NodoABP));
        strcpy(novo->nome, nome);
        novo->horas = horas;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    if (strCmpLower(nome, raiz->nome) < 0) {
        raiz->esquerda = insereNodoABP(raiz->esquerda, nome, horas, arvore2);
    }
    else if (strCmpLower(nome, raiz->nome) > 0) {
        raiz->direita = insereNodoABP(raiz->direita, nome, horas, arvore2);
    }
    else {
        return raiz; // nomes iguais == não insere
    }
    return raiz; 
}


NodoABP* Maior(NodoABP* raiz) {
    if(raiz != NULL )
        while( raiz->direita != NULL )
            raiz = raiz->direita;
    return raiz;
}

int contaNodos(NodoABP* raiz, int cont) {
    if (raiz != NULL) {
        cont++;
        contaNodos(raiz->esquerda, cont);
        contaNodos(raiz->direita, cont);
    }
    return cont;
}

void imprimePorNivel (NodoABP* raiz, int prf) {
    prf++;
    if (raiz != NULL ) {
        for (int j=0; j < prf; j++) {
            printf("=");
        }
        printf("[%s | %.2f h]\n", raiz->nome, raiz->horas);
        imprimePorNivel(raiz->esquerda, prf);
        imprimePorNivel (raiz->direita, prf);
    }
}


void printABP(ABP *arvore) {
    printf("\n===== ÁRVORE ABP =====\n");
    imprimePorNivel(arvore->raiz, 0);
    printf("=======================\n");
}

int alturaABP(NodoABP* raiz) {
    if (raiz == NULL)
        return -1;
    int e = alturaABP(raiz->esquerda);
    int d = alturaABP(raiz->direita);
    return (e > d ? e : d) + 1;
}
