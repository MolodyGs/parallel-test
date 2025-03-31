# Establece la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(parallel)

# Especifica el estándar de C++ a utilizar
set(CMAKE_CXX_STANDARD 11)

# Buscar OpenMP
find_package(OpenMP REQUIRED)

# Agrega los archivos fuente para compilar el proyecto
add_executable(parallel src/Parallel.cpp)

# Incluir las flags necesarias para OpenMP
if(OpenMP_CXX_FOUND)
  target_compile_options(parallel PRIVATE ${OpenMP_CXX_FLAGS})
  target_link_libraries(parallel PRIVATE ${OpenMP_CXX_LIBRARIES})
endif()

set_target_properties(parallel PROPERTIES WIN32_EXECUTABLE OFF)