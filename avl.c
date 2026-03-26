#include "avl.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "utilitarias.h"
AVL* inserirAVL(AVL* arvore, char* nome, float horas) {
    arvore->nodos++;
    arvore->raiz = inserirNodo(arvore->raiz, nome, horas, arvore);
    return arvore;
}


NodoAVL* inserirNodo(NodoAVL* raiz, char* nome, float horas, AVL* arvore) {

    if (raiz == NULL) {
        NodoAVL* novo = (NodoAVL*)malloc(sizeof(NodoAVL));
        strcpy(novo->nome, nome);
        novo->horas = horas;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->FB = 0;
        
        return novo;
    }

    

    if (strCmpLower(nome, raiz->nome) < 0) {
        raiz->esquerda = inserirNodo(raiz->esquerda, nome, horas, arvore);
    }
    else if (strCmpLower(nome, raiz->nome) > 0) {
        raiz->direita = inserirNodo(raiz->direita, nome, horas, arvore);
    }
    else {
        return raiz; // nomes iguais não insere
    }

    // Atualiza fator de balanceamento
    raiz->FB = fatorBalanceamento(raiz);

    // Caso direita pesada
    if (raiz->FB < -1) {
        if (fatorBalanceamento(raiz->direita) <= 0) {
            arvore->rotacoes++;
            return rotacaoSimplesEsquerda(raiz);
        } else {
            arvore->rotacoes++;
            return rotacaoDuplaEsquerda(raiz);
        }
    }

    // Caso esquerda pesada
    if (raiz->FB > 1) {
        if (fatorBalanceamento(raiz->esquerda) >= 0) {
            arvore->rotacoes++;
            return rotacaoSimplesDireita(raiz);
        } else {
            arvore->rotacoes++;
            return rotacaoDuplaDireita(raiz);
        }
    }
    
    return raiz;
}


int alturaAVL(NodoAVL* raiz) {
    if (raiz == NULL)
        return -1;
    int e = alturaAVL(raiz->esquerda);
    int d = alturaAVL(raiz->direita);
    return (e > d ? e : d) + 1;
}

int fatorBalanceamento(NodoAVL* raiz) {
    if (raiz == NULL) return 0;
    return alturaAVL(raiz->esquerda) - alturaAVL(raiz->direita);
}


NodoAVL* rotacaoSimplesDireita(NodoAVL* y) {
    NodoAVL* x = y->esquerda;
    NodoAVL* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->FB = fatorBalanceamento(y);
    x->FB = fatorBalanceamento(x);

    return x;
}

NodoAVL* rotacaoSimplesEsquerda(NodoAVL* x) {
    NodoAVL* y = x->direita;
    NodoAVL* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->FB = fatorBalanceamento(x);
    y->FB = fatorBalanceamento(y);

    return y;
}

NodoAVL* rotacaoDuplaDireita(NodoAVL* raiz) {
    raiz->esquerda = rotacaoSimplesEsquerda(raiz->esquerda);
    return rotacaoSimplesDireita(raiz);
}

NodoAVL* rotacaoDuplaEsquerda(NodoAVL* raiz) {
    raiz->direita = rotacaoSimplesDireita(raiz->direita);
    return rotacaoSimplesEsquerda(raiz);
}


AVL* criarAVL() {
    AVL* novaAVL = (AVL*)malloc(sizeof(AVL));
    novaAVL->raiz = NULL;
    novaAVL->rotacoes = 0;
    novaAVL->comp = 0;
    novaAVL->nodos = 0;
    return novaAVL;
}
void printAVL_rec(NodoAVL *raiz, int nivel) {
    if (raiz == NULL)
        return;

    // imprime primeiro a subárvore direita (vai para o topo)
    printAVL_rec(raiz->direita, nivel + 1);

    // imprime o nó atual indentado
    for (int i = 0; i < nivel; i++)
        printf("    ");  // 4 espaços por nível

    printf("[%s | %.2f h | FB=%d]\n", raiz->nome, raiz->horas, raiz->FB);

    // imprime a subárvore esquerda (fica embaixo)
    printAVL_rec(raiz->esquerda, nivel + 1);
}

void printAVL(AVL *arvore) {
    printf("\n===== ÁRVORE AVL =====\n");
    printAVL_rec(arvore->raiz, 0);
    printf("=======================\n");
}