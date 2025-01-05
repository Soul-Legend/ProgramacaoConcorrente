Exercício 1

Utilize um pthread_mutex_t para proteger a região crítica do código do Exercício 1 da atividade prática anterior, em que um contador era acessado concorrentemente por várias threads, resultando em um valor inconsistente. O mutex deve ser utilizado de modo a controlar a concorrência entre as threads, fazendo com que o programa apresente o resultado esperado. 

Você precisará das seguintes funções:

    pthread_mutex_lock() e pthread_mutex_unlock()
    pthread_mutex_init()
    pthread_mutex_destroy()

Exercício 2

Um estagiário escreveu um programa paralelo de multiplicação de matrizes. Para gerar e multiplicar 2 matrizes 40 x 40 usando 2 threads, o programa é chamado assim:

./program 40 2

Quando o programa é executado com uma thread apenas, tudo funciona. Mas quando o programa é chamado com 2 threads ou mais, há erros no resultado.

O estagiário não teve disciplina de programação concorrente antes, e por isso não usou nenhum mutex. Conserte o código do estagiário inserindo um mutex e o utilizando nos pontos adequados do arquivo main.c e no arquivo thread.c. Preserve ao máximo o paralelismo!

Importante:

    A seção crítica que precisa ser sincronizada está na função matrix_mult_worker (em thread.c).
    Inicialize e destrua o mutex na função main (em main.c).
    O arquivo helper.c não poderá ser alterado.

Exercício 3

Um engenheiro fez um programa que funcionava em um computador antigo que, infelizmente, queimou. Ao rodar o programa em um computador moderno, o programa apenas trava e não faz nada. Arqueólogos  e outros estudiosos se debruçaram sobre o código-fonte e observaram o seguinte:

    O programa recebe como primeiro argumento um número de threads. Os argumentos subsequentes são argumentos da função compute, a ser executada por cada uma das threads com o argumento correspondente.
    O programa faz uso de mutex e sincroniza o acesso a uma variável global chamada gValue.
    Quando executado, o programa fica travado para sempre.
    De acordo com o código-fonte, a intenção do engenheiro seria de que, ao ser chamado com os argumentos 2 16 17, o programa produzisse o seguinte resultado:

    $ ./program 2 16 17
    results[0]: 987 
    results[1]: 1597

    Estudiosos determinaram que os cálculos feitos pelo programa estão corretos, mas há um erro no uso do mutex gMtx.

Encontre esse erro e o corrija.

Importante:

    O arquivo helper.c não poderá ser alterado.
    Hás três abordagens possíveis para solucionar o problema:
        Você pode alterar a forma como o mutex é usado, de modo que o programa não trave. Essa solução resolve o problema, mas é questionável. Se a adotar, pense nas consequências.
        Outra opção é usar um mutex recursivo. Este tipo de mutex permite que uma thread que já é dona do mutex  faça um segundo lock sem travar. Para liberar o mutex, a thread deve fazer um unlock para cada lock feito.
            Essa é a solução mais "fácil".
            Para criar um mutex recursivo, use o argumento pthread_mutexattr_t attr no pthread_mutex_init().
                Aloque uma variável attrs do tipo pthread_mutexattr_t; 
                Inicialize attrs usando pthread_mutexattr_init(&attrs); 
                Sete o tipo do mutex para PTHREAD_MUTEX_RECURSIVE usando pthread_mutexattr_settype() (se tiver dificuldades para fazê-lo, consulte essa página e essa outra); 
                Inicialize o mutex com os atributes em attrs usando pthread_mutex_init(); 
                Por fim, destrua attrs usando pthread_mutexattr_destroy().
        A função compute() pode ser reescrita de modo que nenhum mutex seja necessário no programa. Essa solução aproveita melhor o paralelismo!

Entrega do Exercício

Submeta um arquivo .tar.gz (ou zip) na mesma estrutura do esqueleto dado como ponto inicial nessa tarefa. O uso do esqueleto fornecido é obrigatório. Em especial, você deve criar suas soluções editando os arquivos dentro das pastas exercicio_*. Utilize make submission para garantir que o arquivo terá o formato solicitado.
