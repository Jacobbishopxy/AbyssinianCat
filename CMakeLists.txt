# @file:	CMakeLists.txt
# @author:	Jacob Xie
# @date:	2025/07/06 22:55:28 Sunday
# @brief:

cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

###################################################################################################
# env file

# Function to read .env file
function(read_env_file env_file)
    file(STRINGS ${env_file} env_lines)
    foreach(line IN LISTS env_lines)
        # Skip comments and empty lines
        if(NOT line MATCHES "^#" AND line MATCHES "=")
            # Split into key and value
            string(REGEX REPLACE "=.*" "" key ${line})
            string(REGEX REPLACE "^[^=]*=" "" value ${line})

            # Remove surrounding quotes if present
            string(REGEX REPLACE "^[\"'](.*)[\"']$" "\\1" value ${value})

            # Set as CMake variable
            set(${key} ${value} PARENT_SCOPE)
        endif()
    endforeach()
endfunction()

# Usage
if(EXISTS "${CMAKE_SOURCE_DIR}/.env")
    read_env_file("${CMAKE_SOURCE_DIR}/.env")
endif()

###################################################################################################

set(PROJECT_VERSION ${PROJ_VER})

project(AbyssinianCat VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(ABYSSINIAN_CAT_PREFIX "/opt/AbyssinianCat-${PROJECT_VERSION}")

add_subdirectory(src/Paw)
add_subdirectory(src/Tail)

###################################################################################################

include(CMakePackageConfigHelpers)

# Version config file #1
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/AbyssinianCatConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/AbyssinianCatConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/AbyssinianCatConfig.cmake
    INSTALL_DESTINATION ${ABYSSINIAN_CAT_PREFIX_PREFIX}/lib/cmake/AbyssinianCat
)

###################################################################################################

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/AbyssinianCatConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/AbyssinianCatConfigVersion.cmake
    DESTINATION ${ABYSSINIAN_CAT_PREFIX}/lib/cmake/AbyssinianCat
)

install(EXPORT AbyssinianCatTargets
    FILE AbyssinianCatTargets.cmake
    NAMESPACE AbyssinianCat::
    DESTINATION ${ABYSSINIAN_CAT_PREFIX}/lib/cmake/AbyssinianCat
)

###################################################################################################

option(BUILD_TESTS "Build tests for the project" OFF)

if(BUILD_TESTS)
  add_subdirectory(test)
endif()
