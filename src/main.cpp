#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Shader.h>
#include <Cube.h>

#define WIDTH 800
#define HEIGHT 600

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// TODO: Consolidate cube to its own class
// TODO: Procedural cylinder

glm::mat4 projection(1.0f);

int main(void) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, NAME, nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to Created GLFW Window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to Load GLAD\n";
        return -1;
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    Shader shader("../shaders/vertexShader.glsl", "../shaders/fragmentShader.glsl");
    shader.use();

    Cube cube(&shader);

    glm::mat4 view(1.0f);

    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    projection = glm::perspective(glm::radians(45.0f), float(WIDTH)/float(HEIGHT), 0.1f, 100.0f);


    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double time = glfwGetTime();
        double green = sin(time * 2) / 2.0f + 0.5f;
        cube.translate(glm::vec3(0.0f));
        cube.rotate(time, glm::vec3(1.0f, 0.0f, 0.0f));
        cube.scale(glm::vec3(0.5f, 1.0f, 0.5f));
        shader.setMat4(view, "view");
        shader.setMat4(projection, "projection");
        shader.setVec4(glm::vec4(0.0f, green, 0.0f, 1.0f), "inFragColor");

        cube.draw();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    projection = glm::perspective(glm::radians(45.0f), float(width)/float(height), 0.1f, 100.0f);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}