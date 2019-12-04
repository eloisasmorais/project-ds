#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    CLIENTE dados;
};

typedef struct elemento Elem;

//FUNÇÕES LISTA
Lista *criaLista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void destroiLista(Lista *li) {
  if (li != NULL) {
    Elem *no;
    while ((*li) != NULL) {
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}
int tamanhoLista (Lista *li) {
  if (li == NULL) {
    return 0;
  }

  int tamanho = 0;
  Elem *no = *li;

  while (no != NULL) {
    tamanho++;
    no = no->prox;
  }

  return tamanho;
}

int listaVazia(Lista *li){
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
  if(listaVazia(li)){
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

void exibeRelatorioTotal(Lista *li) {
  CLIENTE *dados;
  dados = (CLIENTE*) malloc (tamanhoLista(li)* sizeof(CLIENTE));
  Elem *no = *li;
  while (no != NULL) {
    *dados = no->dados;
    printf("\n============= CLIENTE =============\n");
    printf("%d - %s\n", dados->codigo, dados->nome);
    printf("Empresa: %s\n", dados->empresa);
    printf("Departamento: %s\n", dados->departamento);
    printf("Telefone: %s\n", dados->telefone);
    printf("Celular: %s\n", dados->celular);
    printf("Email: %s\n", dados->email);

    no = no->prox;
  }
  free(dados);
}

void exibeClientes(CLIENTE cli) {
    printf("%d - %s\n", cli.codigo,cli.nome);
    printf("Empresa: %s\n", cli.empresa);
    printf("Departamento: %s\n", cli.departamento);
    printf("Telefone: %s\n", cli.telefone);
    printf("Celular: %s\n", cli.celular);
    printf("Email: %s\n", cli.email);
    printf("\n\n");
}

int buscaCliCod (Lista *li, int cod, CLIENTE *cli) {
  Elem *no = *li;
  while (no != NULL && no->dados.codigo != cod) {
    no = no->prox;
  }

  if (no == NULL) {
    return 0;
  } else {
    *cli = no->dados;
    return 1;
  }
}
void buscaCliNome(Lista *li, char *nome) {
  CLIENTE cli;
  Elem *no = *li;

  while (no != NULL) {
    if (strcmp(no->dados.nome, nome) == 0) {
      cli = no->dados;
      exibeClientes(cli);
    }
    no = no->prox;
  }
  if (no == NULL) {
    return;
  }
}

void exibeCli(CLIENTE *cli) {
  printf("\n============= CLIENTE =============\n");
  printf("%d - %s\n", cli->codigo, cli->nome);
  printf("Empresa: %s\n", cli->empresa);
  printf("Departamento: %s\n", cli->departamento);
  printf("Telefone: %s\n", cli->telefone);
  printf("Celular: %s\n", cli->celular);
  printf("Email: %s\n", cli->email);
}

int editaContato(Lista *li, int codigo) {
  printf("Edição de contato\n\n");
  Elem *no = *li;
  while (no != NULL && no->dados.codigo != codigo) {
    no = no->prox;
  }

  if (no == NULL) {
    return 0;
  } else {
      CLIENTE cli = recebeDados();
      no->dados = cli;

      return 1;
  }
}

int removeContato(Lista *li, int codigo) {
  printf("Remoção de contato\n\n");
  if (li == NULL) return 0;

  Elem *no = *li;
  while (no != NULL && no->dados.codigo != codigo) {
    no = no->prox;
  }

  if (no == NULL) {
    return 0;
  }

  if (no->ant == NULL) {
    *li = no->prox;
  } else {
    no->ant->prox = no->prox;
  }

  if (no->prox != NULL) {
    no->prox->ant = no->ant;
  }

  free(no);
  return 1;
}

CLIENTE recebeDados() {
  CLIENTE dados;

  printf("Informe o código do funcionário: ");
  scanf("%d",&dados.codigo);
  getchar();
  printf("Informe o nome: ");
  fgets(dados.nome, 31, stdin);
  dados.nome[strlen(dados.nome)-1]='\0';
  printf("Informe a Empresa: ");
  fgets(dados.empresa,21,stdin);
  dados.empresa[strlen(dados.empresa)-1]='\0';
  printf("Informe o departamento: ");
  fgets(dados.departamento,21,stdin);
  dados.departamento[strlen(dados.departamento)-1]='\0';
  printf("Informe o telefone: ");
  fgets(dados.telefone,21,stdin);
  dados.telefone[strlen(dados.telefone)-1]='\0';
  printf("Informe o celular: ");
  fgets(dados.celular,21,stdin);
  dados.celular[strlen(dados.celular)-1]='\0';
  printf("Informe o email: ");
  fgets(dados.email,31,stdin);
  dados.email[strlen(dados.email)-1]='\0';

  return dados;
}

//Funções auxiliares para manipulação de arquivos
int gravaArquivo (Lista *li) {
  arq = fopen("clientes.txt", "wb");
  if (arq == NULL) {
    printf("Erro ao abrir arquivo\n");
    return 0;
  }

  CLIENTE *dados;
  dados = (CLIENTE*) calloc (tamanhoLista(li), sizeof(CLIENTE));
  Elem *no = *li;
  while (no != NULL) {
    *dados = no->dados;
    fwrite(dados, sizeof(CLIENTE), 1, arq);

    no = no->prox;
  }

  free(dados);
  fclose(arq);
  return 1;
}

int leArquivo (Lista *li) {
  arq = fopen("clientes.txt", "rb");
  if (arq == NULL) {
    return 0;
  }
  CLIENTE cli;
  while (1) {
    fread(&cli, sizeof(CLIENTE), 1, arq);
    if(feof(arq)) break;
    inserirCliente(li, cli);
  }
  fclose(arq);
  return 1;
}
