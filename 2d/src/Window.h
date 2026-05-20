#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:

    GLFWwindow* window;

public:

    Window(int width, int height, const char* title);

    bool IsOpen();

    void Update();

    GLFWwindow* GetNativeWindow();

    ~Window();
};
