# --- Konfiguracja ---
CPPFLAGS = -Wall -pedantic -std=c++17 -Iinc
LDFLAGS = -Wall -ldl -lxerces-c

# Automatyczne znajdowanie wszystkich plików źródłowych w katalogu src/
SRCS = $(wildcard src/*.cpp)
# Zamiana listy plików .cpp na listę plików .o w katalogu obj/
OBJS = $(SRCS:src/%.cpp=obj/%.o)
# Nazwa pliku wykonywalnego
TARGET_EXEC = interp

__start__: obj __lines_for_space__ __plugins__ interp
	@echo
	@echo "Kompilacja zakonczona. Uruchom program recznie, np:"
	@echo "./interp config/config.xml polecenia_etap_3.txt"
	@echo "lub uzyj 'make run'"
	@echo

run:
	export LD_LIBRARY_PATH="./libs"; ./interp config/config.xml polecenia_etap_3.txt

obj:
	mkdir -p obj

__lines_for_space__:
	@echo
	@echo
	@echo
	@echo
	@echo

__plugins__:
	cd plugin_move; make
	cd plugin_pause; make
	cd plugin_rotate; make
	cd plugin_set; make

# Linkowanie głównego programu wykonywalnego
$(TARGET_EXEC): $(OBJS)
	g++ -o $(TARGET_EXEC) $(OBJS) $(LDFLAGS)

# Reguła kompilacji dla wszystkich plików .cpp z src/ do obj/
obj/%.o: src/%.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
doc:
	cd dox; make

clean:
	rm -f obj/* $(TARGET_EXEC) core*

clean_plugins:
	cd plugin_move; make clean
	cd plugin_pause; make clean
	cd plugin_rotate; make clean
	cd plugin_set; make clean


clean_plugin:
	cd plugin_move; make clean

cleanall: clean
	cd plugin_move; make cleanall
	cd plugin_rotate; make cleanall
	cd plugin_set; make cleanall
	cd plugin_pause; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
