#include <stdbool.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

//       (pai)
//         |
//    +----+----+
//    |         |
// filho_1   filho_2

// ~~~ printfs  ~~~
// pai (ao criar filho): "Processo pai criou %d\n"
//    pai (ao terminar): "Processo pai finalizado!\n"
//  filhos (ao iniciar): "Processo filho %d criado\n"

// Obs:
// - pai deve esperar pelos filhos antes de terminar!

const int NUM_FILHOS = 2;

// Retorna false para pai e true para filho.
bool processo_filho() {
  fflush(stdout);
  pid_t pid = fork();

  // Processo pai sai da função.
  if (pid > 0) {
    printf("Processo pai criou %d\n", pid);
    return false;
  }

  printf("Processo filho %d criado\n", getpid());
  return true;
}

int main(int argc, char **argv) {
  for (int i = 0; i < NUM_FILHOS; ++i) {
    if (processo_filho()) {
      return 0;
    }
  }

  while (wait(NULL) >= 0)
    ;

  printf("Processo pai finalizado!\n");
  return 0;
}
