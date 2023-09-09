#include <stdio.h>
#include <stdlib.h>

// Assinatura das funcoes
void tela_menu_principal(void);
// Modulo de veiculos
void tela_menu_veiculo(void);
void tela_cadastrar_veiculo(void);
void tela_pesquisar_veiculo(void);
void tela_alterar_veiculo(void);
void tela_excluir_veiculo(void);
void tela_visualizar_veiculo(void);
// Modulo de clientes
void tela_menu_cliente(void);
void tela_cadastrar_cliente(void);
void tela_editar_cliente(void);
void tela_excluir_cliente(void);
void tela_visualizar_cliente(void);
// Modulo de vagas do estacionamento
void tela_menu_vagas(void);
void tela_criar_vaga(void);
void tela_editar_vaga(void);
void tela_excluir_vaga(void);

// Programa principal
int main(void) {
    tela_menu_principal();
    return 0;
}

// Funcoes
void tela_menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = =         SysParking        = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Carros                                                    ///\n");
    printf("///            2. Clientes                                                  ///\n");
    printf("///            3. Vagas                                                     ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
    scanf("%d", &op);
    getchar();
    switch(op){
		case 1:
			tela_menu_veiculo();
        case 2:
        	tela_menu_cliente();
   		case 3: 
        	tela_menu_vagas();	
		case 0:
			break;	
		
		default:
			printf("Valor invalido, tente novamente!");	
			tela_menu_principal();	
        return 0;	
	}
}

void tela_menu_veiculo(void) {
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
    scanf("%d", &op);
    getchar();
    switch(op){
		case 1:
			tela_cadastrar_veiculo();
		case 2:
			tela_visualizar_veiculo();
		case 3:
			tela_alterar_veiculo();
		case 4: 
			tela_excluir_veiculo();
		case 0:
			tela_menu_principal();
		default:
			printf("Valor invalido, tente novamente!");
			printf("\n");
    		printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    		getchar();
			tela_menu_veiculo();	
	}
    
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
    printf("///            Ano do veiculo (dd/mm/aaaa):                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
    printf("\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();
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
    printf("\t\t>>> Pressione <ENTER> para continuar...\n");
    getchar();
}

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
    printf("///            4. Visualizar informações de um cliente                      ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &op);
    getchar();
    switch(op)
	{
	case 1:
		tela_cadastrar_cliente();	 
	case 2:		   
		tela_editar_cliente();
    case 3:
    	tela_excluir_cliente();
 	case 4:
 		visualizar_cliente();
    case 0:
    	tela_menu_principal();
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
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_editar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Editar Cliente = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser editado:                       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void visualizar_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Visualizar Cliente = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF do cliente a ser visualizado:                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_menu_vagas(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = Menu Vagas = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Criar uma nova vaga                                        ///\n");
    printf("///            2. Editar vaga existente                                      ///\n");
    printf("///            3. Excluir vaga                                               ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &op);
    switch(op)
	{
	case 1:
		tela_criar_vaga();
	case 2:
		tela_editar_vaga();
    case 3:
    	tela_excluir_vaga();
 	case 0:
 		tela_menu_principal();
	default:
		printf("Valor invalido, tente novamente!");
		printf("\n");
    	printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
		tela_menu_vagas();
	}
    
}

void tela_criar_vaga(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = Criar Vaga = = = = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o número da vaga:                                    ///\n");
    printf("///            Tipo da vaga (carro, moto, etc.):                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_editar_vaga(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = Editar Vaga = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o número da vaga a ser editada:                       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_excluir_vaga(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = Excluir Vaga = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o número da vaga a ser excluída:                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}