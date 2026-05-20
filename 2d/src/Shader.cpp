#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

std::string Shader::LoadFile(
    const char* path
)
{
    std::ifstream file(path);

    std::stringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
}

Shader::Shader(
    const char* vertexPath,
    const char* fragmentPath
)
{
    std::string vertexCode =
        LoadFile(vertexPath);

    std::string fragmentCode =
        LoadFile(fragmentPath);

    const char* vShaderCode =
        vertexCode.c_str();

    const char* fShaderCode =
        fragmentCode.c_str();

    unsigned int vertexShader;

    vertexShader =
        glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(
        vertexShader,
        1,
        &vShaderCode,
        NULL
    );

    glCompileShader(vertexShader);

    unsigned int fragmentShader;

    fragmentShader =
        glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(
        fragmentShader,
        1,
        &fShaderCode,
        NULL
    );

    glCompileShader(fragmentShader);

    ID = glCreateProgram();

    glAttachShader(ID, vertexShader);

    glAttachShader(ID, fragmentShader);

    glLinkProgram(ID);

    glDeleteShader(vertexShader);

    glDeleteShader(fragmentShader);
}

void Shader::Use()
{
    glUseProgram(ID);
}