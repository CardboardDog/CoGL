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
ArrayBuffer::ArrayBuffer(GLenum type){
    glGenBuffers(1,&this->VBO);
    this->bufferType = type;
}
void ArrayBuffer::setData(GLsizei size, const GLvoid* data){
    glBindBuffer(this->bufferType,this->VBO);
    glBufferData(this->bufferType,size,data,GL_STATIC_DRAW);
}
void ArrayBuffer::use(){
    glBindBuffer(this->bufferType,this->VBO);
}
void ArrayBuffer::draw(GLenum geometry, GLsizei amount){
    glBindBuffer(this->bufferType,this->VBO);
    switch(this->bufferType){
        case GL_ELEMENT_ARRAY_BUFFER:
            glDrawElements(geometry,amount,GL_UNSIGNED_INT,0);
        case GL_ARRAY_BUFFER:
            glDrawArrays(geometry,0,amount);
        default:
            return;
    };
}
ArrayBuffer::~ArrayBuffer(){
    glDeleteBuffers(1,&this->VBO);
}