add_executable(messages-test main.cpp message_test.cpp)

target_include_directories(messages-test PRIVATE "${CMAKE_SOURCE_DIR}/include")

if(NOT MSVC)
    target_compile_options(messages-test PRIVATE -std=c++14 -Wall -Werror -pedantic)
endif()

# target_link_libraries(messages-test PRIVATE siminusminus-messages siminusminus-utils CONAN_PKG::googlemock)
target_link_libraries(messages-test PRIVATE siminusminus-utils CONAN_PKG::googlemock)

add_test(messages-test messages-test)
