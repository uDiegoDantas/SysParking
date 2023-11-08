#include <stdio.h>
#include <stdlib.h>
#include "telas_vagas.h"

struct Vaga {
    char codigo[3]; // Uma letra seguida de um numero de 0 a 15
    char tipo[20];
};

void tela_menu_vagas(void) {
    char op;
    
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Menu Vagas = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Criar uma nova vaga                                       ///\n");
    printf("///            2. Editar vaga existente                                     ///\n");
    printf("///            3. Excluir vaga                                              ///\n");
    printf("///            4. Visualizar lista de vagas                                 ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opcao desejada: "); 
    scanf("%c", &op);
    getchar();

    switch(op){
        case '1':
            tela_criar_vaga();
            break;
        case '2':
            tela_editar_vaga();
            break;
        case '3':
            tela_excluir_vaga();
            break;
        case '4':
            lista_vagas();
            break;
        case '0':
            return;
        default:
            printf("Valor invalido, tente novamente!");
            printf("\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
	}
}

void tela_criar_vaga(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = Criar Vaga = = = = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///           Informe o codigo da vaga (letra + numero de 0 a 15, ex: A7):  ///\n");
    char codigo[3];
    scanf("%s", codigo);
    printf("///            Tipo da vaga (carro, moto, etc.): ");
    char tipo[20];
    scanf("%s", tipo);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    // Verifique se o codigo da vaga segue o padrão especificado 
    if ((codigo[0] >= 'A' && codigo[0] <= 'Z') &&
        (codigo[1] >= '0' && codigo[1] <= '9') && codigo[2] == '\0' &&
        (codigo[1] - '0' >= 0 && codigo[1] - '0' <= 15)) {
        
        FILE *arquivo = fopen("vagas.dat", "ab");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        struct Vaga vaga;
        
        strcpy(vaga.codigo, codigo);
        strcpy(vaga.tipo, tipo);

        fwrite(&vaga, sizeof(struct Vaga), 1, arquivo);

        fclose(arquivo);

        printf("Vaga cadastrada com sucesso!\n");

    } else {
        printf("codigo da vaga invalido. Deve ser uma letra seguida por um numero de 0 a 15.\n");
    }

    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_editar_vaga(void) {
    char codigo[3];

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = Editar Vaga = = = = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o codigo da vaga a ser editada: ");
    scanf("%s", codigo);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    // Verifique se o codigo da vaga segue o padrão especificado
    if ((codigo[0] >= 'A' && codigo[0] <= 'Z') &&
        (codigo[1] >= '0' && codigo[1] <= '9') && codigo[2] == '\0' &&
        (codigo[1] - '0' >= 0 && codigo[1] - '0' <= 15)) {
    
        FILE *arquivo = fopen("vagas.dat", "r+b");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            printf(">>> Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        struct Vaga vaga;
        int encontrado = 0;

        while (fread(&vaga, sizeof(struct Vaga), 1, arquivo) == 1) {
            if (strcmp(codigo, vaga.codigo) == 0) {
                printf("///     Dados do cliente a ser editado:\n");
                printf("///\n");
                printf("///     Codigo: %s\n", vaga.codigo);
                printf("///     Tipo: %s\n", vaga.tipo);
                printf("///\n");
                printf("///     Novo codigo: ");
                scanf("%s", vaga.codigo);
                printf("///     Novo Tipo: ");
                scanf("%s", vaga.tipo);
                printf("///\n");
                printf("///////////////////////////////////////////////////////////////////////////////\n");
                printf("\n");
                getchar();
                
                fseek(arquivo, -sizeof(struct Vaga), SEEK_CUR);
                fwrite(&vaga, sizeof(struct Vaga), 1, arquivo);
                encontrado = 1;
                break; 
            }
        }

        if (!encontrado) {
            printf("Vaga com o codigo %s nao encontrada.\n", codigo);
        }

        fclose(arquivo);

        printf(">>> Tecle <ENTER> para continuar...\n");
    
    } else {
        printf("codigo da vaga invalido. Deve ser uma letra seguida por um numero de 0 a 15.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
    }

    getchar();
}

void tela_excluir_vaga(void) {
    char codigo[3];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = Excluir Vaga = = = = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o codigo da vaga a ser excluida : ");
    scanf("%s", codigo);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    
    if ((codigo[0] >= 'A' && codigo[0] <= 'Z') &&
        (codigo[1] >= '0' && codigo[1] <= '9') && codigo[2] == '\0' &&
        (codigo[1] - '0' >= 0 && codigo[1] - '0' <= 15)) {
        
        FILE *arquivo = fopen("vagas.dat", "r+b");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            printf(">>> Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        struct Vaga vaga;
        int encontrado = 0;
        FILE *temp = fopen("temp_vagas.dat", "w+b"); 

        if (temp == NULL) {
            printf("Erro ao criar o arquivo temporario.\n");
            fclose(arquivo);
            printf(">>> Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        while (fread(&vaga, sizeof(struct Vaga), 1, arquivo) == 1) {
            if (strcmp(codigo, vaga.codigo) == 0) {
                printf("A vaga foi excluída.\n");
                encontrado = 1;
            } else {
                fwrite(&vaga, sizeof(struct Vaga), 1, temp);
            }
        }

        if (!encontrado) {
            printf("Vaga nao encontrada.\n");
        }

        fclose(arquivo);
        fclose(temp);

        remove("vagas.dat");
        rename("temp_vagas.dat", "vagas.dat");

        printf(">>> Tecle <ENTER> para continuar...\n");
    } else {
        printf("codigo da vaga invalido. O codigo deve ser uma letra seguida por um numero de 0 a 15.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
    }

    getchar();
}

void tela_visualizar_vaga(void) {
    char codigo[3];

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = =  Visualizar Vaga = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o codigo da vaga a ser visualizada : ");
    scanf("%s", codigo);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    if ((codigo[0] >= 'A' && codigo[0] <= 'Z') &&
        (codigo[1] >= '0' && codigo[1] <= '9') && codigo[2] == '\0' &&
        (codigo[1] - '0' >= 0 && codigo[1] - '0' <= 15)) {
        
        FILE *arquivo = fopen("vagas.dat", "rb");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            printf(">>> Tecle <ENTER> para continuar...\n");
            getchar();
            return;
        }

        struct Vaga vaga;
        int encontrado = 0;

        while (fread(&vaga, sizeof(struct Vaga), 1, arquivo) == 1) {
            if (strcmp(codigo, vaga.codigo) == 0) {
                printf("Dados da vaga:\n");
                printf("codigo: %s\n", vaga.codigo);
                printf("Tipo: %s\n", vaga.tipo);
                encontrado = 1;
                break; 
            }
        }

        if (!encontrado) {
            printf("Vaga nao encontrada.\n");
        }

        fclose(arquivo);

        printf(">>> Tecle <ENTER> para continuar...\n");
    } else {
        printf("codigo da vaga invalido. Deve ser uma letra seguida por um numero de 0 a 15.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
    }

    getchar();
}

void lista_vagas(void){
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = =  Lista das Vagas = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");

    // Abra o arquivo binário no modo de leitura
    FILE *arquivo = fopen("vagas.dat", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    struct Vaga vaga;


    while (fread(&vaga, sizeof(struct Vaga), 1, arquivo) == 1) {
        printf("///     Codigo: %s\n", vaga.codigo);
        printf("///     Tipo: %s\n", vaga.tipo);
        printf("///\n");
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
 
    fclose(arquivo);

    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
}