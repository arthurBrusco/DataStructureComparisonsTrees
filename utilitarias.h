#ifndef UTILITARIAS_H
#define UTILITARIAS_H
#include "abp.h"
#include "avl.h"
#include <string.h>
AVL* moveArqAVL(char nomeArquivo[]);
NodoAVL* consulta(AVL *a, char *chave);
ABP* moveArqABP(char nomeArquivo[]);
NodoABP* consultaABP(ABP *arvore2, char *chave);
int strCmpLower(const char* str1, const char* str2);
#endif