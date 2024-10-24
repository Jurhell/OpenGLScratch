#include "Renderer.h"
#include <iostream>

void GLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    const char* severityString = "";
    switch (severity)
    {
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        severityString = "NOTIFICATION";
        break;
    case GL_DEBUG_SEVERITY_LOW:
        severityString = "LOW";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        severityString = "MEDIUM";
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        severityString = "HIGH";
        break;
    default:
        severityString = "DEBUG";
        break;
    }

    std::cout << "[OpenGL] [" << severityString << "] " << message << "\n";
    if (severity == GL_DEBUG_SEVERITY_HIGH)
        __debugbreak();
}

void GLFWErrorCallback(int error, const char* description)
{
    std::cerr << description << "\n";
}

void GLClearError()
{
    while (!glGetError);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << function <<
            " " << ";" << line << "\n";
        return false;
    }
    return true;
}
