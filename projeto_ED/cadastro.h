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

Lista *criaLista();

int tamanhoLista (Lista *li);

int inserirCliente(Lista *li, CLIENTE cli);

int listaVazia(Lista *li);

void destroiLista(Lista *li);
//Novas funções

int exibeMenu(); //Exibe menu de opções do programa
void exibeErro();
void exibeRelatorioTotal(Lista *li);
void buscaCliCod(Lista *li, int cod, CLIENTE *cli);
void buscaCliNome(Lista *li, char *nome, CLIENTE *cli);
void exibeCli(CLIENTE *cli);
void editaContato();
void removeContato();

CLIENTE recebeDados();
