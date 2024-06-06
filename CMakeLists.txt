cmake_minimum_required(VERSION 3.15.0)
project(task1 VERSION 0.1.0 LANGUAGES C CXX)



find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)
include_directories(OpenCV_LIBS)
include_directories( ${OPENSSL_INCLUDE_DIR})

add_executable(task1 task1.cpp)
add_library(HashVotes STATIC HashVotes.cpp)
add_library(hashfile STATIC hashfile.hpp hashfile.cpp)
add_library(caeser STATIC caeser.hpp caeser.cpp)

target_link_libraries(hashfile ${OPENSSL_LIBRARIES})
target_link_libraries(caeser ${OpenCV_LIBS})
target_link_libraries(task1 HashVotes hashfile caeser ${OpenCV_LIBS} ${OPENSSL_LIBRARIES})

