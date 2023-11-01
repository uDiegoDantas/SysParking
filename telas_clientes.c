#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas_clientes.h"

void tela_menu_cliente(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Menu Clientes = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo cliente                                 ///\n");
    printf("///            2. Editar dados de um cliente                                ///\n");
    printf("///            3. Excluir um cliente do sistema                             ///\n");
    printf("///            4. Visualizar informacoes de um cliente                      ///\n");
    printf("///            5. Lista de clientes                                         ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opcao desejada: ");        
    scanf("%c", &op);
    getchar();
    
    switch(op) {
        case '1':
            tela_cadastrar_cliente();
            break;  
        case '2':
            tela_editar_cliente();
            break;  
        case '3':
            tela_excluir_cliente();
            break;  
        case '4':
            visualizar_cliente();
            break;  
        case '5':
            listar_clientes();
            break;
        case '0':
            return;
        default:
            printf("Valor invalido, tente novamente!");
            printf("\n");
            
            printf(">>> Tecle <ENTER> para continuar...\n");
            getchar();
    }
   
}

struct Cliente {
    char nome[50];
    char cpf[12];
    char telefone[15];
};

void tela_cadastrar_cliente(void) {
    struct Cliente cliente; 

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome: ");
    scanf("%s", cliente.nome);
    printf("///            CPF: ");
    scanf("%s", cliente.cpf);
    printf("///            Telefone: ");
    scanf("%s", cliente.telefone);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    FILE *arquivo = fopen("clientes.dat", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        
        getchar();
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }

    fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);

    fclose(arquivo);

    printf("Cliente cadastrado com sucesso!\n");

    getchar();
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void tela_editar_cliente(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Editar Cliente = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser editado: ");
    scanf("%s", cpf);
    printf("///\n");

    FILE *arquivo = fopen("clientes.dat", "r+b");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");

        getchar();
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }
    
    struct Cliente cliente;
    int encontrado = 0;
    
    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        if (strcmp(cpf, cliente.cpf) == 0) {
            printf("///     Dados do cliente a ser editado:\n");
            printf("///\n");
            printf("///     Nome: %s\n", cliente.nome);
            printf("///     CPF: %s\n", cliente.cpf);
            printf("///     Telefone: %s\n", cliente.telefone);
            printf("///\n");        
            printf("///     Novo Nome: ");
            scanf("%s", cliente.nome);
            printf("///     Novo CPF: ");
            scanf("%s", cliente.cpf);
            printf("///     Novo Telefone: ");
            scanf("%s", cliente.telefone);
            getchar();
            printf("///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\n");
            
            fseek(arquivo, -sizeof(struct Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);
            encontrado = 1;
            break; 
        }
    }
    
    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
        return;
    }
    
    fclose(arquivo);
    
    printf("CLiente editado com sucesso!");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void tela_excluir_cliente(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Excluir Cliente = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser excluido: ");
    scanf("%s", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    
    FILE *arquivo = fopen("clientes.dat", "r+b");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }
    
    struct Cliente cliente;
    int encontrado = 0;
    FILE *temp = fopen("temp.dat", "w+b"); 
    
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporario.\n");
        fclose(arquivo);

        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }
    
    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        if (strcmp(cpf, cliente.cpf) == 0) {
            printf("Cliente excluido com sucesso!.\n");
            encontrado = 1;
        } else {

            fwrite(&cliente, sizeof(struct Cliente), 1, temp);
        }
    }
    
    if (!encontrado) {
        printf("Cliente com o CPF %s nao encontrado.\n", cpf);
    }
    
    fclose(arquivo);
    fclose(temp);

    remove("clientes.dat");
    rename("temp.dat", "clientes.dat");
    
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void visualizar_cliente(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Visualizar Cliente = = = = = = = = =     ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser visualizado: ");
    scanf("%s", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    FILE *arquivo = fopen("clientes.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }

    struct Cliente cliente;
    int encontrado = 0;

    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1) {
        if (strcmp(cpf, cliente.cpf) == 0) {
            printf("Dados do cliente:\n");
            printf("Nome: %s\n", cliente.nome);
            printf("CPF: %s\n", cliente.cpf);
            printf("Telefone: %s\n", cliente.telefone);
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    fclose(arquivo);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void listar_clientes(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Lista de Clientes = = = = = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Lista de Clientes:                                           ///\n");
    printf("///                                                                         ///\n");

    FILE *arquivo = fopen("clientes.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        getchar();
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    struct Cliente cliente;

    while (fread(&cliente, sizeof(struct Cliente), 1, arquivo) == 1){
        printf("///            Nome: %s\n", cliente.nome);
        printf("///            CPF: %s\n", cliente.cpf);
        printf("///            Telefone: %s\n", cliente.telefone);
        printf("///\n");
        
    }
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    fclose(arquivo);

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}

