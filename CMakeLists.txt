cmake_minimum_required(VERSION 3.16)
project(Babushka_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Babushka_2 main.cpp)

include_directories(LexicalAnalysis)
add_subdirectory(lib/LexicalAnalysis)

target_link_libraries(Babushka_2 LexicalAnalysis_lib)

include_directories(GeneralType)
add_subdirectory(lib/GeneralType)

target_link_libraries(Babushka_2 GeneralType_lib)
