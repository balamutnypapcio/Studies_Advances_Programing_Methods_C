
TRG=/tmp/prog
OBJ=${TRG}/obj
CXXFLAGS=-g -Wall -std=c++11 -pedantic -iquote inc


__start__: ${TRG}/prog
	${TRG}/prog


${TRG}/prog: ${OBJ} ${OBJ}/gtsDebug.o ${OBJ}/main.o
	g++ -o ${TRG}/prog ${OBJ}/gtsDebug.o ${OBJ}/main.o

${OBJ}:
	mkdir -p ${OBJ}

${OBJ}/gtsDebug.o: src/gtsDebug.cpp inc/gtsDebug.hh
	g++ -c ${CXXFLAGS} -o ${OBJ}/gtsDebug.o src/gtsDebug.cpp

${OBJ}/main.o: src/main.cpp inc/gtsDebug.hh
	g++ -c ${CXXFLAGS} -o ${OBJ}/main.o src/main.cpp


clean:
	rm -f ./prog ${OBJ}/*.o
