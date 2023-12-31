cmake_minimum_required(VERSION 3.13)

project(TimeLapse)

add_executable(TimeLapse TimeLapse.cpp)

find_package(OpenCV REQUIRED)

target_include_directories(TimeLapse PUBLIC ${OpenCV_INCLUDE_DIRS})

target_link_libraries(TimeLapse ${OpenCV_LIBS})


