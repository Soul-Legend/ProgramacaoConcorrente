#include <stdbool.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

//                          (principal)
//                               |
//              +----------------+--------------+
//              |                               |
//           filho_1                         filho_2
//              |                               |
//    +---------+-----------+          +--------+--------+
//    |         |           |          |        |        |
// neto_1_1  neto_1_2  neto_1_3     neto_2_1 neto_2_2 neto_2_3

// ~~~ printfs  ~~~
//      principal (ao finalizar): "Processo principal %d finalizado\n"
// filhos e netos (ao finalizar): "Processo %d finalizado\n"
//    filhos e netos (ao inciar): "Processo %d, filho de %d\n"

// Obs:
// - netos devem esperar 5 segundos antes de imprmir a mensagem de finalizado (e
// terminar)
// - pais devem esperar pelos seu descendentes diretos antes de terminar

const int NUM_FILHOS = 2;
const int NUM_NETOS = 3;
const int TEMPO_ESPERA = 5;

// Retorna false para pai e true para filho.
bool processo_filho(int num_netos) {
  fflush(stdout);
  pid_t pid = fork();

  // Processo pai sai da função.
  if (pid > 0) {
    return false;
  }

  printf("Processo %d, filho de %d\n", getpid(), getppid());

  for (int i = 0; i < num_netos; ++i) {
    // Chama a função atual para criar os netos.
    if (processo_filho(0)) {
      sleep(TEMPO_ESPERA);
      return true;
    }
  }

  // Filho espera pelos netos.
  while (wait(NULL) >= 0)
    ;

  return true;
}

int main(int argc, char **argv) {
  for (int i = 0; i < NUM_FILHOS; ++i) {
    if (processo_filho(NUM_NETOS)) {
      printf("Processo %d finalizado\n", getpid());
      return 0;
    }
  }

  while (wait(NULL) >= 0)
    ;

  printf("Processo principal %d finalizado\n", getpid());
  return 0;
}
