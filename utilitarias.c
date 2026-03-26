#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utilitarias.h"



AVL* moveArqAVL(char nomeArquivo[]) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }
    
    char linha[200];
    AVL *arvore = criarAVL();

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        
        linha[strcspn(linha, "\n")] ='\0'; // remove '\n'

        // separa nome e horas
        char *nome = strtok(linha, ",");
        char *horasStr = strtok(NULL, "\0");

        

        
        float horas = atof(horasStr); // converte string -> float
        //printf("Nome: %s, Horas: %.2f\n", nome, horas); 
        
        arvore= inserirAVL(arvore, nome, horas); 
    }


    fclose(arq);
    return arvore;
}

ABP* moveArqABP(char nomeArquivo[]) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }
    
    char linha[200];
    ABP* arvore2 = criarABP();
    
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        
        linha[strcspn(linha, "\n")] ='\0'; // remove '\n'
        
        // separa nome e horas
        char *nome = strtok(linha, ",");
        char *horasStr = strtok(NULL, "\0");
        
        float horas = atof(horasStr); // converte string -> float 
        
        arvore2 = inserirABP(arvore2, nome, horas); 
        //printf("entrou na funcao\n");
    }


    fclose(arq);
    return arvore2;
}

NodoAVL* consulta(AVL *a, char *chave) {
    NodoAVL *atual = a->raiz;

    while (atual != NULL) {
        a->comp++;
        
        int cmp = strCmpLower(chave, atual->nome);
        
        if (cmp == 0) {

            return atual; // achou
        }
        else if (cmp < 0) {
            atual = atual->esquerda;
        }
        else if (cmp > 0) {
            atual = atual->direita;
        }
    }

    return NULL; // nao encontrado
}

NodoABP* consultaABP(ABP *arvore2, char *chave) {
    NodoABP *atual = arvore2->raiz;

    while (atual != NULL) {
        arvore2->comp++;
        
        int cmp = strCmpLower(chave, atual->nome);

        if (cmp == 0) {

            return atual; // achou
        }
        else if (cmp < 0) {
            atual = atual->esquerda;
        }
        else if (cmp > 0) {
            atual = atual->direita;
        }
    }

    return NULL; // nao encontrado
}

char* stringToLower(char* s) {
    char* str = malloc(strlen(s) + 1);
    int n = strlen(s);
    for (int i = 0; i<n; i++, str++, s++) {
        *str = tolower(*s);
    }
    return str; // retorna a string em minusculo
                // precisa limpar str
}
int strCmpLower(const char* str1, const char* str2) {
    const char* a = str1;
    const char* b = str2;

    while (*a != 0 && *b != 0) {
        int ca = tolower(*a);
        int cb = tolower(*b);

        if (ca != cb) return ca - cb;

        a++;
        b++;
    }

    return tolower(*a) - tolower(*b);
}