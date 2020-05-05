SET(GCC_EXTRA_COMPILE_FLAGS " -Wl,--no-undefined")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_EXTRA_COMPILE_FLAGS}")

find_package(Threads REQUIRED)
include(FindPkgConfig)
pkg_check_modules(gmodule-2.0 REQUIRED IMPORTED_TARGET gmodule-2.0)

set(MYLIB_HEADERS ${CMAKE_SOURCE_DIR}/include/mylibrary.hpp)
set(MYLIB_SOURCES mylibrary.cpp)

add_library (studygmodule SHARED ${MYLIB_HEADERS} ${MYLIB_SOURCES})
target_link_libraries(studygmodule PkgConfig::gmodule-2.0)
