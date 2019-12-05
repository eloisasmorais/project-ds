#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cadastro.h"

int main() {
  setlocale(LC_ALL,"Portuguese");
  int opc, estaVazia, gravou, leu, inseriu;
  Lista *li = NULL;
  CLIENTE dados;

  li = criaLista();
  FILE *arq;
  arq = fopen("clientes.txt", "rb");
  if (arq == NULL) {
    arq = fopen("clientes.txt", "w+b");
  } else {
    leu = leArquivo(li);
    fclose(arq);
  }
  if (!leu) {
    printf("Erro ao ler arquivo.\n");
    return 0;
  } else {
    opc = exibeMenu();
  }

  while(opc) {
    if (opc == 1) {
      dados = recebeDados(0, 0);
      inseriu = inserirCliente(li, dados);
      gravou = gravaArquivo(li);

      if (inseriu && gravou) {
        printf("\nCliente armazenado com sucesso!\n\n");
      } else {
        printf("\nErro ao armazenar cliente\n\n");
      }
    } else if (opc == 2) { //Relatório geral
      estaVazia = listaVazia(li);
      if (!estaVazia) {
        printf("\n****** Relatório Total - Clientes ******\n");
        exibeRelatorioTotal(li);
      } else {
        exibeErro();
      }
    } else if (opc == 3) { //Relatório individual por código
      estaVazia = listaVazia(li);
      if(!estaVazia) {
        int codigo;
        CLIENTE cli;
        printf("Digite o código desejado: ");
        scanf("%d", &codigo);
        int encontrou = buscaCliCod(li, codigo, &cli);
        if (encontrou) {
          exibeClientes(cli);
        } else {
          printf("Nenhum cliente encontrado!\n");
        }
      }
    } else if (opc == 4) { //Relatório individual por nome
      estaVazia = listaVazia(li);
      if(!estaVazia) {
        char nome[31];
        printf("Digite o nome desejado: ");
        getchar();
        fgets(nome, 31, stdin);
        nome[strlen(nome)-1]='\0';
        int encontrou = buscaCliNome(li, nome);
        if (!encontrou) {
          printf("Cliente não encontrado!");
        }
      } 
    } else if (opc == 5) { //Edição de contato por código
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          int codigo;
          printf("Digite o código do cliente a ser editado: ");
          scanf("%d", &codigo);
          int encontrou = editaContato(li, codigo);
          if (encontrou) {
            printf("Cliente editado com sucesso!\n");
            gravou = gravaArquivo(li);
          } else {
            printf("Não foi possível editar, cliente não encontrado.\n");
          }
        }
    } else if (opc == 6) { //Remoção de contato por código
      estaVazia = listaVazia(li);
      if(!estaVazia) {
        int codigo;
        printf("Digite o código do cliente a ser removido: ");
        scanf("%d", &codigo);
        int encontrou = removeContato(li, codigo);
        if (encontrou) {
          printf("Cliente apagado com sucesso!\n");
          gravou = gravaArquivo(li);
          if (!gravou) {
            printf("Falha ao gravar no arquivo!\n");
          } else {
          }
        }
      }
    } else if (opc == 7) {//Encerra programa
      printf("Encerrando o programa...\n\n");
      estaVazia = listaVazia(li);
       if (!estaVazia) {
        destroiLista(li);
        return 0;
      } else {
        return 0;
      }
    }

   opc = exibeMenu();
  }
}
