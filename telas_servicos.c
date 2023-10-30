#include <stdio.h>
#include <stdlib.h>
#include "telas_servicos.h"

void tela_menu_servicos(void){
    char op;
    
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Menu Servicos = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Chek-in                                                   ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opcao desejada: "); 
    scanf("%c", &op);
    getchar();

    switch(op){
        case '1':
            tela_checkin();
			break;
        case '0':
            return;
        default:
			printf("Valor invalido, tente novamente!");
			printf("\n");
    		printf("\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
    		break;
    }
    
}

void tela_checkin(void){
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Check-in = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
