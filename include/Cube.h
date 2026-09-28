#ifndef CUBE_H
#define CUBE_H

#include <Shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Cube {
    public:
        Cube(Shader* shader);
        void translate(glm::vec3 vec);
        void rotate(float radians, glm::vec3 axis);
        void scale(glm::vec3 vec);
        void draw();

    private:
        glm::mat4 model;
        unsigned int VBO, VAO;
        float* vertices;
        Shader* shader;
};

#endif