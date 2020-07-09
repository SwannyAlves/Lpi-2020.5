GCC = g++
GCC_FLAGS = -I include -std=c++11 -g
PROGRAMA = banco

all: $(PROGRAMA)

$(PROGRAMA): conta.o main.o cliente.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) conta.o main.o cliente.o

Conta.o: src/conta.cpp include/Agencia.hpp
	$(GCC) $(GCC_FLAGS) -c src/conta.cpp

Main.o: src/main.cpp include/Cliente.hpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Main.o: src/cliente.cpp include/Conta.hpp
	$(GCC) $(GCC_FLAGS) -c src/cliente.cpp

clean:
	rm *.o banco	