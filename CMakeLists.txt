cmake_minimum_required(VERSION 3.0)

project(fast-fourier-transform C CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/src.wsjcpp/CMakeLists.txt)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${fast-fourier-transform_SOURCE_DIR})

# include header dirs
list (APPEND WSJCPP_INCLUDE_DIRS "src")

list (APPEND WSJCPP_SOURCES "src/main.cpp")
list (APPEND WSJCPP_SOURCES "src/fast_fourier_transform_wiki.h")
list (APPEND WSJCPP_SOURCES "src/fast_fourier_transform_wiki.cpp")

#### BEGIN_WSJCPP_APPEND
#### END_WSJCPP_APPEND

include_directories(${WSJCPP_INCLUDE_DIRS})

add_executable (fast-fourier-transform ${WSJCPP_SOURCES})

target_link_libraries(fast-fourier-transform ${WSJCPP_LIBRARIES})

install(
    TARGETS
        fast-fourier-transform
    RUNTIME DESTINATION
        /usr/bin
)

