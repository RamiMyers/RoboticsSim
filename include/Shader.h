#ifndef SHADER_H
#define SHADER_H

class Shader {
    public:
        Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
        ~Shader();
    
    private:
        unsigned int ID;
};

#endif