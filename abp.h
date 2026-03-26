#ifndef ABP_H
#define ABP_H

typedef struct NodoABP {
    char nome[100];
    float horas;
    struct NodoABP *esquerda;
    struct NodoABP *direita;
} NodoABP;

typedef struct ABP{
    NodoABP* raiz;
    int comp;
    int nodos;
} ABP;

ABP* inserirABP(ABP* arvore, char* nome, float horas);
ABP* criarABP();
NodoABP* insereNodoABP(NodoABP *raiz, char* nome, float horas, ABP* arvore2);
NodoABP* Maior(NodoABP *raiz);
int contaNodos(NodoABP* raiz, int cont);
void imprimePorNivel (NodoABP* raiz, int prf);
void printABP(ABP *arvore);
void printABP_rec(NodoABP *raiz, int nivel);
int alturaABP(NodoABP* raiz);
#endif
