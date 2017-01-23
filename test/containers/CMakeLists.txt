add_executable(containers-test main.cpp inmutablestring_test.cpp)

target_include_directories(containers-test PRIVATE "${CMAKE_SOURCE_DIR}/include")

if(NOT MSVC)
    target_compile_options(containers-test PRIVATE -std=c++14 -Wall -Werror -pedantic)
endif()

target_link_libraries(containers-test PRIVATE siminusminus-containers CONAN_PKG::googlemock)

add_test(containers-test containers-test)
