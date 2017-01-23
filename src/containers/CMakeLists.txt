add_library(siminusminus-containers inmutablestring.cpp)

target_include_directories(siminusminus-containers PUBLIC "${CMAKE_SOURCE_DIR}/include")

if(NOT MSVC)
    target_compile_options(siminusminus-containers PRIVATE -std=c++14 -Wall -Werror -pedantic)
endif()
