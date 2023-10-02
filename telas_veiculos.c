#include <stdio.h>
#include <stdlib.h>
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
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
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

void tela_cadastrar_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar veiculo = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Placa:                                                       ///\n");
    printf("///            Codigo do proprietario:                                      ///\n");
    printf("///            Tipo do veiculo:                                             ///\n");
    printf("///            Cor do veiculo:                                              ///\n");
    printf("///            Ano do veiculo (aaaa):                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_veiculos();
}

void tela_visualizar_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = =  Visualizar Veiculo = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a placa do veiculo a ser visualizado:                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_veiculos();
}

void tela_alterar_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Veiculo = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a placa do veiculo:                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_veiculos();
}

void tela_excluir_veiculo(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir Veiculo = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a placa do veiculo que deseja excluir:               ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_veiculos();
}
