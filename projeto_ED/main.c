#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cadastro.h"

int main() {
  setlocale(LC_ALL,"Portuguese");
  int opc, inseriu, estaVazia, tamanhoLista, encontrou;
  Lista *li;
  CLIENTE dados;

  li = criaLista();

  printf("****** Lista de Contatos ******\n");
  opc = exibeMenu();

  while(opc) {
    if (opc == 1) {
      dados = recebeDados();
      inseriu = inserirCliente(li, dados);
      if (inseriu) {
        printf("Cadastro realizado com sucesso!\n");
      } else {
        system("clear");
        printf("Erro ao realizar o cadastro!\n");
      }
    } else if (opc ==2 ) { //Relatório geral
      estaVazia = listaVazia(li);
      if (!estaVazia) {
        printf("****** Relatório Total - Contatos ******\n");
        exibeRelatorioTotal(li);
      } else {
        system("clear");
        exibeErro();
      }
    } else if (opc == 3) { //Relatório individual por código
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          int codigo;
          CLIENTE cli;
          printf("Digite o código do cliente: ");
          scanf("%d", &codigo);
          encontrou = buscaCliCod(li, codigo, &cli);
          if (encontrou) {
            exibeCli(&cli);
          } else {
            printf("Nenhum cliente encontrado!\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 4) { //Relatório individual por nome
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          char nome[31];
          CLIENTE cli;
          printf("Digite o nome: ");
          getchar();
          fgets(nome, 31, stdin);
          nome[strlen(nome)-1]='\0';

          encontrou = buscaCliNome(li, nome, &cli);
          if (encontrou){
            exibeCli(&cli);
          } else {
            printf("Nenhum cliente encontrado!\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 5) { //Edição de contato por código
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          int codigo;
          printf("Digite o código do cliente a ser editado: ");
          scanf("%d", &codigo);
          encontrou = editaContato(li, codigo);
          if (encontrou) {
            printf("Cliente editado com sucesso!\n");
          } else {
            printf("Não foi possível editar, cliente não encontrado.\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 6) { //Remoção de contato por código
        estaVazia = listaVazia(li);
        if(!estaVazia) {
          int codigo;
          printf("Digite o código do cliente a ser removido: ");
          scanf("%d", &codigo);
          encontrou = removeContato(li, codigo);
          if (encontrou) {
            printf("Cliente removido com sucesso!\n");
          } else {
            printf("Não foi possível remover, cliente não encontrado.\n");
          }
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 7) {//Encerra programa
      printf("Encerrando o programa...\n\n");
      destroiLista(li);
      return 0;
    }

    int l = 0;
    printf("Aperte 1 para voltar ao menu: ");
    scanf("%d", &l);
    if (l) {
      opc = exibeMenu(); 
    }
  }
}