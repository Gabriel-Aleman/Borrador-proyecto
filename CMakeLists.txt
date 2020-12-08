cmake_minimum_required(VERSION 3.10)
project(examen VERSION 1.0
              DESCRIPTION "Proyecto"
              LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

set(sources
  src/main.c
  src/menu.c)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(proyecto ${sources})

install (TARGETS proyecto DESTINATION bin)