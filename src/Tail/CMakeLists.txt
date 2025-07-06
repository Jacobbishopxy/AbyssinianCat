# @file:	CMakeLists.txt
# @author:	Jacob Xie
# @date:	2025/07/06 23:25:31 Sunday
# @brief:

add_library(Tail STATIC Tail.cpp)

target_include_directories(Tail PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${ABYSSINIAN_CAT_PREFIX}/include>
)

add_library(AbyssinianCat::Tail ALIAS Tail)

install(TARGETS Tail
    EXPORT AbyssinianCatTargets
    ARCHIVE DESTINATION ${ABYSSINIAN_CAT_PREFIX}/lib
)

install(FILES
    ${CMAKE_SOURCE_DIR}/include/AbyssinianCat/Cat.hpp
    ${CMAKE_SOURCE_DIR}/include/AbyssinianCat/Tail.hpp
    DESTINATION ${ABYSSINIAN_CAT_PREFIX}/include/AbyssinianCat
)
