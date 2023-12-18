cmake_minimum_required(VERSION 3.4...3.18)
project(alpha_zero_env)

# PYTHON_EXECUTABLE is set by cmake/pybind11.cmake
message(STATUS "Python executable: ${PYTHON_EXECUTABLE}")

execute_process(
  COMMAND "${PYTHON_EXECUTABLE}" -c "import torch; print(torch.utils.cmake_prefix_path)"
  OUTPUT_STRIP_TRAILING_WHITESPACE
  OUTPUT_VARIABLE TORCH_DIR
)

message(STATUS "TORCH_DIR: ${TORCH_DIR}")

list(APPEND CMAKE_PREFIX_PATH "${TORCH_DIR}")
find_package(Torch REQUIRED)
message(STATUS "TORCH_INCLUDE_DIRS: ${TORCH_INCLUDE_DIRS}")
include_directories(${TORCH_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_subdirectory(pybind11)
pybind11_add_module(alpha_zero_env src/main.cpp)

target_link_libraries(alpha_zero_env PRIVATE "${TORCH_LIBRARIES}")

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(alpha_zero_env PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else()
  set(CMAKE_CXX_STANDARD 17)
endif (MSVC)
