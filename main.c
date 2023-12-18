#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "telas_clientes.h"
#include "telas_vagas.h"
#include "telas_veiculos.h"
#include "telas_info.h"
#include "telas_servicos.h"
#include "verificadores.h"

// Assinatura da tela do menu principal
void tela_menu_principal(void);

// Tela do menu principal
void tela_menu_principal(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = =         SysParking        = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Veiculos                                                  ///\n");
    printf("///            2. Clientes                                                  ///\n");
    printf("///            3. Vagas                                                     ///\n");
    printf("///            4. Servicos                                                  ///\n");
    printf("///            5. Informacoes                                               ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");
    return;
}

// Programa principal
int main(void) {

    setlocale(LC_ALL,"Portuguese");
    char op;
    
    do {
        tela_menu_principal();
        printf("               Escolha a opcao desejada: ");
        scanf("%c", &op);
        getchar();
    
        switch(op) {
        case '1':
            tela_menu_veiculos();
            break;  
        case '2':
            tela_menu_cliente();
            break;  
        case '3':
            tela_menu_vagas();
            break;  
        case '4':
            tela_menu_servicos();
            break;  
        case '5':
            tela_menu_info();
            break;  
        case '0':
            exit(0);  
        default:
            printf("Valor invalido, tente novamente!\n");
            printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    		getchar();
        }
    }while(op != '0');
    return 0;
}
