GCC = g++
GCC_FLAGS = -I include -std=c++11 -Wall # -Wall - recompilar todos os arquivos 
PROGRAMA = diary
ARQUIVOS_PROGRAMA: App.o Date.o Diary.o HoraDataAtual.o main.o Time.o

all: Diary $(PROGRAMA)

$(PROGRAMA): $(ARQUIVOS_PROGRAMA)
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) $(ARQUIVOS_PROGRAMA)

App.o: src/App.cpp include/App.h # se mudar algo no .h vai atualizar
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

HoraDataAtual.o: src/HoraDataAtual.cpp include/HoraDataAtual.h
	$(GCC) $(GCC_FLAGS) -c src/HoraDataAtual.cpp

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

# make clean no terminal - Excluir arquivos .o.
clean:
	rm *.o 

#não dar conflito com arquivos que sejam criados com mesmo nome  
.PHONY: all clean