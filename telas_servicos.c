#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "telas_servicos.h"
#include "telas_clientes.h"
#include "telas_veiculos.h"
#include "telas_vagas.h"

void tela_menu_servicos(void){
    char op;
    
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Menu Servicos = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Chek-in                                                   ///\n");
    printf("///            2. Chek-out                                                  ///\n");
    printf("///            3. Listar Chek-in's                                          ///\n");
    printf("///            4. Editar Chek-in                                            ///\n");
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
        case '2':
            tela_checkout();
            break;
        case '3':
            listar_checkins();
            break;
        case '4':
            editar_checkin();
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

struct Servicos{
    char placa[10];
    char codigo[3];
    char cpf[12];
    char data[11];
    char horario[6];
    char nomeCliente[50];
};

void tela_checkin(void){

    struct Servicos servico;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Check-in = = = = = = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///     Informe a placa do carro:\n");
    scanf("%s", servico.placa);
    getchar();
    
    int teste_veiculo = 0;

    FILE *arquivo_veiculos = fopen("veiculos.dat", "r+b");

    if (arquivo_veiculos == NULL) {
        printf("Arquivo não encontrado!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    struct Veiculo veiculo;

    while (fread(&veiculo, sizeof(struct Veiculo), 1, arquivo_veiculos) == 1 ) {
        if (strcmp(servico.placa, veiculo.placa) == 0) {
        teste_veiculo = 1;
        break;
        }
    }

    // Se o veículo não foi encontrado, exibe uma mensagem de erro
    if (!teste_veiculo) {
        printf("Veiculo nao encontrado ou ja esta cadastrado um algum check-in!.\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    fclose(arquivo_veiculos);

    printf("///\n");
    printf("///     Informe a vaga que sera utiliziada:\n");
    scanf("%s", servico.codigo);
    getchar();

    int vaga_encontrada = 0;

    FILE *arquivo_vagas = fopen("vagas.dat", "r+b");
    
    if (arquivo_vagas == NULL) {
        printf("Arquivo não encontrado!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    struct Vaga vaga;

    while (fread(&vaga, sizeof(struct Vaga), 1, arquivo_vagas) == 1) {
    
        // Verificar se a vaga existe
        if (strcmp(vaga.codigo, servico.codigo) == 0) {
            vaga_encontrada = 1;
            break;
        }

    }
    
    if(!vaga_encontrada){
        printf("Vaga nao encontrada ou ja esta cadastrada um algum check-in!.\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    fclose(arquivo_vagas);

    printf("///\n");
    printf("///     Informe o CPF do cliente:\n");
    scanf("%s", servico.cpf);
    getchar();
    
    int cpf_encontrado = 0;

    FILE *arquivo_clientes = fopen("clientes.dat", "r+b");

    if (arquivo_clientes == NULL) {
        printf("Arquivo não encontrado!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;    
    } 

    struct Cliente cliente;

    while(fread(&cliente, sizeof(struct Cliente), 1, arquivo_clientes) == 1){

        //Verifica se o CPF indicado existe
        if(strcmp(cliente.cpf, servico.cpf) == 0){
            cpf_encontrado = 1;
            strncpy(servico.nomeCliente, cliente.nome, sizeof(servico.nomeCliente) - 1);
            servico.nomeCliente[sizeof(servico.nomeCliente) - 1] = '\0'; 
            break;
        }
    }

    if(!cpf_encontrado){
        printf("CPF nao encontrado.\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    fclose(arquivo_clientes);

    // Verificar se já existe um check-in com esses dados
    if (existeCheckin(servico.placa, servico.codigo, servico.cpf)) {
        printf("Check-in com esses dados ja existe!\n");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    //Pegar a hora e data do checkin

    // Obter a hora atual
    time_t agora = time(NULL);
    struct tm *data_hora = localtime(&agora);

    // Armazena a hora e os minutos na variável 
    strftime(servico.horario, sizeof(servico.horario), "%H:%M", data_hora);

    // Obter a data atual
    
    struct tm *data_atual = localtime(&agora);

    // Armazena a data atual na variável "data"
    strftime(servico.data, sizeof(servico.data), "%d/%m/%Y", data_atual);
   
    printf("///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    FILE *arquivo = fopen("servicos.dat", "a+b");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        system("pause >nul");

    }

    fwrite(&servico, sizeof(struct Servicos), 1, arquivo);

    fclose(arquivo);

    printf("Checkin cadastrado com sucesso!\n");
    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listar_checkins(void){

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = Listar Check-in's Ativos = = = = = = = =       ///\n");
    printf("///                                                                         ///\n");

    FILE *arquivo_servicos = fopen("servicos.dat", "rb");

    struct Servicos servico;
    
    if (arquivo_servicos == NULL) {
        printf("Erro ao abrir o arquivo!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    printf("///\n");
    printf("///     Placa | Codigo | CPF | Data | Horario | Nome do Cliente\n");

    while (fread(&servico, sizeof(struct Servicos), 1, arquivo_servicos) == 1) {
        printf("///\n");
        printf("///     %s | %s | %s | %s | %s | %s\n", servico.placa, servico.codigo, servico.cpf, servico.data, servico.horario, servico.nomeCliente);
    }

    fclose(arquivo_servicos);

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para continuar...\n");
    getchar();
    return;
}

void tela_checkout(void){
    char codigo[3];

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Check-out = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///     Informe o codigo da vaga para realizar o check-out:\n");
    scanf("%s", codigo);
    getchar();

    FILE *arquivo_servicos = fopen("servicos.dat", "r+b");

    if (arquivo_servicos == NULL) {
        printf("Erro ao abrir o arquivo!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    FILE *arquivo_temporario = fopen("temporario.dat", "w+b");

    if (arquivo_temporario == NULL) {
        printf("Erro ao criar o arquivo temporario!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        fclose(arquivo_servicos);
        return;
    }

    int check_out_realizado = 0;
    struct Servicos servico;

    while (fread(&servico, sizeof(struct Servicos), 1, arquivo_servicos) == 1) {
        if (strcmp(codigo, servico.codigo) == 0) {
            // Registro encontrado, não copie para o arquivo temporário
            check_out_realizado = 1;
        } else {
            // Registro não é o que estamos procurando, copie para o arquivo temporário
            fwrite(&servico, sizeof(struct Servicos), 1, arquivo_temporario);
        }
    }

    fclose(arquivo_servicos);
    fclose(arquivo_temporario);

    if (check_out_realizado) {
        // Substitui o arquivo original pelo temporário
        remove("servicos.dat");
        rename("temporario.dat", "servicos.dat");
        printf("Check-out realizado com sucesso!\n");
    } else {
        printf("Check-out nao encontrado para o codigo da vaga informado.\n");
        // Remove o arquivo temporário, já que não foi utilizado
        remove("temporario.dat");
    }

    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void editar_checkin(void){
    char codigo[3];

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = Editar Check-in = = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("///     Informe o codigo da vaga para editar o check-in:\n");
    scanf("%s", codigo);
    getchar();


    FILE *arquivo_servicos = fopen("servicos.dat", "r+b");

    if (arquivo_servicos == NULL) {
        printf("Erro ao abrir o arquivo!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    FILE *arquivo_temporario = fopen("temporario.dat", "w+b");

    if (arquivo_temporario == NULL) {
        printf("Erro ao criar o arquivo temporario!");
        printf("\t\t>>> Tecle <ENTER> para continuar...\n");
        fclose(arquivo_servicos);
        return;
    }

    int checkin_encontrado = 0;
    struct Servicos servico;

    while (fread(&servico, sizeof(struct Servicos), 1, arquivo_servicos) == 1) {
        if (strcmp(codigo, servico.codigo) == 0) {
            // Registro encontrado, permite editar os dados
            checkin_encontrado = 1;

            printf("///     Informe a nova placa do carro:\n");
            scanf("%s", servico.placa);
            getchar();

            printf("///\n");
            printf("///     Informe o novo CPF do cliente:\n");
            scanf("%s", servico.cpf);
            getchar();

            printf("///\n");
            printf("///     Informe o novo nome do cliente:\n");
            scanf("%s", servico.nomeCliente);
            getchar();

            fwrite(&servico, sizeof(struct Servicos), 1, arquivo_temporario);

        }
    }

    fclose(arquivo_servicos);
    fclose(arquivo_temporario);

    if (checkin_encontrado ) {
        // Substitui o arquivo original pelo temporário
        remove("servicos.dat");
        rename("temporario.dat", "servicos.dat");
        printf("Check-in editado com sucesso!\n");
    } else {
        printf("Check-in nao encontrado para o codigo da vaga informado.\n");
        // Remove o arquivo temporário, já que não foi utilizado
        remove("temporario.dat");
    }

    printf("\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

int existeCheckin(const char *placa, const char *codigo, const char *cpf){
    FILE *arquivo_servicos = fopen("servicos.dat", "rb");

    if (arquivo_servicos == NULL) {
        return 0;
    }

    struct Servicos servico;
    while (fread(&servico, sizeof(struct Servicos), 1, arquivo_servicos) == 1) {
        if (strcmp(placa, servico.placa) == 0 || strcmp(codigo, servico.codigo) == 0 || strcmp(cpf, servico.cpf) == 0) {
            fclose(arquivo_servicos);
            return 1; // Já existe um check-in com esses dados
        }
    }

    fclose(arquivo_servicos);
    return 0; // Não encontrou um check-in com esses dados
}
