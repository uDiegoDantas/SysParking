#include <stdio.h>
#include <stdlib.h>
#include "telas_clientes.h"
#include "telas_vagas.h"
#include "telas_veiculos.h"

// Assinatura da tela do menu principal
void tela_menu_principal(void);

// Programa principal
int main(void) {
    tela_menu_principal();
    return 0;
}

// Tela do menu principal
void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = =         SysParking        = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Veiculos                                                  ///\n");
    printf("///            2. Clientes                                                  ///\n");
    printf("///            3. Vagas                                                     ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    switch (op) {
        case '1':
            tela_menu_veiculos();
            break;  
        case '2':
            tela_menu_cliente();
            break;  
        case '3':
            tela_menu_vagas();
            break;  
        case '0':
            exit(0);  
        default:
            printf("Valor inválido, tente novamente!");
            tela_menu_principal();
    }
}

