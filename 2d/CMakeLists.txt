cmake_minimum_required(VERSION 3.10)

project(OpenGL2D)

set(CMAKE_CXX_STANDARD 17)

# =========================================
# GLFW
# =========================================

add_subdirectory(external/glfw)

# =========================================
# Executable
# =========================================

add_executable(OpenGL2D

    src/main.cpp

    src/Window.cpp
    src/Renderer.cpp
    src/Shader.cpp
    src/Square.cpp

    external/glad/src/glad.c
)

# =========================================
# Includes
# =========================================

target_include_directories(OpenGL2D PRIVATE

    external/glad/include
    external/glfw/include

    src
)

# =========================================
# Link
# =========================================

target_link_libraries(OpenGL2D

    glfw
)