#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// Lê o conteúdo do arquivo filename e retorna um vetor E o tamanho dele
// Se filename for da forma "gen:%d", gera um vetor aleatório com %d elementos
//
// +-------> retorno da função, ponteiro para vetor malloc()ado e preenchido
// |
// |         tamanho do vetor (usado <-----+
// |         como 2o retorno)              |
// v                                       v
double *load_vector(const char *filename, int *out_size);

// Avalia se o prod_escalar é o produto escalar dos vetores a e b. Assume-se
// que ambos a e b sejam vetores de tamanho size.
void avaliar(double *a, double *b, int size, double prod_escalar);

struct args_st {
  int start;
  int end;
  double *a;
  double *b;
};

// Realiza o produto escalar parcial entre os subvetores
// a[start:end] e b[start:end].
void *thread(void *arg_void) {
  struct args_st arg = *((struct args_st *)arg_void);

  double *sum = calloc(1, sizeof(double));

  for (int i = arg.start; i < arg.end; ++i) {
    *sum += arg.a[i] * arg.b[i];
  }

  pthread_exit(sum);
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  // Temos argumentos suficientes?
  if (argc < 4) {
    printf("Uso: %s n_threads a_file b_file\n"
           "    n_threads    número de threads a serem usadas na computação\n"
           "    *_file       caminho de arquivo ou uma expressão com a forma "
           "gen:N,\n"
           "                 representando um vetor aleatório de tamanho N\n",
           argv[0]);
    return 1;
  }

  // Quantas threads?
  int n_threads = atoi(argv[1]);
  if (!n_threads) {
    printf("Número de threads deve ser > 0\n");
    return 1;
  }
  // Lê números de arquivos para vetores alocados com malloc
  int a_size = 0, b_size = 0;
  double *a = load_vector(argv[2], &a_size);
  if (!a) {
    // load_vector não conseguiu abrir o arquivo
    printf("Erro ao ler arquivo %s\n", argv[2]);
    return 1;
  }
  double *b = load_vector(argv[3], &b_size);
  if (!b) {
    printf("Erro ao ler arquivo %s\n", argv[3]);
    return 1;
  }

  // Garante que entradas são compatíveis
  if (a_size != b_size) {
    printf("Vetores a e b tem tamanhos diferentes! (%d != %d)\n", a_size,
           b_size);
    return 1;
  }

  if (n_threads > a_size) {
    n_threads = a_size;
  }

  pthread_t threads[n_threads];
  struct args_st args[n_threads];

  for (int i = 0; i < n_threads; ++i) {
    args[i].start = i * a_size / n_threads;
    args[i].end = (i + 1) * a_size / n_threads;
    args[i].a = a;
    args[i].b = b;

    pthread_create(&threads[i], NULL, thread, (void *)&args[i]);
  }

  // Junta os produtos escalares parciais em um produto total.
  double scalar_product = 0;
  for (int i = 0; i < n_threads; ++i) {
    double *partial = NULL;
    pthread_join(threads[i], (void **)&partial);
    scalar_product += *partial;

    free(partial);
  }

  //    +---------------------------------+
  // ** | IMPORTANTE: avalia o resultado! | **
  //    +---------------------------------+
  avaliar(a, b, a_size, scalar_product);

  // Libera memória
  free(a);
  free(b);

  return 0;
}
