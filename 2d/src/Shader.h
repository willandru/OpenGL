#pragma once

#include <string>

class Shader
{
private:

    unsigned int ID;

    std::string LoadFile(
        const char* path
    );

public:

    Shader(
        const char* vertexPath,
        const char* fragmentPath
    );

    void Use();
};