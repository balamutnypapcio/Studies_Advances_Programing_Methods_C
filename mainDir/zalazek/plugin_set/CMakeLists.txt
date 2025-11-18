# Plik: zalazek/plugin_rotate/CMakeLists.txt

# Nazwa tej konkretnej wtyczki
set(PLUGIN_NAME "Set")

# Zdefiniuj bibliotekę współdzieloną (SHARED library -> .so)
add_library(Interp4${PLUGIN_NAME} SHARED
    src/Interp4${PLUGIN_NAME}.cpp
)

# Określ, gdzie wtyczka ma szukać plików nagłówkowych
# (w swoim lokalnym 'inc' oraz w głównym 'inc' projektu)
target_include_directories(Interp4${PLUGIN_NAME} PUBLIC
    inc
    ../inc
)

# Określ, gdzie ma zostać umieszczony finalny plik .so
set_target_properties(Interp4${PLUGIN_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs"
)