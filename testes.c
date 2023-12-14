#include <stdio.h>
#include <time.h>

int main(void) {

  // Obtém a data atual
  time_t agora = time(NULL);

  // Converte a data atual para uma estrutura tm
  struct tm *data_atual = localtime(&agora);

  // Armazena a data atual na variável "data"
  char data[11];

  strftime(data, sizeof(data), "%d/%m/%Y", data_atual);

  // Imprime a data atual
  printf("Data atual: %s\n", data);

  return ;
}
