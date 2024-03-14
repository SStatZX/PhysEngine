#include <iostream>
// #include "Vector2.h"
// #include "Vector3.h"
// #include "Matrix2x2.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>
#include "MathPhys.h"
#include "BoundingCircle.h"

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static ShaderProgramSource ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);
    
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << "\n";
        }
    }

    return { ss[0].str(), ss[1].str() };
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) 
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) 
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Harshdeep Smells", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
    /* Problem: glewInit failed, something is seriously wrong. */
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    float positions[6]={
        -0.5f, -0.5f,
         0.0f, 0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    // unsigned int VAO;
    // glGenVertexArrays(1, &VAO);
    // glBindVertexArray(VAO);

    ShaderProgramSource source = ParseShader("res/shaders/circle.shader");

    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    
    // std::cout << source.VertexSource << std::endl;
    // std::cout << source.FragmentSource << std::endl;

    // https://www.youtube.com/watch?v=71BLZwRGUJE

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);
    glfwTerminate();
    return 0;
}

void BoundingCircleTest() {
    Vector2 banana(2.0F, 3.0F);
    Vector2 apple(3.0F, -2.0F);

    // std::cout << apple.to_string() << std::endl;
    // apple.normalize();
    // std::cout << apple.to_string() << std::endl;
    // std::cout << banana.length() << std::endl;
    // std::cout << banana.dot(apple) << std::endl;
    // Vector2 product = banana * apple;
    // std::cout << product.to_string() << std::endl;

    // Vector3 cheese(2.0F, 1.0F, 4.0F);
    // Vector3 carrot(1.0F, 1.0F, 9.0F);
    // std::cout << cheese.to_string() << std::endl;
    // cheese.normalize();
    // std::cout << cheese.to_string() << std::endl;
    // std::cout << carrot.dot(cheese) << std::endl;
    // std::cout << carrot.length() << std::endl;

    // Matrix2x2 toast(1.0, 2.0, 3.0, 4.0);
    // std::cout << toast.to_string() << std::endl;

    BoundingCircle c1(banana, 4.0);
    BoundingCircle c2(apple, 3.0);


    BoundingCircle c3(banana, 1.0);
    // BoundingCircle c4(apple, 4.0);    
    Intersection inter = c1.getIntersection(c2);

    // std::string info = (c1.getIntersection(c2)).to_string();
    std::cout << "Bounding?: " << inter.to_string() << std::endl;
    // std::cout << "Bounding?: " << c2.isColliding(c3) << ", " << c2.getDistance(c3) << std::endl;
}


