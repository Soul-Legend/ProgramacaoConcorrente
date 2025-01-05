#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *out;

sem_t num_a;
sem_t num_b;

void *thread_a(void *args) {
  for (int i = 0; i < *(int *)args; ++i) {
    sem_post(&num_b);
    sem_wait(&num_a);

    fprintf(out, "A");
    fflush(stdout);
  }

  return NULL;
}

void *thread_b(void *args) {
  for (int i = 0; i < *(int *)args; ++i) {
    sem_post(&num_a);
    sem_wait(&num_b);

    fprintf(out, "B");
    fflush(stdout);
  }

  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Uso: %s [ITERAÇÕES]\n", argv[0]);
    return 1;
  }
  int iters = atoi(argv[1]);
  srand(time(NULL));
  out = fopen("result.txt", "w");

  pthread_t ta, tb;

  sem_init(&num_a, 0, 0);
  sem_init(&num_b, 0, 0);

  // Cria threads
  pthread_create(&ta, NULL, thread_a, &iters);
  pthread_create(&tb, NULL, thread_b, &iters);

  // Espera pelas threads
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);

  sem_destroy(&num_a);
  sem_destroy(&num_b);

  // Imprime quebra de linha e fecha arquivo
  fprintf(out, "\n");
  fclose(out);

  return 0;
}
