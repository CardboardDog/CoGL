#include "shaders.hxx"
using namespace cogl;
Shader::Shader(GLenum type, std::string code){
    this->type = type;
    this->shader = glCreateShader(type);
    const char* shaderCode = code.c_str();
    glShaderSource(this->shader,1,&shaderCode,0);
    glCompileShader(this->shader);
}
Shader::~Shader(){
    glDeleteShader(this->shader);
}
ShaderProgram::ShaderProgram(){
    this->program = glCreateProgram();
}
void ShaderProgram::link(Shader* shader){
    glAttachShader(this->program,shader->shader);
}
bool ShaderProgram::compile(){
    int compiled;
    glLinkProgram(this->program);
    glGetProgramiv(this->program,GL_COMPILE_STATUS,&compiled);
    return (bool)compiled;
}
void ShaderProgram::use(){
    glUseProgram(this->program);
}
void ShaderProgram::set(std::string variable, int value){
    glUniform1i(glGetUniformLocation(this->program,variable.c_str()),value);
}
void ShaderProgram::set(std::string variable, float value){
    glUniform1f(glGetUniformLocation(this->program,variable.c_str()),value);
}
void ShaderProgram::set(std::string variable, bool value){
    glUniform1i(glGetUniformLocation(this->program,variable.c_str()),value);
}
ShaderProgram::~ShaderProgram(){
    glDeleteProgram(this->program);
}