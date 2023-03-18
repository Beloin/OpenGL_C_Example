#include <stdio.h>
#include "test/test.h"
#include <glad.h>
#include <GLFW/glfw3.h>

GLFWwindow *setup();

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {

}

int main() {
    GLFWwindow *window = setup();

    float triangle[] = {
            0.4f, .5f, 0.f,
            -.1f, -.5f, 0.f,
            .9f, -.5f, 0.f,
    };


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // First triangle
        GLuint v;
        glGenBuffers(1, &v);
        glBindBuffer(GL_ARRAY_BUFFER, v);

        GLsizeiptr i = sizeof(triangle) * (sizeof(triangle) / sizeof(triangle[0]));
        glBufferData(GL_ARRAY_BUFFER, i, &triangle[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    printf("Hello, World!\n");
    PrintSmoll();
    return 0;
}

GLFWwindow *setup() {
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(640, 320, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glViewport(0, 0, 640, 320);
    glfwSetKeyCallback(window, keyCallback);
    return window;
}
