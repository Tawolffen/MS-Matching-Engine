cmake_minimum_required(VERSION 3.16)
project(MatchingEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# --- Biblioteca com a lógica da engine (para ser usada pelo app e pelos testes) ---
add_library(engine_lib
  src/domain/order.cpp
  src/engine/order_book.cpp
  src/engine/matcher.cpp
  src/cli/parser.cpp
)
target_include_directories(engine_lib PUBLIC src)

# --- Executável principal (REPL) ---
add_executable(matching_engine
  src/main.cpp
  src/cli/repl.cpp
)
target_link_libraries(matching_engine PRIVATE engine_lib)

# --- Testes (Catch2, baixado automaticamente via FetchContent) ---
option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
  )
  FetchContent_MakeAvailable(Catch2)
  list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

  enable_testing()

  add_executable(unit_tests
    tests/test_parser.cpp
    tests/test_matcher.cpp
    tests/test_priority.cpp
    tests/test_pegged.cpp
  )
  target_link_libraries(unit_tests PRIVATE engine_lib Catch2::Catch2WithMain)

  include(CTest)
  include(Catch)
  catch_discover_tests(unit_tests)
endif()
