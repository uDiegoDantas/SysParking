#include <stdio.h>
#include <stdlib.h>
 
#include "telas_clientes.h"
#include "telas_vagas.h"

struct Clientes2{
    char nome[50];
    char cpf[12];
    char telefone[15];
};

int existe_cpf(const char *cpf){
    FILE *arquivo_clientes = fopen("clientes.dat", "rb");

    if (arquivo_clientes == NULL) {
        return 0;
    }

    struct Clientes2 cliente;
    while (fread(&cliente, sizeof(struct Clientes2), 1, arquivo_clientes) == 1) {
        // Verifica se o CPF já foi cadastradow
        if (strcmp(cliente.cpf, cpf) == 0) {
            fclose(arquivo_clientes);
            return 1;
        }
    }

    fclose(arquivo_clientes);
    return 0;
}

