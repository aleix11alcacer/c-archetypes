cmake_minimum_required(VERSION 3.16)
project(archetypes C)

set(CMAKE_C_STANDARD 99)

option(SHARED_LIB "Create shared library" ON)
option(STATIC_LIB "Create static library" ON)

if (SHARED_LIB)
    set(ARCHETYPES_LIB archetypes_shared)
elseif (STATIC_LIB)
    set(ARCHETYPES_LIB archetypes_static)
else()
    message(FATAL_ERROR "No library is created")
endif ()

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/src/*.c)

if (SHARED_LIB)
    add_library(archetypes_shared SHARED ${SRC_FILES})
    set_target_properties(archetypes_shared PROPERTIES OUTPUT_NAME archetypes)
    install(TARGETS archetypes_shared DESTINATION lib)
endif()

if (STATIC_LIB)
    add_library(archetypes_static STATIC ${SRC_FILES})
    set_target_properties(archetypes_static PROPERTIES OUTPUT_NAME archetypes)
    install(TARGETS archetypes_static DESTINATION lib)
endif()

install(FILES ${CMAKE_CURRENT_LIST_DIR}/include/* DESTINATION include)

add_subdirectory(examples)
