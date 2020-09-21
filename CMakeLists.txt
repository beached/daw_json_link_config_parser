cmake_minimum_required(VERSION 3.17)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)

include( FetchContent )
set( FETCHCONTENT_UPDATES_DISCONNECTED ON )
FetchContent_Declare(
        daw_json_link
        GIT_REPOSITORY https://github.com/beached/daw_json_link
        GIT_TAG release
)
FetchContent_MakeAvailable(daw_json_link)

add_executable(untitled4 main.cpp config.h config_json.h config.cpp)
target_link_libraries( untitled4 daw::json_link )