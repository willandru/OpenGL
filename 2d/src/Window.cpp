#include "Window.h"

#include <iostream>

Window::Window(
    int width,
    int height,
    const char* title
)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(
        GLFW_OPENGL_PROFILE,
        GLFW_OPENGL_CORE_PROFILE
    );

    window = glfwCreateWindow(
        width,
        height,
        title,
        NULL,
        NULL
    );

    if (window == NULL)
    {
        std::cout << "Failed to create window\n";

        glfwTerminate();

        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
    }

    glViewport(0, 0, width, height);
}

bool Window::IsOpen()
{
    return !glfwWindowShouldClose(window);
}

void Window::Update()
{
    glfwPollEvents();

    glfwSwapBuffers(window);
}

Window::~Window()
{
    glfwDestroyWindow(window);

    glfwTerminate();
}