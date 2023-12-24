#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers.h"

void listarTabela() {
    FILE *arquivo;
    char l[100], nome[50];
    int chave;
    
    arquivo = fopen("projeto.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao buscar tabela.\n");
        exit(1);
    }

    printf("Lista de tabelas:\n");
    
    while (fgets(l, sizeof(l), arquivo) != NULL) {
        if (strstr(l, "Nome da tabela:") != NULL) {
            sscanf(l, "Nome da tabela: %s", nome);
            printf("- %s\n", nome);
        }
    }
    if (strstr(l, "Nome da tabela:") != NULL) {

    }
    fclose(arquivo);
}
