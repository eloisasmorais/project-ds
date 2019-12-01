#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cadastro.h"

int main() {
  setlocale(LC_ALL,"Portuguese");
  int opc, inseriu, estaVazia, tamanhoLista;
  Lista *li;
  CLIENTE dados;

  li = cria_lista();

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
      estaVazia = lista_vazia(li);
      if (!estaVazia) {
        printf("****** Relatório Total - Contatos ******\n");
        exibeRelatorioTotal(li);
      } else {
        system("clear");
        exibeErro();
      }
    } else if (opc == 3) { //Relatório individual por código
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          exibeRelatorioCod();
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 4) { //Relatório individual por nome
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          exibeRelatorioNome();
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 5) { //Edição de contato por código
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          editaContato();
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 6) { //Remoção de contato por código
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          removeContato();
        } else {
          system("clear");
          exibeErro();
        }
    } else if (opc == 7) {//Encerra programa
        printf("Encerrando o programa...\n\n");
        return 0;
    }

    sleep(2);
    opc = exibeMenu();
  }
  return 0;
}