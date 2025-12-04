PLUGIN_NAME = Move
TARGET_SO = libInterp4$(PLUGIN_NAME).so

CPPFLAGS = -Wall -fPIC -pedantic -std=c++17 -Iinc -I../inc
LDFLAGS = -shared

SRC = src/Interp4$(PLUGIN_NAME).cpp
OBJ = obj/Interp4$(PLUGIN_NAME).o

__start__: obj __lines_for_space__ ../libs/$(TARGET_SO)
	@echo "  Tworzenie wtyczki $(TARGET_SO) zakonczone."
	@echo

obj:
	mkdir -p obj

__lines_for_space__:
	@echo

../libs/$(TARGET_SO): $(OBJ)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ): $(SRC)
	g++ -c $(CPPFLAGS) -o $@ $<

clean:
	rm -rf obj

cleanall: clean
	find . -name \*~ -print -exec rm {} \;