#include <stdio.h>
#include <glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <math.h>
#include "time.h"
#include "src/utils/vector.h"

#define HEIGHT 800
#define WIDTH 800
#define sqrt3 ((float) sqrt(3))

// Vertex Shader source code
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
//Fragment Shader source code
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
                                   "}\n\0";

//Fragment Shader source code
const char *fragmentShaderSource02 = "#version 330 core\n"
                                     "out vec4 FragColor;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   FragColor = vec4(0.5f, 0.3f, 0.02f, 1.0f);\n"
                                     "}\n\0";


GLFWwindow *setup();

GLuint genShaderProgram01();

GLuint genShaderProgram02();

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
}

int main() {
    GLFWwindow *window = setup();

    gladLoadGL();
    glViewport(0, 0, HEIGHT, WIDTH);
    glClearColor(0.07f, 0.13f, 0.17f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Reference containers for the Vertex Array and the Vertex Buffer
    // VAO = Vertex Array Object
    // VBO = Vertex Buffer Object
    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    float vectorVertex[9];
    Vector2 p1 = CreateVector(400, 400);
    TriangleVector2 tv2 = CreateTriangle(&p1, HEIGHT, WIDTH);
    GenerateFloatArray(&tv2, vectorVertex);

    time_t t1, t0;
    time(&t0);
    t1 = t0;

    GLfloat vertices45[] =
            {
                    -0.5f, -0.5f * sqrt3 / 3, 0.0f, // Lower left corner
                    0.5f, -0.5f * sqrt3 / 3, 0.0f, // Lower right corner
                    0.0f, 0.5f * sqrt3 * 2 / 3, 0.0f // Upper corner
            };

    GLuint shaderProgram01 = genShaderProgram01();
    GLuint shaderProgram02 = genShaderProgram02();
    int fps = 0;
    while (!glfwWindowShouldClose(window)) {
        fps++;
        if (t1 - t0 > 0) {
            printf("FPS: %d\n", fps);
            time(&t0);
            fps = 0;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glEnableVertexAttribArray(0);

        glUseProgram(shaderProgram01);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vectorVertex), vectorVertex, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();

        time(&t1);
    }


    glDeleteVertexArrays(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram01);
    glDeleteProgram(shaderProgram02);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

GLuint genShaderProgram01() {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

GLuint genShaderProgram02() {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource02, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

GLFWwindow *setup() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

    GLFWwindow *window = glfwCreateWindow(HEIGHT, WIDTH, "OpenGL", NULL, NULL);
    if (window == NULL) {
        exit(1);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    return window;
}
