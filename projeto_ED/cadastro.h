#include <stdio.h>

typedef struct cli{
    int codigo;
    char nome[30];
    char empresa[20];
    char departamento[20];
    char telefone[20];
    char celular[20];
    char email[30];
}CLIENTE;

typedef struct elemento *Lista;
FILE *arq; //Declaração do ponteiro para abertura de arquivo

Lista *criaLista();

int tamanhoLista (Lista *li);

int inserirCliente(Lista *li, CLIENTE cli);

int listaVazia(Lista *li);

void destroiLista(Lista *li);

//Novas funções

int exibeMenu(); 
/*
  Exibe menu de opções do programa
  Retorno da função: int com o opção escolhida
*/
void exibeErro(); 
/*
  Exibe mensagem de erro padrão
  Retorno da função: nenhum
*/
void exibeRelatorioTotal(Lista *li);
/*
  Exibe todos os clientes armazenados na lista
  Parâmetros: ponteiro do tipo Lista
  Retorno da função: nenhum
 */
int buscaCliCod(Lista *li, int cod, CLIENTE *cli);
/*
  Busca cliente em função do código identificador
  Parâmetros: ponteiro do tipo Lista, código identificado do tipo int,
  ponteiro para struct CLIENTE
  Retorno da função: retorna 1 se encontrar o código, retorna 0 se nó == NULL
*/
int buscaCliNome(Lista *li, char *nome);
/*
  Busca cliente em função do nome, procura substring em todos os nomes da lista
  Parâmetros: ponteiro do tipo Lista, ponteiro para string,
  Retorno da função: retorna 1 se encontrar nomes, retorna 0 se não encontrar
*/
void exibeClientes(CLIENTE cli);
/*
  Exibe dados dos clientes
  Parâmetros: variável do tipo CLIENTE
  Retorno da função: nenhum
*/
int editaContato(Lista *li, int codigo);
/*
  Edição de clientes, um por vez, através do código
  Parâmetros: ponteiro para tipo Lista, inteiro para o código
  do cliente a ser editado
  Retorno da função: 1 se encontrou o cliente, 0 se não encontrar 
*/
int removeContato(Lista *li, int codigo);
/*
  Remove cliente da lista, um por vez.
  Parâmetros: ponteiro para tipo Lista, inteiro para o código
  do cliente a ser removido
  Retorno da função: 1 se removeu da lista corretamente, 
  0  se não encontrou o cliente
*/

CLIENTE recebeDados(int codigo, int edicao);
/*
  Função para receber dados do teclado
  Parâmetros: int para o código do cliente em caso de edição,
  int para verificar se é modo de edição ou inserção
  Retorno da função: retorna struct do tipo CLIENTE
*/


//Funções auxiliares para manipulação de arquivos
int gravaArquivo (Lista *li);
/*
  Remove cliente da lista, um por vez.
  Parâmetros: ponteiro para tipo Lista
  Retorno da função: 1 se gravou o arquivo, 0 se não abriu o arquivo corretamente
*/

int leArquivo(Lista *li);
/*
  Leitura do arquivo para a gravação dos dados na lista
  Parâmetros: ponteiro para tipo Lista
  Retorno da função: 1 se leu o arquivo corretamente até o fim,
  0 se o arquivo não foi aberto.
*/
