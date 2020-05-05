SET(GCC_EXTRA_COMPILE_FLAGS " -fpermissive ")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_EXTRA_COMPILE_FLAGS}")

include(FindPkgConfig)
pkg_check_modules(gstreamer-1.0 REQUIRED IMPORTED_TARGET gstreamer-1.0)
add_executable(HelloGstreamer main.cpp)
target_link_libraries(HelloGstreamer PkgConfig::gstreamer-1.0)