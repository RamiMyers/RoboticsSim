#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>

class Shader {
    public:
        Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
        void setFloat(float value, const char* name);
        void setVec4(glm::vec4 vec, const char* name);
        void use();
    
    private:
        unsigned int ID;
};

#endif