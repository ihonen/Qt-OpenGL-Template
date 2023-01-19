#include "Renderer.h"

#include <GL/gl3w.h>

#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
// This example is based on "Hello Triangle" from learnopengl.com.
// -----------------------------------------------------------------------------

struct Renderer
{
    unsigned VAO;
    unsigned VBO;

    unsigned vertexShader;
    unsigned fragmentShader;
    unsigned shaderProgram;
};

// -----------------------------------------------------------------------------

static const char* VertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

static const char* FragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

// -----------------------------------------------------------------------------

struct Renderer* Renderer_new()
{
    struct Renderer* self = calloc(1, sizeof(struct Renderer));
    if (!self)
    {
        fprintf(stderr, "FATAL: Failed to allocat memory\n");
        abort();
    }

    return self;
}

void Renderer_init(struct Renderer* self)
{
    if (gl3wInit() != GL3W_OK)
    {
        fprintf(stderr, "FATAL: Failed to load OpenGL functions\n");
        abort();
    }

    // Vertex shader
    {
        self->vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(self->vertexShader, 1, &VertexShaderSource, NULL);
        glCompileShader(self->vertexShader);

        int success;        
        glGetShaderiv(self->vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetShaderInfoLog(self->vertexShader, 512, NULL, infoLog);
            fprintf(stderr, "FATAL: Failed to compile vertex shader:\n%s\n", infoLog);
            abort();
        }
    }

    // Fragment shader
    {
        self->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(self->fragmentShader, 1, &FragmentShaderSource, NULL);
        glCompileShader(self->fragmentShader);

        int success;
        glGetShaderiv(self->fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetShaderInfoLog(self->fragmentShader, 512, NULL, infoLog);
            fprintf(stderr, "FATAL: Failed to compile fragment shader:\n%s\n", infoLog);
            abort();
        }
    }

    // Shader program
    {
        self->shaderProgram = glCreateProgram();
        glAttachShader(self->shaderProgram, self->vertexShader);
        glAttachShader(self->shaderProgram, self->fragmentShader);
        glLinkProgram(self->shaderProgram);
        glDeleteShader(self->vertexShader);
        glDeleteShader(self->fragmentShader);

        int success;
        glGetProgramiv(self->shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetProgramInfoLog(self->shaderProgram, 512, NULL, infoLog);
            fprintf(stderr, "FATAL: Failed to link shaders:\n%s\n", infoLog);
            abort();
        }
    }

    // Vertex buffer
    {
        const float triangleVertices[] = {
            -0.5f, -0.5f, 0.0f, // left  
             0.5f, -0.5f, 0.0f, // right 
             0.0f,  0.5f, 0.0f, // top   
        };

        glGenVertexArrays(1, &self->VAO);
        glGenBuffers(1, &self->VBO);
        glBindVertexArray(self->VAO);

        glBindBuffer(GL_ARRAY_BUFFER, self->VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        glBindVertexArray(0); 
    }
}

void Renderer_free(struct Renderer* self)
{
    free(self);
}

void Renderer_doRender(struct Renderer* self)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(self->shaderProgram);
    glBindVertexArray(self->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

void Renderer_setViewPort(struct Renderer* self, int x, int y, int w, int h)
{
    glViewport(x, y, w, h);
}
