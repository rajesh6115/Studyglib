SET(GCC_EXTRA_COMPILE_FLAGS " -Wl,--no-undefined")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_EXTRA_COMPILE_FLAGS}")

find_package(Threads REQUIRED)
include(FindPkgConfig)
pkg_check_modules(gmodule-2.0 REQUIRED IMPORTED_TARGET gmodule-2.0)

add_executable(GModuleEx main.cpp)
target_link_libraries(GModuleEx PkgConfig::gmodule-2.0)

