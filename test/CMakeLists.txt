# @file:	CMakeLists.txt
# @author:	Jacob Xie
# @date:	2025/07/08 15:14:06 Tuesday
# @brief:


cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

find_package(AbyssinianCat REQUIRED PATHS /opt/AbyssinianCat-0.0.0)
message(STATUS "Found AbyssinianCat: ${AbyssinianCat_DIR}")

add_executable(test_paw test_paw.cpp)
target_link_libraries(test_paw PRIVATE AbyssinianCat::Paw)

add_executable(test_tail test_tail.cpp)
target_link_libraries(test_tail PRIVATE AbyssinianCat::Tail)
