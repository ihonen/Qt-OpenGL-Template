#include "Engine.h"

#include <GL/gl3w.h>

#include <stdio.h>
#include <stdlib.h>

void Engine_init()
{
    switch (gl3wInit())
    {
    case GL3W_OK:
        printf("INFO   GL3W: Successfully loaded OpenGL functions\n");
        break;
    case GL3W_ERROR_INIT:
        fprintf(stderr, "FATAL  GL3W: Failed to load OpenGL functions (GL3W_ERROR_INIT)\n");
        abort();
        break;
    case GL3W_ERROR_LIBRARY_OPEN:
        fprintf(stderr, "FATAL  GL3W: Failed to load OpenGL functions (GL3W_ERROR_LIBRARY_OPEN)\n");
        abort();
        break;
    case GL3W_ERROR_OPENGL_VERSION:
        fprintf(stderr, "FATAL  GL3W: Failed to load OpenGL functions (GL3W_ERROR_OPENGL_VERSION)\n");
        abort();
        break;
    }

    printf("ASD\n");
}

void Engine_render()
{
    
}
