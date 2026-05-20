#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include "Square.h"

int main()
{
    Window window(800, 800, "OpenGL");

    Renderer renderer;

    Shader shader(
        "shaders/default.vert",
        "shaders/default.frag"
    );

    Square square;

    while (window.IsOpen())
    {
        renderer.Clear();

        shader.Use();

        square.Draw();

        window.Update();
    }

    return 0;
}