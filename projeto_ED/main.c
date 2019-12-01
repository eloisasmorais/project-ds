#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cadastro.h"

// int main() {
//   setlocale(LC_ALL,"Portuguese");
//   int opc, x;
//   Lista *li;
//   CLIENTE dados;

//   li = cria_lista();

//   printf("****** Lista de Contatos ******\n");

//   opc = exibeMenu();

//   while (opc) {
//     switch(opc){
//       case 1:
        // printf("Informe o código do funcionário:\n");
        // scanf("%d",&dados.codigo);
        // printf("Informe o nome:\n");
        // getchar();
        // fgets(dados.nome, 29, stdin);
        // printf("Informe a Empresa:\n");
        // getchar();
        // fgets(dados.empresa,19,stdin);
        // printf("Informe o departamento:\n");
        // getchar();
        // fgets(dados.departamento,19,stdin);
        // printf("Informe o telefone:\n");
        // getchar();
        // fgets(dados.telefone,19,stdin);
        // printf("Informe o celular:\n");
        // getchar();
        // fgets(dados.celular,19,stdin);
        // printf("Informe o email:\n");
        // getchar();
        // fgets(dados.email,29,stdin);
//         x = inserirCliente(li, dados);
//         if(x){
//           printf("Cadastro realizado com sucesso!\n");
//         }
//         else{
//           printf("Erro ao realizar o cadastro!\n");
//         }
//         break;
//       case 2:
//         exibeRelatorioTotal();
//         break;
//       case 3:
//         printf("opcao 3");
//         break;
//       case 4:
//         printf("opcao 4");
//         break;
//       case 5:
//         printf("opcao 5");
//         break;
//       case 6:
//         printf("opcao 6");
//         break;
//       case 7:
//         printf("Encerrando programa...\n");
//         return 0;
//     }
//     opc = exibeMenu();
//   }
// }

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