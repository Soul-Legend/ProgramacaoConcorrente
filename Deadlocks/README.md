Exercício 1

O programa dado cria duas threads worker1 e worker2 que fazem uma operação misteriosa 20 vezes. Cada uma dessas threads soma o resultado em uma variável global e coloca um valor em uma lista, também global. Além da atualização dessas variáveis globais, as próprias operações misteriosas das threads não podem ser executadas concorrentemente. Ou seja, se worker1 está realizando sua operação (operacao_worker1()), a thread worker2 não pode executar operacao_worker2().

Ninguém sabe o que o programa faz, pois quando é executado, ele quase sempre trava. Verifique se está ocorrendo um impasse (deadlock) e, se for o caso, realize as alterações necessárias para que os impasses não ocorram.

    O arquivo helper.c não deve ser alterado!
    Não remova nem renomeie o mutex ou semáforo.

Exercício 2

O programa dado simula uma agência bancária. As contas são armazenadas em um array (veja banco.h) e contêm um identificador, um saldo e um mutex. O programa cria NUM_CAIXAS threads que executam TOTAL_TRANSFERENCIAS transferências entre as NUM_CONTAS contas existentes no banco. As transferências são geradas aleatoriamente. O caixa escolhe uma conta de origem, uma conta de destino, um valor e realiza a transferência chamando a função transferir(conta_t* origem, conta_t* destino, double valor). Qualquer transferência é permitida; se a conta de origem tiver saldo insuficiente, o cheque especial será utilizado e o saldo ficará negativo.

Para manter os saldos íntegros, a função transferir() utiliza o mutex particular de cada conta_t envolvida na transação. Afinal, se a mesma conta participar de duas transferências paralelamente, o saldo pode ser corrompido, causando o desaparecimento ou surgimento de dinheiro. Por isso, uma das transferências precisa aguardar que a outra termine antes de iniciar (ex.: se caixa 1 está transferindo valores da conta 2 para a 3, caixa 2 precisa esperar para poder transferir da conta 4 para a 3). No entanto, algo não está certo nessa função, já que o programa simulador costuma travar após poucas transferências. Você deve modificar apenas a função transferir() de modo a resolver esse problema.

    Não altere os arquivos helper.c e banco.h como parte da solução. Durante a correção, esses arquivos serão trocados pelas versões originais. 

Dicas

Use o GDB, como explicado aqui, para identificar onde estão ocorrendo os deadlocks.
Entrega do Exercício

Submeta um arquivo .tar.gz (ou zip) na mesma estrutura do esqueleto dado como ponto inicial nessa tarefa. O uso do esqueleto fornecido é obrigatório. Em especial, você deve criar suas soluções editando os arquivos dentro das pastas exercicio_*. Utilize make submission para garantir que será gerado um arquivo conforme solicitado.
