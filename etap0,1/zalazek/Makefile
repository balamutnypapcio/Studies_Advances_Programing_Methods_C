all: run

# Cel 'run' najpierw buduje wszystko ('build'), a potem uruchamia
run: build
	@echo
	@echo "--- Uruchamianie programu ---"
	@LD_LIBRARY_PATH=$(PWD)/libs ./interp

# Cel 'build' odpowiada za całą kompilację
build: interp __plugin__

obj:
	@mkdir -p obj

libs:
	@mkdir -p libs

__plugin__: libs
	@(cd plugin; make)
	@(cd plugin_rotate; make)
	@(cd plugin_set; make)
	@(cd plugin_pause; make)


CPPFLAGS=-Wall -pedantic -std=c++17 -Iinc
LDFLAGS=-Wall -lxerces-c -ldl


OBJS = obj/main.o obj/LibInterface.o obj/preprocessor.o obj/xmlinterp.o obj/ComChannel.o obj/Configuration.o obj/Scene.o obj/Interpreter.o obj/AbstractComChannel.o

${OBJS}: | obj

interp: ${OBJS}
	g++ -o $@ $(filter %.o,$^) ${LDFLAGS}


obj/main.o: src/main.cpp inc/Configuration.hh inc/LibInterface.hh inc/preprocessor.hh inc/ComChannel.hh inc/Port.hh inc/Interpreter.hh inc/Scene.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/LibInterface.o: src/LibInterface.cpp inc/LibInterface.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/preprocessor.o: src/preprocessor.cpp inc/preprocessor.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/xmlinterp.o: src/xmlinterp.cpp inc/xmlinterp.hh inc/Configuration.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/Configuration.o: src/Configuration.cpp inc/Configuration.hh inc/xmlinterp.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/ComChannel.o: src/ComChannel.cpp inc/ComChannel.hh inc/AbstractComChannel.hh inc/Port.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/AbstractComChannel.o: src/AbstractComChannel.cpp inc/AbstractComChannel.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/Scene.o: src/Scene.cpp inc/Scene.hh inc/AbstractScene.hh
	g++ -c ${CPPFLAGS} -o $@ $<

obj/Interpreter.o: src/Interpreter.cpp inc/Interpreter.hh inc/LibInterface.hh inc/ComChannel.hh inc/Scene.hh
	g++ -c ${CPPFLAGS} -o $@ $<


doc:
	cd dox; make

clean:
	rm -f obj/* interp core*

clean_plugin:
	(cd plugin; make clean)
	(cd plugin_rotate; make clean)
	(cd plugin_set; make clean)
	(cd plugin_pause; make clean)

cleanall: clean clean_plugin
	rm -r -f obj libs
	find . -name \*~ -print -exec rm {} \;

help:
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "  make          - kompilacja i uruchomienie programu (to samo co 'make all' lub 'make run')."
	@echo "  make build    - tylko kompiluje program i wtyczki."
	@echo "  make clean    - usuwa produkty kompilacji."
	@echo "  clean_plugin  - usuwa wtyczki."
	@echo "  cleanall      - wykonuje 'clean' i 'clean_plugin' oraz usuwa kopie zapasowe."
	@echo "  help          - wyswietla niniejszy komunikat."