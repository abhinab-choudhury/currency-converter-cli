cmake_minimum_required(VERSION 4.0)
project(currency_converter_cli)

set(CMAKE_CXX_STANDARD 20)

find_package(CURL REQUIRED)

add_executable(currency_converter_cli
        src/Main.cpp
        src/Menu.cpp
        src/CurrencyConverter.cpp
        src/HttpClient.cpp
)

target_include_directories(currency_converter_cli PRIVATE src/include)

# Link libcurl
target_link_libraries(currency_converter_cli PRIVATE CURL::libcurl)
