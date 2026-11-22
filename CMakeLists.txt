cmake_minimum_required(VERSION 3.24)
project(Tienda3D LANGUAGES C CXX)

include(FetchContent)
set(FREEGLUT_BUILD_SHARED_LIBS OFF CACHE BOOL "Build FreeGLUT DLL")
set(FREEGLUT_BUILD_STATIC_LIBS ON CACHE BOOL "Build static FreeGLUT")
set(FREEGLUT_BUILD_DEMOS OFF CACHE BOOL "Build FreeGLUT demos")
FetchContent_Declare(
    freeglut
    URL https://codeload.github.com/freeglut/freeglut/zip/refs/tags/v3.8.0
    URL_HASH SHA256=66c12fbf41ef5da34a386d59dbd389e30b601124937f8edb81a30a5006247f93
)
FetchContent_MakeAvailable(freeglut)

# The version resource is unnecessary in a static library and MinGW windres
# can fail to preprocess it when the project path contains accented letters.
if(MINGW)
    get_target_property(freeglut_sources freeglut_static SOURCES)
    list(REMOVE_ITEM freeglut_sources "${CMAKE_BINARY_DIR}/freeglut.rc")
    set_property(TARGET freeglut_static PROPERTY SOURCES "${freeglut_sources}")
endif()

find_package(OpenGL REQUIRED)
add_executable(Tienda3D main.cpp glm.cpp Texture.cpp)
target_include_directories(Tienda3D PRIVATE "${freeglut_SOURCE_DIR}/include")
target_compile_features(Tienda3D PRIVATE cxx_std_11)
target_link_libraries(Tienda3D PRIVATE freeglut_static OpenGL::GL OpenGL::GLU)
if(MINGW)
    target_compile_options(Tienda3D PRIVATE $<$<CONFIG:Release>:-O2>)
    target_link_options(Tienda3D PRIVATE -static-libgcc -static-libstdc++)
endif()
