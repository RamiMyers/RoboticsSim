#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
    public:
        Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
        void setVec4(glm::vec4 vec, const char* name);
        void use();
    
    private:
        unsigned int ID;
};

#endif