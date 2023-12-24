#include "funcoes/headers.h"
#include <stdio.h>

int main() {
  int escolha;
  printf("Bem-vindo ao SGBD ITP!\nO que deseja fazer?");

  do {
    printf("\n0- Sair\n"
           "1- Criar tabela\n"
           "2- Listar tabelas\n"
           "3- Apagar tabela\n"
           "4- Listar dados da tabela\n"
           "5- Criar uma nova tupla na tabela\n"
           "6- Apagar tupla de uma tabela\n"
           "7- Pesquisar valor em uma tabela\n");

    printf("\nO que deseja fazer? ");
    while (scanf("%d", &escolha) != 1) {

      printf("Entrada inválida.\n");
      while (getchar() != '\n');
    }

    switch (escolha) {
	    case 1:
	      criarTabela();
	      break;
	    case 2:
	      listarTabela();
	      break;
	    case 3:
	      apagarTabela();
	      break;
	    case 4:
	      listarDados();
	      break;
	    case 5:
	      criarTupla();
	      break;
	    case 6:
	      apagarTupla();
	      break;
	    case 7:
	      pesquisarTabela();
	      break;
	    case 0:
	      break;
	    }
  } while (escolha != 0);

  return 0;
}
