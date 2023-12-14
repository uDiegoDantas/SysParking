#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas_veiculos.h"

void tela_menu_veiculos(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = Menu Veiculos = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo veiculo                                 ///\n");
    printf("///            2. Pesquisar os dados de um veiculo                          ///\n");
    printf("///            3. Atualizar o cadastro de um veiculo                        ///\n");
    printf("///            4. Excluir um veiculo do sistema                             ///\n");
    printf("///            5. Listar veiculos cadastrados                               ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();

    switch(op){
        case '1':
            tela_cadastrar_veiculo();
            break;
        case '2':
            tela_visualizar_veiculo();
            break;
        case '3':
            tela_alterar_veiculo();
            break;
        case '4': 
            tela_excluir_veiculo();
            break;
        case '5':
            listar_veiculos();
            break;
        case '0':
            break;
        default:
            printf("Valor invalido, tente novamente!");
            printf("\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();

	}    
    return;     
}

struct Veiculo {
    char placa[10];
    char proprietario[50];
    char ano[4];
    char porte[20];
};

void tela_cadastrar_veiculo(void) {
    char placa[10];
    char proprietario[50];
    char ano[4];
    char porte[20];

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = Cadastrar veiculo = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Placa: ");
    scanf("%s", placa);
    getchar();
    printf("///            Proprietario: ");
    scanf("%s", proprietario);
    getchar();
    printf("///            Ano do veiculo (aaaa): ");
    scanf("%s", ano);
    getchar();
    printf("///            Porte(Carro, moto, etc): ");
    scanf("%s", porte);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    FILE *arquivo = fopen("veiculos.dat", "ab");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    struct Veiculo veiculo;

    strcpy(veiculo.placa, placa);
    strcpy(veiculo.proprietario, proprietario);
    strcpy(veiculo.ano, ano);
    strcpy(veiculo.porte, porte);

    fwrite(&veiculo, sizeof(struct Veiculo), 1, arquivo);

    fclose(arquivo);

    printf("Veiculo cadastrado com sucesso!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void tela_visualizar_veiculo(void) {
    char placa[10];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = =  Visualizar Veiculo = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a placa do veiculo a ser visualizado: ");
    scanf("%s", placa);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    

    FILE *arquivo = fopen("veiculos.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    struct Veiculo veiculo;
    int encontrado = 0;

    while (fread(&veiculo, sizeof(struct Veiculo), 1, arquivo) == 1) {
        if (strcmp(placa, veiculo.placa) == 0) {
            system("clear||cls");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("///                                                                         ///\n");
            printf("///            = = = = = = = = =  Veiculo Encontrado  = = = = = = = =       ///\n");
            printf("///                                                                         ///\n");
            printf("///     Placa: %s\n", veiculo.placa);
            printf("///     Proprietario: %s\n", veiculo.proprietario);
            printf("///     Ano: %s\n", veiculo.ano);
            printf("///     Porte: %s\n", veiculo.porte);
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            encontrado = 1;
            break; // Parar a busca após encontrar o veículo
        }
    }

    if (!encontrado) {
        printf("Veículo com a placa %s não encontrado.\n", placa);
    }

    // Feche o arquivo após a leitura
    fclose(arquivo);

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void tela_alterar_veiculo(void) {
    char placa[10];

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = Alterar Veiculo = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a placa do veiculo: ");
    scanf("%s", placa);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    // Abra o arquivo binário no modo de leitura e escrita
    FILE *arquivo = fopen("veiculos.dat", "r+b");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }

    struct Veiculo veiculo;
    int encontrado = 0;

    while (fread(&veiculo, sizeof(struct Veiculo), 1, arquivo) == 1) {
        if (strcmp(placa, veiculo.placa) == 0) {
            system("clear||cls");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("///                                                                         ///\n");
            printf("///            = = = = = = = = Veiculo a ser editado = = = = = = =          ///\n");
            printf("///                                                                         ///\n");
            printf("///     Placa: %s\n", veiculo.placa);
            printf("///     Proprietario: %s\n", veiculo.proprietario);
            printf("///     Ano: %s\n", veiculo.ano);
            printf("///     Porte: %s\n", veiculo.porte);
            printf("///\n");
            printf("///     Nova Placa: ");
            scanf("%s", veiculo.placa);
            getchar();
            printf("///     Novo Proprietario: ");
            scanf("%s", veiculo.proprietario);
            getchar();
            printf("///     Novo Ano: ");
            scanf("%s", veiculo.ano);
            getchar();
            printf("///     Novo Porte: ");
            scanf("%s", veiculo.porte);
            getchar();
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\n");
            
            fseek(arquivo, -sizeof(struct Veiculo), SEEK_CUR);
            fwrite(&veiculo, sizeof(struct Veiculo), 1, arquivo);
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado) {
        printf("Veículo com a placa %s não encontrado.\n", placa);
    }

    fclose(arquivo);

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void tela_excluir_veiculo(void) {
    char placa[10];

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = Excluir Veiculo = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a placa do veiculo que deseja excluir: ");
    scanf("%s", placa);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    FILE *arquivo = fopen("veiculos.dat", "r+b");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }

    struct Veiculo veiculo;
    int encontrado = 0;
    FILE *temp = fopen("temp_veiculos.dat", "w+b"); 

    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(&veiculo, sizeof(struct Veiculo), 1, arquivo) == 1) {
        if (strcmp(placa, veiculo.placa) == 0) {
            printf("O veiculo  foi excluido com sucesso.\n");
            encontrado = 1;
        } else {
            fwrite(&veiculo, sizeof(struct Veiculo), 1, temp);
        }
    }

    if (!encontrado) {
        printf("Veículo nao foi encontrado.\n");
    }

    fclose(arquivo);
    fclose(temp);

    remove("veiculos.dat");
    rename("temp_veiculos.dat", "veiculos.dat");

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}

void listar_veiculos(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Lista de Veiculos = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///     Lista de veiculos cadastrados:                                      ///\n");
    printf("///                                                                         ///\n");

    FILE *arquivo = fopen("veiculos.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

        return;
    }

    struct Veiculo veiculo;

    while (fread(&veiculo, sizeof(struct Veiculo), 1, arquivo) == 1){
        printf("///     Placa: %s\n", veiculo.placa);
        printf("///     Proprietario: %s\n", veiculo.proprietario);
        printf("///     Ano: %s\n", veiculo.ano);
        printf("///     Porte: %s\n", veiculo.porte);
        printf("///\n");
    }

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    fclose(arquivo);

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();

    return;
}
