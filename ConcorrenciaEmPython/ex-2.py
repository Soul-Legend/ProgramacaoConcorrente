from random import randint
from threading import Semaphore, Thread
from time import sleep


def produtor():
    for i in range(10):
        sleep(randint(0, 2))  # fica um tempo produzindo...
        item = "item " + str(i)

        # verifica se há lugar no buffer
        vazio.acquire()
        buffer.append(item)
        print("Produzido %s (ha %i itens no buffer)" % (item, len(buffer)))
        cheio.release()


def consumidor():
    for _ in range(10):
        # aguarda que haja um item para consumir
        cheio.acquire()
        item = buffer.pop(0)
        print("Consumido %s (ha %i itens no buffer)" % (item, len(buffer)))
        vazio.release()

        sleep(randint(0, 2))  # fica um tempo consumindo...


buffer = []
tam_buffer = 3

cheio = Semaphore(0)
vazio = Semaphore(tam_buffer)

# cria semáforos
produtor = Thread(target=produtor)
consumidor = Thread(target=consumidor)

produtor.start()
consumidor.start()

produtor.join()
consumidor.join()
