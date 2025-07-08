# @file:	CMakeLists.txt
# @author:	Jacob Xie
# @date:	2025/07/06 23:25:21 Sunday
# @brief:

add_library(Paw STATIC Paw.cpp)

target_include_directories(Paw PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${ABYSSINIAN_CAT_PREFIX}/include>
)

add_library(AbyssinianCat::Paw ALIAS Paw)

install(TARGETS Paw
    EXPORT AbyssinianCatTargets
    ARCHIVE DESTINATION ${ABYSSINIAN_CAT_PREFIX}/lib
)

install(FILES
    ${CMAKE_SOURCE_DIR}/include/AbyssinianCat/Cat.hpp
    ${CMAKE_SOURCE_DIR}/include/AbyssinianCat/Paw.hpp
    DESTINATION ${ABYSSINIAN_CAT_PREFIX}/include/AbyssinianCat
)
