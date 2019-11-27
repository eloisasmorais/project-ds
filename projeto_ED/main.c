#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"cadastro.h"

int main(){
    setlocale(LC_ALL,"Portuguese");
    int opc, x;
    Lista *li;
    CLIENTE dados;

    li = cria_lista();

    printf("****** Lista de Contatos ******\n");

    while(opc < 1 || opc > 6){
        printf("1 - Inserir novo contato\n");
        printf("2 - Gerar e exibir relatório de contatos em forma de lista total\n");
        printf("3 - Gerar e exibir relatório individual com busca por identificador\n");
        printf("4 - Gerar e exibir relatório com busca por nome\n");
        printf("5 - Edição do contato através de um identificador\n");
        printf("6 - Remover contato através de um identificador\n");
        printf("7 - Encerrar o programa\n\n");
        printf("Escolha uma opção:\n");
        scanf("%d",&opc);


        switch(opc){
        case 1:
            printf("Informe o código: \n");
            scanf("%d",&dados.codigo);
            printf("Informe o nome: \n");
            getchar();
            fgets(dados.nome, 29, stdin);
            printf("Informe a Empresa: \n");
            getchar();
            fgets(dados.empresa,19,stdin);
            printf("Informe o departamento: \n");
            getchar();
            fgets(dados.departamento,19,stdin);
            printf("Informe o telefone: \n");
            getchar();
            fgets(dados.telefone,19,stdin);
            printf("Informe o celular\n");
            getchar();
            fgets(dados.celular,19,stdin);
            printf("Informe o email: \n");
            getchar();
            fgets(dados.email,29,stdin);
            x = inserirCliente(li, dados);
            if(x){
                printf("Cadastro realizado com sucesso!\n");
            }
            else{
                printf("Erro ao realizar o cadastro!\n");
            }

            break;
        case 2:
            printf("opcao 2");
            break;
        case 3:
            printf("opcao 3");
            break;
        case 4:
            printf("opcao 4");
            break;
        case 5:
            printf("opcao 5");
            break;
        case 6:
            printf("opcao 6");
            break;
        case 7:
            printf("opcao 7");
            break;
        default:
            printf("opcao invalida");
            break;

        }
    }



}


