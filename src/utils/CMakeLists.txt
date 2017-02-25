add_library(siminusminus-utils debugutilities.cpp)

target_include_directories(siminusminus-utils PUBLIC "${CMAKE_SOURCE_DIR}/include")

if(NOT MSVC)
    target_compile_options(siminusminus-utils PRIVATE -std=c++14 -Wall -Werror -pedantic)
endif()
