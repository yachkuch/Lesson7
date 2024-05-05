cmake_minimum_required(VERSION 3.10.0)
project(cmdes VERSION 0.1.0 LANGUAGES C CXX)


include(CTest)
enable_testing()

set( SOURCES cmd/cmd.cpp)
set( HEAD cmd/cmd.h)

add_executable(bulk main.cpp ${HEAD} ${SOURCES} )

set_target_properties(bulk  PROPERTIES
CXX_STANDARD 20
CXX_STANDARD_REQUIRED ON
)

target_include_directories(bulk PRIVATE cmd)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
