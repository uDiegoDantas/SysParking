#include <stdio.h>
#include <stdlib.h>
#include "telas_info.h"

void tela_menu_info(void){
    char op;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Menu Informacoes = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Sobre o programa                                          ///\n");
    printf("///            2. Ajuda                                                     ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("               Escolha a opcao desejada: "); 
    scanf("%c", &op);
    getchar();

    switch(op){
        case '1':
            tela_sobre();
			break;
        case '2':
            tela_ajuda();
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

void tela_sobre(void){

    system("clear || cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = = = = =  Sobre o Programa = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///            o SysParking eh um projeto de sistema de gestao de           ///\n");
    printf("///         estacionamento da disciplina de programaCAo do curso de         ///\n");                    
    printf("///         Sistemas de Informacao - UFRN.                                  ///\n");   
    printf("///                                                                         ///\n");
    printf("///            Atencao: este NAO eh um programa comercial. O autor nao      ///\n");
    printf("///         se responsabiliza por quaisquer danos, sejam pessoais,          ///\n");
    printf("///         materiais ou imateriais, decorrentes da utilizacao deste        ///\n");                 
    printf("///         codigo-fonte ou de trechos do mesmo, assim como, nao garante    ///\n");
    printf("///         o seu funcionamento correto em situacoes reais.                 ///\n");
    printf("///                                                                         ///\n");
    printf("///            Criado por Diego Dantas da Silva, aluno do curso de          ///\n");
    printf("///         Bacharelado em Sistema de Informacao - UFRN, em 2023.           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
}

void tela_ajuda(void){

    system("clear || cls");
    printf("\n");
    printf("////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                              ///\n");
    printf("///                  = = = = = = =  Instrucoes de uso = = = = = = =              ///\n");
    printf("///                                                                              ///\n");
    printf("///  1 - Ao iniciar o programa, voce sera apresentado ao Menu Principal. Este    ///\n");
    printf("///  menu oferece opcoes para acessar diferentes funcionalidades do sistema.     ///\n");
    printf("///                                                                              ///\n");
    printf("///  2 - Escolha da Opcao:                                                       ///\n");
    printf("///     Insira o numero correspondente a opcao desejada e pressione Enter.       ///\n");
    printf("///  Caso seja necessario inserir informacoes, siga as instrucoes na tela.       ///\n");
    printf("///                                                                              ///\n");
    printf("///  3 - Navegacao:                                                              ///\n");
    printf("///     Apos completar uma operacao, o programa geralmente retornara ao Menu     ///\n");
    printf("///  anterior ou solicitara a proxima acao.                                      ///\n");
    printf("///                                                                              ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;

}