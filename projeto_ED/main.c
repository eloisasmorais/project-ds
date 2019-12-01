#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cadastro.h"

int main() {
  setlocale(LC_ALL,"Portuguese");
  int opc, inseriu, estaVazia;
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
        printf("Erro ao realizar o cadastro!\n");
      }
    } else if (opc ==2 ) { //Relatório geral
      estaVazia = lista_vazia(li);
      if (!estaVazia) {
        exibeRelatorioTotal();
      } else {
        exibeErro();
      }
    } else if (opc == 3) { //Relatório individual por código
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          exibeRelatorioCod();
        } else {
          exibeErro();
        }
    } else if (opc == 4) { //Relatório individual por nome
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          exibeRelatorioNome();
        } else {
          exibeErro();
        }
    } else if (opc == 5) { //Edição de contato por código
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          editaContato();
        } else {
          exibeErro();
        }
    } else if (opc == 6) { //Remoção de contato por código
        estaVazia = lista_vazia(li);
        if(!estaVazia) {
          removeContato();
        } else {
          exibeErro();
        }
    } else if (opc == 7) {//Encerra programa
        printf("Encerrando o programa...\n\n");
        return 0;
    }

    sleep(2);
    system("clear");
    opc = exibeMenu();
  }
  return 0;
}