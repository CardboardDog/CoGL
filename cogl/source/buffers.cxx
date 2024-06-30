#include"buffers.hxx"
using namespace cogl;
VertexAttributeArray::VertexAttributeArray(int length){
    glGenVertexArrays(1,&this->VAO);
    this->addPointer = 0;
    this->attributeCount = length;
}
VertexAttributeArray::~VertexAttributeArray(){
    glDeleteVertexArrays(1,&this->VAO);
}
void VertexAttributeArray::use(){
    glBindVertexArray(this->VAO);
}
void VertexAttributeArray::addAttribute(GLuint index, GLint length, GLenum type, bool normalized){
    GLsizei size;
    switch(type){
        case GL_FLOAT:
            size = sizeof(float)*length;
            break;
        case GL_UNSIGNED_INT:
        case GL_INT:
            size = sizeof(int)*length;
            break;
        case GL_DOUBLE:
            size = sizeof(double)*length;
        default:
            return;
    };
    glBindVertexArray(this->VAO);
    glVertexAttribPointer(index,length,type,(normalized)?GL_TRUE:GL_FALSE,sizeof(float)*this->attributeCount,(void*)this->addPointer);
    glEnableVertexAttribArray(index);
    this->addPointer+=size;
}
void VertexAttributeArray::enableAttribute(GLuint index){
    glBindVertexArray(this->VAO);
    glEnableVertexAttribArray(index);   
}
void VertexAttributeArray::disableAttribute(GLuint index){
    glBindVertexArray(this->VAO);
    glDisableVertexAttribArray(index);   
}