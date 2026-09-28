#ifndef CUBE_H
#define CUBE_H

#include <Shader.h>

class Cube {
    public:
        Cube(Shader* shader);
        void draw();

    private:
        unsigned int VBO, VAO;
        float* vertices;
        Shader* shader;
};

#endif