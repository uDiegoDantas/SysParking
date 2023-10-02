#include <stdio.h>
#include <stdlib.h>
#include "telas_info.h"

void tela_menu_info(void){
    char op;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Menu Informaçoes = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Sobre o programa                                          ///\n");
    printf("///            2. Ajuda                                                     ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: "); 
    scanf("%c", &op);
    getchar();

    switch(op){
        case '1':

            printf("Função em desenvolvimento, tente novamente mais tarde!");
            printf("\n");
    		printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    		getchar();
			tela_menu_info();
        case '2':
            printf("Função em desenvolvimento, tente novamente mais tarde!");
            printf("\n");
    		printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    		getchar();
			tela_menu_info();
        case '0':
            return;
        default:
			printf("Valor invalido, tente novamente!");
			printf("\n");
    		printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    		getchar();
    }
    
}