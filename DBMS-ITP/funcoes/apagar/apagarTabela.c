#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers.h"

void apagarTabela() {
    int aux = 0;
    char nome[50];
    printf("Nome da tabela a ser apagada: ");
    scanf("%s", nome);

    FILE *arquivo, *tempFile;
    char linha[100];
    arquivo = fopen("projeto.txt", "r");
    tempFile = fopen("tempFile.txt", "w");
   
    if (arquivo == NULL || tempFile == NULL) {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, nome) != NULL) {
            aux = 1;
            continue;
        }
        fputs(linha, tempFile);
    }
    fclose(arquivo); 
    fclose(tempFile);

    if (!aux) {
        printf("Tabela '%s' nao encontrada.\n", nome);
        remove("tempFile.txt"); 
    } else {
        remove("projeto.txt");
        rename("tempFile.txt", "projeto.txt");
        printf("'%s' apagado(a) com sucesso.\n", nome);
    }
}