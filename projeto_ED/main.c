#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cadastro.h"

int main() {
  setlocale(LC_ALL,"Portuguese");
  int opc, estaVazia, tamanho;
  Lista *li = NULL;
  CLIENTE dados;

  li = criaLista();
  // FILE *arq = fopen("clientes.txt", "a+b");
  // if (arq == NULL) {
  //   printf("Erro ao abrir arquivo\n");
  //   return 0;
  // }
  /* Menu */
  printf("****** Lista de Contatos ******\n");
  opc = exibeMenu();

  FILE *arq = fopen("clientes.txt", "rb");
  if (arq != NULL) {
    leLista(arq, li);
  }

  while(opc) {
    if (opc == 1) {
      dados = recebeDados();
      int inseriu = inserirCliente(li, dados);
      int gravou = gravaArquivo(arq, li);
      if (gravou) {
        printf("Dados gravados com sucesso!\n");
      } else {
        printf("Erro ao gravar dados.\n");
      }
      if (inseriu) {
        printf("Cadastro realizado com sucesso!\n");
      } else {
        system("clear");
        printf("Erro ao realizar o cadastro!\n");
      }
      fclose(arq);
    } else if (opc == 2) { //Relatório geral
      FILE *arq = fopen("clientes.txt", "rb");
      if (arq == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 0;
      }
      leLista(arq, li);
      estaVazia = listaVazia(li);
      if (!estaVazia) {
        printf("****** Relatório Total - Contatos ******\n");
        exibeRelatorioTotal(li);
      } else {
        system("clear");
        exibeErro();
      }
      fclose(arq);
    } else if (opc == 3) { //Relatório individual por código
        FILE *arq = fopen("clientes.txt", "rb");
        if (arq == NULL) {
          printf("Erro ao abrir arquivo\n");
          return 0;
        }
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          int codigo;
          CLIENTE cli;
          printf("Digite o código do cliente: ");
          scanf("%d", &codigo);
          int encontrou = buscaCliCod(li, codigo, &cli);
          if (encontrou) {
            exibeCli(&cli);
          } else {
            printf("Nenhum cliente encontrado!\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
        fclose(arq);
    } else if (opc == 4) { //Relatório individual por nome
        FILE *arq = fopen("clientes.txt", "rb");
        if (arq == NULL) {
          printf("Erro ao abrir arquivo\n");
          return 0;
        }
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          char nome[31];
          CLIENTE cli;
          printf("Digite o nome: ");
          getchar();
          fgets(nome, 31, stdin);
          nome[strlen(nome)-1]='\0';

          int encontrou = buscaCliNome(li, nome, &cli);
          if (encontrou){
            exibeCli(&cli);
          } else {
            printf("Nenhum cliente encontrado!\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
        fclose(arq);
    } else if (opc == 5) { //Edição de contato por código
        FILE *arq = fopen("clientes.txt", "r+b");
        if (arq == NULL) {
          printf("Erro ao abrir arquivo\n");
          return 0;
        }
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          int codigo;
          printf("Digite o código do cliente a ser editado: ");
          scanf("%d", &codigo);
          int encontrou = editaContato(li, codigo);
          if (encontrou) {
            printf("Cliente editado com sucesso!\n");
          } else {
            printf("Não foi possível editar, cliente não encontrado.\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
        fclose(arq);
    } else if (opc == 6) { //Remoção de contato por código
        FILE *arq = fopen("clientes.txt", "r+b");
        if (arq == NULL) {
          printf("Erro ao abrir arquivo\n");
          return 0;
        }
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          int codigo;
          printf("Digite o código do cliente a ser removido: ");
          scanf("%d", &codigo);
          int encontrou = removeContato(li, codigo);
          if (encontrou) {
            printf("Cliente removido com sucesso!\n");
          } else {
            printf("Não foi possível remover, cliente não encontrado.\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
        fclose(arq);
    } else if (opc == 7) {//Encerra programa
      printf("Encerrando o programa...\n\n");
      destroiLista(li);
      return 0;
    }

    exibeMenu(); 
  }
}