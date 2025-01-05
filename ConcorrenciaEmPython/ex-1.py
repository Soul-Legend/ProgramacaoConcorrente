from random import randint
from threading import Condition, Lock, Thread
from time import sleep


def produtor():
    i = 0
    while i < 10:
        sleep(randint(0, 2))  # fica um tempo produzindo...
        item = "item " + str(len(buffer))

        with lock:
            if len(buffer) == tam_buffer:
                print(">>> Buffer cheio. Produtor ira aguardar.")
                lugar_no_buffer.wait()  # aguarda que haja lugar no buffer
                continue

            buffer.append(item)
            print("Produzido %s (ha %i itens no buffer)" % (item, len(buffer)))
            item_no_buffer.notify()
            i += 1


def consumidor():
    i = 0
    while i < 10:
        with lock:
            if len(buffer) == 0:
                print(">>> Buffer vazio. Consumidor ira aguardar.")
                item_no_buffer.wait()  # aguarda que haja um item para consumir
                continue

            item = buffer.pop(0)
            print("Consumido %s (ha %i itens no buffer)" % (item, len(buffer)))
            lugar_no_buffer.notify()
            i += 1

        sleep(randint(0, 2))  # fica um tempo consumindo...


buffer = []
tam_buffer = 5
lock = Lock()
lugar_no_buffer = Condition(lock)
item_no_buffer = Condition(lock)

produtor1 = Thread(target=produtor)
produtor2 = Thread(target=produtor)
consumidor1 = Thread(target=consumidor)
consumidor2 = Thread(target=consumidor)

produtor1.start()
produtor2.start()
consumidor1.start()
consumidor2.start()

produtor1.join()
produtor2.join()
consumidor1.join()
consumidor2.join()
