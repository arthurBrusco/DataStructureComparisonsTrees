#ifndef AVL_H
#define AVL_H

typedef struct NodoAVL {
    char nome[100];
    float horas;
    struct NodoAVL *esquerda;
    struct NodoAVL *direita; 
    int FB;
} NodoAVL;

typedef struct AVL{
    NodoAVL* raiz;
    int rotacoes;
    int comp;
    int nodos;
} AVL;
AVL* inserirAVL(AVL* arvore, char* nome, float horas);
AVL* criarAVL();
int alturaAVL(NodoAVL* raiz);
NodoAVL* inserirNodo(NodoAVL* raiz, char* nome, float horas, AVL* arvore);
int fatorBalanceamento(NodoAVL* raiz);
NodoAVL* rotacaoSimplesDireita(NodoAVL* y);
NodoAVL* rotacaoSimplesEsquerda(NodoAVL* x);
NodoAVL* rotacaoDuplaDireita(NodoAVL* raiz);
NodoAVL* rotacaoDuplaEsquerda(NodoAVL* raiz);
void printAVL(AVL *arvore);
void printAVL_rec(NodoAVL *raiz, int nivel);
#endif 