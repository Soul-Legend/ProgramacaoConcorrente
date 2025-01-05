Exercício 1

O programa dado no esqueleto cria duas threads, uma para imprimir letras A e outra para imprimir letras B em um arquivo chamado results.txt. Ao ser invocado o comando abaixo, no qual 5 é o número de letras A e letras B:

./program 5

Seria gerado algo assim no arquivo result.txt:

AAAAABBBBB

Utilize semáforos para que as threads executem em paralelo, mas garantindo que em qualquer posição i da string, a diferença entre o número de A's e de B's seja menor ou igual a 1. Veja alguns exemplos de saídas válidas ou inválidas com 3 ocorrências de cada letra:

    Válidas: 
        ABABAB
        ABBAAB
        BAABAB
    Inválidas:
        AABBAB (posição i=1: #A=2, #B=0)
        ABBBAB (posição i=3: #A=1, #B=3)
        BBBAAA (posição i=1: #A=0, #B=2)

Exercício 2

Em 2099, após um ataque terrorista, as pontes Pontes Pedro Ivo e Colombo Salles caíram, restando apenas a ponte Hercílio Luz. Como a Hercílio Luz estava novamente reforma, ela não podia suportar tráfego com segurança. No entanto, dada a excepcionalidade da situação, as autoridades liberaram a passagem de até veiculos_turno veículos de passeio por vez, em mão única. Sua empresa venceu uma licitação para implementar o controle de tráfego na ponte. A ponte deve alternar o sentido de passagem dos veículos, permitindo a passagem de veiculos_turno veículos em cada direção, iniciando pela direção CONTINENTE → ILHA.

Cada veículo é representado por uma estrutura do tipo veiculo_t, que contém como atributos um identificador único (id), a próxima cabeceira da ponte pela qual ele vai passar (cabeceira) e sua thread (thread), e seu comportamento básico já foi implementado na função veiculo_executa(void *arg). Porém, as principais funções de controle de acesso à ponte não foram implementadas. Uma breve descrição do funcionamento destas funções é mostrada abaixo:

    ponte_inicializar(): Função executada no início do programa para inicializar o controle da ponte. É invocada uma única vez pela função main().
    ponte_entrar(veiculo_t *v): Função invocada pelo veículo (v) para indicar que o veículo está querendo entrar em uma cabeceira da ponte.
    void ponte_sair(veiculo_t *v): Função invocada pelo veículo (v) para indicar que o veículo está querendo sair em uma cabeceira da ponte.
    ponte_finalizar(): Função executada no final do programa para finalizar o controle da ponte. É invocada uma única vez pela função main().

Nenhum veículo tentará sair pela mesma cabeceira que entrou. Apenas após veiculos_turno veículos concluirem a travessia em um sentido é que travessias no sentido oposto serão permitidas (novamente limitadas a veiculos_turno veículos). Abaixo é mostrada uma possível saída esperada para uma execução com 16 veículos e 4 veículos por turno (./program 16 4):

[PONTE] *** Novo sentido da travessia: CONTINENTE -> ILHA. ***

[Veiculo   0] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo   0] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo   1] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo   2] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo   2] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo   3] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo   4] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo   4] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo   5] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo   6] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo   6] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo   7] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo   8] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo   9] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo  10] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo  11] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo  12] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo  13] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo  14] Aguardando para entrar na ponte pelo(a) CONTINENTE.
[Veiculo  15] Aguardando para entrar na ponte pelo(a) ILHA.
[Veiculo   0] SAIU da ponte pelo(a) ILHA.
[Veiculo   2] SAIU da ponte pelo(a) ILHA.
[Veiculo   4] SAIU da ponte pelo(a) ILHA.
[Veiculo   6] SAIU da ponte pelo(a) ILHA.

[PONTE] *** Novo sentido da travessia: ILHA -> CONTINENTE. ***

[Veiculo   1] ENTROU na ponte pelo(a) ILHA.
[Veiculo   3] ENTROU na ponte pelo(a) ILHA.
[Veiculo   5] ENTROU na ponte pelo(a) ILHA.
[Veiculo   7] ENTROU na ponte pelo(a) ILHA.
[Veiculo   5] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo   7] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo   3] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo   1] SAIU da ponte pelo(a) CONTINENTE.

[PONTE] *** Novo sentido da travessia: CONTINENTE -> ILHA. ***

[Veiculo   8] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo  10] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo  12] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo  14] ENTROU na ponte pelo(a) CONTINENTE.
[Veiculo   8] SAIU da ponte pelo(a) ILHA.
[Veiculo  10] SAIU da ponte pelo(a) ILHA.
[Veiculo  12] SAIU da ponte pelo(a) ILHA.
[Veiculo  14] SAIU da ponte pelo(a) ILHA.

[PONTE] *** Novo sentido da travessia: ILHA -> CONTINENTE. ***

[Veiculo   9] ENTROU na ponte pelo(a) ILHA.
[Veiculo  11] ENTROU na ponte pelo(a) ILHA.
[Veiculo  13] ENTROU na ponte pelo(a) ILHA.
[Veiculo  15] ENTROU na ponte pelo(a) ILHA.
[Veiculo   9] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo  13] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo  11] SAIU da ponte pelo(a) CONTINENTE.
[Veiculo  15] SAIU da ponte pelo(a) CONTINENTE.

[PONTE] *** Novo sentido da travessia: CONTINENTE -> ILHA. ***

[PONTE] FIM!

No exemplo de saída acima, são criados 8 veículos do lado do CONTINENTE e 8 veículos do lado da ILHA (16 no total). Como o número de veículos permitidos a trafegar por turno (veiculos_turno) é 4, são necessários 4 turnos para que todos os 16 veículos atravessem a ponte.

Inicialmente, os veículos 0, 2, 4 e 6 (em azul) foram liberados para fazer a travessia, pois a direção inicial de travessia era CONTINENTE → ILHA. Por outro lado, os veículos 1, 3, 5 e 7 (em vermelho) aguardavam no outro lado da ponte até que o sentido da travessia fosse invertido (esses veículos desejam fazer a travessia no sentido ILHA → CONTINENTE). Quando todos os veículos do primeiro turno saíram da ponte, o sentido de travessia da ponte foi invertido, liberando assim os veículos do próximo turno (1, 3, 5 e 7) para fazerem a travessia. A mesma lógica é aplicada para os demais veículos da execução: em cada turno, 4 veículos são liberados e quando os mesmos saem da ponte o sentido da travessia é invertido. A simulação acaba após todos os 16 veículos terem terminado.

Você poderá declarar variáveis globais (fora das funções), mas não poderá alterar a função main() e nem remover ou adicionar printf(). Adicione o código necessário de forma a realizar o controle correto de acesso dos veículos à ponte.
Entrega do Exercício

Submeta um arquivo .tar.gz (ou zip) na mesma estrutura do esqueleto dado como ponto inicial nessa tarefa. O uso do esqueleto fornecido é obrigatório. Em especial, você deve criar suas soluções editando os arquivos dentro das pastas exercicio_*. Utilize make submission para garantir que será criado um arquivo conforme solicitado.
