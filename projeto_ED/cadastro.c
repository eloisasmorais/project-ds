#include<stdio.h>
#include<stdlib.h>
#include"cadastro.h"

struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    CLIENTE dados;
};

typedef struct elemento Elem;

//FUNÇÕES LISTA 
Lista *cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int lista_vazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

//Inserir cliente
int inserirCliente(Lista *li, CLIENTE cli){
  if(li == NULL){
      return 0;
  }
  Elem *no = (Elem*) malloc(sizeof(Elem));
  if(no == NULL){
      return 0;
  }
  no->dados = cli;
  if(lista_vazia(li)){
      no->prox = NULL;
      no->ant = NULL;
      *li = no;
      return 1;
  } else {
    Elem *anterior, *atual = *li;
    while(atual != NULL && atual->dados.codigo < cli.codigo){
        anterior = atual;
        atual = atual->prox;
    }
    
    if(atual == *li){
      no->ant = NULL;
      (*li)->ant = no;
      no->prox = (*li);
      *li = no;
    } else {
        no->prox = anterior->prox;
        no->ant = anterior;
        anterior->prox = no;
        if(atual != NULL) {
          atual->ant = no;
        }
    }
  }

  return 1;
}

// FUNÇÕES MAIN 
//Exibe Menu
int exibeMenu() {
  int opc;
  int tentativa = 0;
  while(opc < 1 || opc > 7){
    printf("1 - Inserir novo contato\n");
    printf("2 - Gerar e exibir relatório de contatos em forma de lista total\n");
    printf("3 - Gerar e exibir relatório individual com busca por identificador\n");
    printf("4 - Gerar e exibir relatório com busca por nome\n");
    printf("5 - Edição do contato através de um identificador\n");
    printf("6 - Remover contato através de um identificador\n");
    printf("7 - Encerrar o programa\n\n");

    if (tentativa) {
      printf("Opção não encontrada, digite novamente: ");
    } else {
      printf("Escolha uma opção: ");
    }
    tentativa++;

    scanf("%d",&opc);
  }

  return opc;
}

void exibeErro() {
  printf("\n\nLista não preenchida, nada a ser exibido...\n\n");
}

//Funções de manipulação de arquivos
void exibeRelatorioTotal() {
  printf("****** Relatório Total - Contatos ******\n");

  printf("Saindo case 2\n");
}

void exibeRelatorioCod() {
  printf("Relatório por código!\n");
}

void exibeRelatorioNome() {
  printf("Relatório por nome!\n");
}

void editaContato() {
  printf("Edição de contato\n\n");
}

void removeContato() {
  printf("Remoção de contato\n\n");
}

CLIENTE recebeDados() {
  CLIENTE dados;

  printf("Informe o código do funcionário:\n");
  scanf("%d",&dados.codigo);
  printf("Informe o nome:\n");
  getchar();
  fgets(dados.nome, 29, stdin);
  printf("Informe a Empresa:\n");
  getchar();
  fgets(dados.empresa,19,stdin);
  printf("Informe o departamento:\n");
  getchar();
  fgets(dados.departamento,19,stdin);
  printf("Informe o telefone:\n");
  getchar();
  fgets(dados.telefone,19,stdin);
  printf("Informe o celular:\n");
  getchar();
  fgets(dados.celular,19,stdin);
  printf("Informe o email:\n");
  getchar();
  fgets(dados.email,29,stdin);

  return dados;
}