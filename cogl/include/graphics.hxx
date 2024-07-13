#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#define COGL_SCREEN_WIDTH 400
#define COGL_SCREEN_HEIGHT 400
namespace cogl{
    extern void __resize_callback__(GLFWwindow* rWindow, int width, int height);
    class GraphicsSystem{
        public:
        GraphicsSystem(std::string name);
        ~GraphicsSystem();
        void clear(float r, float g, float b, float a);
        void clear(GLbitfield buffer);
        void swapBuffers();
        void setDisplay(int display);
        void setViewport(GLint x, GLint y, GLsizei width, GLsizei height);
        void set(GLenum setting, bool value);
        void update();
        bool isAlive();
        int width;
        int height;
        protected:
        GLFWwindow* window;
    };
    extern GraphicsSystem* __current_graphics_system__;
}