#include <stdio.h>
#include <stdlib.h>
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
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    switch(op)
	{
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
    case '0':
        tela_menu_principal();
    	break;
	default:
		printf("Valor invalido, tente novamente!");
		printf("\n");
    	printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
		tela_menu_cliente();
	}
}

void tela_cadastrar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome:                                                        ///\n");
    printf("///            CPF:                                                         ///\n");
    printf("///            Telefone:                                                    ///\n");
    printf("///            Endereço:                                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_cliente();
}

void tela_editar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Editar Cliente = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser editado:                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_cliente();
}

void tela_excluir_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Excluir Cliente = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser excluído:                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_cliente();
}

void visualizar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Visualizar Cliente = = = = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser visualizado:                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("A opcao esta em criacao ou manutencao, tente novamente mais tarde!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    tela_menu_cliente();
}




