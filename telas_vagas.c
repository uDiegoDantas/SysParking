#include <stdio.h>
#include <stdlib.h>
#include "telas_vagas.h"


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
    printf("///            4. Visualizar mapa de vagas                                  ///\n");
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
            mapa_vagas();
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
    printf("///            Informe o numero da vaga:                                    ///\n");
    printf("///            Tipo da vaga (carro, moto, etc.):                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
}

void tela_editar_vaga(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = Editar Vaga = = = = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o numero da vaga a ser editada:                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
}

void tela_excluir_vaga(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = Excluir Vaga = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o numero da vaga a ser excluída:                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
}

void mapa_vagas(void){
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = =  Mapa das Vagas = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
}
