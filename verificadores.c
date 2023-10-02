#include <stdio.h>
#include <stdlib.h>
#include "verificadores.h"

int verifica_cpf(const char *cpf){
    if (strlen(cpf) != 11)
        return 0;

    for (int i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9')
            return 0;
    }

    int soma = 0;
    int digito1, digito2;

    // Calcula o primeiro dígito verificador
    for (int i = 0, j = 10; i < 9; i++, j--) {
        soma += (cpf[i] - '0') * j;
    }
    digito1 = 11 - (soma % 11);
    if (digito1 >= 10)
        digito1 = 0;

    if (cpf[9] - '0' != digito1)
        return 0;

    soma = 0;

    // Calcula o segundo dígito verificador
    for (int i = 0, j = 11; i < 10; i++, j--) {
        soma += (cpf[i] - '0') * j;
    }
    digito2 = 11 - (soma % 11);
    if (digito2 >= 10)
        digito2 = 0;

    if (cpf[10] - '0' != digito2)
        return 0;

    return 1;
}

//Verificador de nome
bool verifica_nome(char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return false;
        }
    }
    return true;
}

//Verificador de telefone
bool verifica_telefone(char telefone[]) {
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (!isdigit(telefone[i]) && telefone[i] != ' ') {
            return false;
        }
    }
    return true;
}

//Verificador de placa de veículo
int verifica_placa(const char *placa) {
    if (placa == NULL)
        return 0;

    for (int i = 0; placa[i] != '\0'; i++) {
        if (!isalnum((unsigned char)placa[i])) {
            return 0; // Se encontrar um caractere que não é alfanumérico, retorna falso
        }
    }

    return 1; // Se passou pelo loop sem encontrar caracteres inválidos, retorna verdadeiro
}

//Verificar o ano do carro 
int verifica_ano_carro(int anoCarro) {
    // Obtém o ano atual
    time_t t;
    struct tm *agora;
    t = time(NULL);
    agora = localtime(&t);
    int anoAtual = agora->tm_year + 1900;

    // Define um ano mínimo (1886, quando o primeiro carro foi fabricado)
    int anoMinimo = 1886;

    if (anoCarro >= anoMinimo && anoCarro <= anoAtual) {
        return 1; // Ano do carro válido
    } else {
        return 0; // Ano do carro inválido
    }
}