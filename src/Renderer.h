#pragma once
#include <GL/glew.h>

#pragma region ChernoErrorCall
    //Macros for Cherno's error call
#define ASSERT(x) if(!(x)) __debugbreak()
#define GLCall(x) GLClearError();\
x;\
ASSERT(GLLogCall(#x, __FILE__, __LINE__))

    //Cherno's error call functions
    static void GLClearError();
    static bool GLLogCall(const char* function, const char* file, int line);
#pragma endregion

    void GLDebugCallback(
        GLenum source,      //unsigned int
        GLenum type,        //unsigned int
        GLuint id,          //unsigned int
        GLenum severity,    //unsigned int
        GLsizei length,     //int
        const GLchar* message,    //string
        const void* userParam);

    void GLFWErrorCallback(int error, const char* description);
