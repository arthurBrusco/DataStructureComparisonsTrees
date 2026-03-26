#include <stdio.h>
#include <stdlib.h>
#include "utilitarias.h"
#include "avl.h"
#include "abp.h"


int main(int argc, char *argv[]) {
    float tempo=0, tempo2=0;

    if (argc != 4) {
        printf("erro nos argumentos\n");
        return 1;
    }
    AVL* arvore = criarAVL();
    arvore= moveArqAVL(argv[1]);
    
    ABP* arvore2 = criarABP();
    arvore2 = moveArqABP(argv[1]);
    
    FILE *arq = fopen(argv[2], "r");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return 1;
    }   
    char linha[200];
    NodoAVL *resultado = NULL;
    NodoABP *resultadoABP = NULL;
    int numAvl=0, numAbp=0;
    
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        
        linha[strcspn(linha, "\n")] = '\0';
        
        resultado = consulta(arvore, linha);
        if (resultado != NULL) {
            //printf("AcheiAVL %s: %.2f horas\n", linha, resultado->horas);
            tempo += resultado->horas;
            numAvl++;
        }
        resultadoABP = consultaABP(arvore2, linha);
        
        if (resultadoABP != NULL)
        {
            //printf("AcheiABP %s: %.2f horas\n", linha, resultado->horas);
            tempo2 += resultadoABP->horas;
            numAbp++;
        }
    }
    
    fclose(arq);
    
    FILE *saida = fopen(argv[3], "w");
    if(saida == NULL) {
        printf("Erro ao abrir o arquivo de saida.\n");
        return 1;
    }
    
    
    
    //printAVL(arvore);
    fprintf(saida,"\n============AVL============\n");
    fprintf(saida,"Tempo total de jogo do jogador 1: %.2f horas\n", tempo);
    fprintf(saida,"Numero de comparacoes: %d\n", arvore->comp);
    fprintf(saida,"Altura da arvore AVL: %d\n", alturaAVL(arvore->raiz));
    fprintf(saida,"Numero de rotacoes: %d\n", arvore->rotacoes);
    fprintf(saida,"Numero de nodos: %d\n", arvore->nodos);

    //printABP(arvore2);
    fprintf(saida,"\n============ABP============\n");
    fprintf(saida,"Tempo total de jogo do jogador 2: %.2f horas\n", tempo2);
    fprintf(saida,"Numero de comparacoes: %d\n", arvore2->comp);
    fprintf(saida, "Altura da arvore ABP: %d\n", alturaABP(arvore2->raiz));
    fprintf(saida, "Numero de nodos: %d\n", arvore2->nodos);
    fclose(saida);
    return 0;
}
    