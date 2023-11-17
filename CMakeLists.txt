cmake_minimum_required(VERSION 3.16)
project(galton VERSION 0.1.0)

# abilita il supporto per i test, tra cui l'opzione BUILD_TESTING usata sotto
include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# richiedi l'uso di C++17, senza estensioni non-standard offerte dal compilatore usato 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# abilita warning
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")

# abilita l'address sanitizer e l'undefined-behaviour sanitizer in debug mode
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

add_executable(galton src/main.cpp src/board.cpp src/iopegs.cpp)

# se il testing e' abilitato...
# per disabilitare il testing, passare -DBUILD_TESTING=OFF a cmake durante la fase di configurazione

if (BUILD_TESTING)
  # aggiungi l'eseguibile galton.t
  add_executable(galton.t src/board.cpp src/board_test.cpp src/iopegs.cpp)

  # aggiungi l'eseguibile galton.t alla lista dei test
  add_test(NAME galton.t COMMAND galton.t)

endif()
