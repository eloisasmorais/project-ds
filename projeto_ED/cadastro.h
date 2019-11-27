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

Lista *cria_lista();

int inserirCliente(Lista *li, CLIENTE cli);

int lista_vazia(Lista *li);

