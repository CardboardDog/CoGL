#include"graphics.hxx"
using namespace cogl;
GraphicsSystem* cogl::__current_graphics_system__ = NULL;
GraphicsSystem::GraphicsSystem(std::string name){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    this->window = glfwCreateWindow(COGL_SCREEN_WIDTH,COGL_SCREEN_HEIGHT,name.c_str(),NULL,NULL);
    __current_graphics_system__ = this;
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,__resize_callback__);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    this->width = COGL_SCREEN_WIDTH;
    this->height = COGL_SCREEN_HEIGHT;
}
GraphicsSystem::~GraphicsSystem(){
    __current_graphics_system__ = NULL;
    glfwDestroyWindow(this->window);
    glfwTerminate();
}
void GraphicsSystem::clear(float r, float g, float b, float a){
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
}
void GraphicsSystem::clear(cogl::clearBuffer buffer){
    glClear(buffer);
}
void GraphicsSystem::swapBuffers(){
    glfwSwapBuffers(this->window);
}
void GraphicsSystem::update(){
    glfwPollEvents();
}
void GraphicsSystem::setViewport(GLint x, GLint y, GLint width, GLint height){
    glViewport(x,y,width,height);
}
void GraphicsSystem::set(cogl::setting setting, bool value){
    if(value){
        glEnable(setting);
    }else{
        glDisable(setting);
    }
}
bool GraphicsSystem::isAlive(){
    return !glfwWindowShouldClose(this->window);
}
void GraphicsSystem::drawActiveBuffer(cogl::geometryType geometry, cogl::dataSize amount, cogl::dataType type){
    switch(type){
        case GL_ELEMENT_ARRAY_BUFFER:
            glDrawElements(geometry,amount,GL_UNSIGNED_INT,0);
            break;
        case GL_ARRAY_BUFFER:
            glDrawArrays(geometry,0,amount);
            break;
        default:
            return;
    };
}
void cogl::__resize_callback__(GLFWwindow* rWindow, int width, int height){
    if(__current_graphics_system__){
        __current_graphics_system__->width = width;
        __current_graphics_system__->height = height;
    }
}
