Essa atividade é dividida em dois exercícios sobre processos.
Exercício 1

Você deve escrever um programa em C em que o processo pai crie 2 processos filhos (fork()). 

Para cada processo filho criado, o processo pai deve imprimir "Processo pai criou XXX", onde XXX é o PID do processo criado.

Cada processo filho deve apenas imprimir "Processo filho XXX criado", onde XXX é o PID do processo corrente (use a função getpid() para isso).

O processo pai (e apenas ele) deve imprimir "Processo pai finalizado!", somente após os filhos terminarem (use a função wait() para aguardar que os filhos terminem de executar).
Exercício 2

Você deve escrever um programa C em que:

    O processo principal crie 2 processos filhos.
    Cada um dos processos filhos deve, por sua vez, criar mais três processos.
    Cada processo filho (tanto do processo principal quanto dos criados no passo anterior) deve imprimir "Processo XXX, filho de YYY", onde XXX é o PID do processo em questão e YYY o PID do processo que o criou (use as funções getpid() e getppid() para isso).
    Os processos netos (filhos dos filhos do processo principal) devem, após imprimir esta mensagem, aguardar 5 segundos antes de terminar (use a função sleep() para isso) 
    Os processos que criaram filhos devem aguardar que seus filhos terminem de executar (utilize a função wait()).
    Todos os processos filhos devem imprimir, ao finalizar, "Processo XXX finalizado", onde XXX é o PID do processo em questão. O processo principal deve imprimir "Processo principal XXX finalizado", onde XXX é o PID do processo principal.

Atenção

    Você deve fazer uma chamada da função wait() ou waitpid() para cada processo filho criado. Esta função deve ser chamada somente depois de todos os filhos do processo em questão terem sido criados. 
    Você deve garantir que os printfs estão como solicitado e na ordem solicitada
        Há uma lista dos printfs no começo de cada arquivo .c
        A função printf não imprime imediatamente na saída, mas sim em um buffer. O seu uso em conjunto com fork() pode gerar duplicidade de prints na tela. Para resolver isso, utilize a função fflush(stdio) antes de um novo fork() sempre que houverem printfs realizados anteriormente.

Dicas

    Perdido com o fork()? Consulte essa animação aqui.
    Há desenhos em ASCII dentro dos arquivos .c iniciais que complementam a especificação.
    A função exit(<status>) pode ser usada para encerrar um processo em qualquer ponto do código. O uso dessa função não é obrigatório.
    Para tornar o código mais legível, crie funções separadas para cada tipo de processo filho (uma função para filhos do processo principal, outra função para filhos dos filhos do processo principal).
    Você vai precisar das seguintes bibliotecas em seu código:

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
Entrega do Exercício

Crie um arquivo .tar.gz criado usando o comando make submission e depois envie o arquivo criado pelo Moodle. O uso do esqueleto fornecido é obrigatório. Em especial, você deve criar suas soluções editando os arquivos dentro das pastas exercicio_*.
