#include <Shader.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>

bool shaderCompilationStatus(GLuint shader, GLenum type);
bool programLinkStatus(GLuint program);

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) {
    std::string vsCode, fsCode;
    std::ifstream vsFile, fsFile;
    std::stringstream vsStream, fsStream;

    vsFile.exceptions(std::fstream::failbit | std::fstream::badbit);
    fsFile.exceptions(std::fstream::failbit | std::fstream::badbit);

    try {
        vsFile.open(vertexShaderPath);
        fsFile.open(fragmentShaderPath);

        vsStream << vsFile.rdbuf();
        fsStream << fsFile.rdbuf();

        vsFile.close();
        fsFile.close();

        vsCode = vsStream.str();
        fsCode = fsStream.str();

    } catch (std::ifstream::failure e) {
        std::cerr << "Error Reading Files:\n" << e.what() << "\n";
    };

    const char* vsSrc = vsCode.c_str();
    const char* fsSrc = fsCode.c_str();

    // Compile shaders and link program...
    GLuint vertexShader, fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vsSrc, nullptr);
    glCompileShader(vertexShader);

    if (!shaderCompilationStatus(vertexShader, GL_VERTEX_SHADER))
        exit(EXIT_FAILURE);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fsSrc, nullptr);
    glCompileShader(fragmentShader);

    if (!shaderCompilationStatus(fragmentShader, GL_FRAGMENT_SHADER))
        exit(EXIT_FAILURE);
    
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    if (!programLinkStatus(ID))
        exit(EXIT_SUCCESS);
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setVec4(glm::vec4 vec, const char* name) {
    glUniform4fv(glGetAttribLocation(ID, name), 1, glm::value_ptr(vec));
}

bool shaderCompilationStatus(GLuint shader, GLenum type) {
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);

        std::cout << "Error Compiling ";
        switch (type) {
            case GL_VERTEX_SHADER:
                std::cout << "Vertex";
                break;
            case GL_FRAGMENT_SHADER:
                std::cout << "Fragment";
                break;
        }

        std::cout << " Shader:\n" << infoLog;

        return 0;
    }

    return 1;
}

bool programLinkStatus(GLuint program) {
    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(program, 512, nullptr, infoLog);

        std::cout << "Error Linking Program:\n" << infoLog;

        return 0;
    }

    return 1;
}