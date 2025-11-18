# Wymagana minimalna wersja CMake
cmake_minimum_required(VERSION 3.10)

# Nazwa projektu i język
project(InterpreterProject CXX)

# Ustawienie standardu C++17 i flag kompilatora
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

# --- Automatyczne Znajdowanie Bibliotek ---
# Znajdź bibliotekę Xerces-C (koniec z ręcznym -lxerces-c)
find_package(XercesC REQUIRED)
# Znajdź bibliotekę do obsługi wątków (dla std::thread)
find_package(Threads REQUIRED)

# Lista plików źródłowych dla głównego programu
set(INTERP_SOURCES
    src/main.cpp
    src/LibInterface.cpp
    src/preprocessor.cpp
    src/xmlinterp.cpp
    src/ComChannel.cpp
    src/Configuration.cpp
    src/Scene.cpp
    src/AbstractComChannel.cpp
    src/Interpreter.cpp   
)

# Zdefiniuj plik wykonywalny "interp"
add_executable(interp ${INTERP_SOURCES})

# Określ, gdzie program ma szukać plików nagłówkowych (.hh)
target_include_directories(interp PUBLIC inc)

# --- Automatyczne Linkowanie Bibliotek ---
# Połącz program 'interp' z wymaganymi bibliotekami
target_link_libraries(interp PUBLIC
    XercesC::XercesC      # Biblioteka Xerces-C
    Threads::Threads      # Biblioteka wątków
    dl                    # Biblioteka do dlopen
)

# --- Obsługa Podkatalogów (Wtyczek) ---
# Powiedz CMake, żeby poszedł do tych katalogów i poszukał tam
# kolejnych plików CMakeLists.txt
add_subdirectory(plugin)
add_subdirectory(plugin_rotate)
add_subdirectory(plugin_set)
add_subdirectory(plugin_pause)

# --- Ustawienie ścieżki do bibliotek podczas uruchamiania (RPATH) ---
# To jest "magia", która rozwiązuje problem z LD_LIBRARY_PATH raz na zawsze!
set(CMAKE_INSTALL_RPATH "${CMAKE_BINARY_DIR}/libs")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# --- Kopiowanie plików konfiguracyjnych i poleceń ---
# To polecenie skopiuje cały katalog 'config' do katalogu 'build/config'
# oraz plik 'polecenia.txt' do 'build/polecenia.txt'
file(COPY
    config
    polecenia.txt
  DESTINATION ${CMAKE_BINARY_DIR}
)