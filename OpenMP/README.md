Usando OpenMP

Para que seja possível usar os #pragmas do OpenMP é necessário usar uma flag especial de compilação: -fopenmp. No Makefile essa flag já está ativada, na variável CFLAGS:

CFLAGS=-fopenmp

Para usar as funções do runtime OpenMP (aquelas que começam com omp_) será necessário um #include:

#include <omp.h>

O número de threads a ser usado por um programa OpenMP pode ser definido de várias formas:

    Variável de ambiente OMP_NUM_THREADS
    Chamada da função omp_set_num_threads(novo_valor)
    Cláusula num_threads(valor), usada em um #pragma omp paralell

As alternativas subsequentes sobrescrevem as anteriores. Se OPENMP_NUM_THREADS=8, e a função omp_set_num_threads(16) é chamada, serão usadas 16 threads.

Além dos slides, você pode precisar da documentação do OpenMP 4.0.

Exercício 1

Um engenheiro escreveu o programa presente no arquivo main.c. Só o engenheiro sabe o que esse código faz, mas você pode observar que cada iteração do for é independente de todas as demais. Utilize OpenMP para paralelizar esse programa.

O programa lê o número de threads e o tamanho do vetor a ser calculado como argumentos de linha de comando. A implementação em OpenMP deve usar o número de threads indicado na variável n_threads. O programa também inclui uma medida do tempo gasto realizando o cálculo. Compute o speedup do seu programa executando-o com diferentes números de threads.
Exercício 2

O programa fornecido inicializa duas matrizes quadradas com o tamanho fornecido como argumento de linha de comando e as multiplica. Esse programa foi paralelizado com OpenMP por um estagiário. O cliente ligou enfurecido para o suporte dizendo que o programa não está tão rápido quanto deveria, e que ele produz resultados incorretos. Arrume o(s) erro(s) cometido(s) pelo estagiário de modo que o cliente fique satisfeito. Além disso, pense se a configuração das diretivas usadas pelo estagiário pode ser modificada de forma a melhorar o desempenho da solução.

Uma vez resolvido o problema, explique para o estagiário o que ele fez de errado (texto fornecido direto no Moodle, durante a submissão). Seja didático, para que o estagiário compreenda o problema e não volte a cometer o mesmo erro...
Exercício 3

O programa fornecido calcula o desvio padrão de uma sequência de números gerados aleatoriamente. O tamanho da sequência é lido como argumento da linha de comando. Paralelize a computação realizada pela função standard_deviation() usando OpenMP.
Entrega do Exercício

Submeta um arquivo .tar.gz (ou zip) na mesma estrutura do esqueleto dado como ponto inicial nessa tarefa. O uso do esqueleto fornecido é obrigatório. Em especial, você deve criar suas soluções editando os arquivos dentro das pastas exercicio_*. Utilize make submission para garantir que será gerado um arquivo conforme solicitado.
