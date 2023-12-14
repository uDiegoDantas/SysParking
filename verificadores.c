#include <stdio.h>
#include <stdlib.h>
#include "verificadores.h"

#include "telas_clientes.h"
#include "telas_vagas.h"
#include "telas_veiculos.h"
#include "telas_info.h"
#include "telas_servicos.h"

//O uso doe alguns verificadores está instavel no programa principal, por isso não está em uso
int existeCheckin(const char *placa, const char *codigo, const char *cpf) {
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

int verificarCPF(char *cpf) {
    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11)
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) || (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
        return 0;
    else {
        for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--)
            digito1 += (cpf[i] - '0') * j;
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - '0') != digito1)
            return 0;
        else {
            for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--)
                digito2 += (cpf[i] - '0') * j;
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - '0') != digito2)
                return 0;
        }
    }
    return 1;
}
