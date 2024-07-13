#include"buffers.hxx"
using namespace cogl;
VertexAttributeArray::VertexAttributeArray(int length){
    glGenVertexArrays(1,&this->VAO);
    this->addPointer = (GLintptr)0;
    this->attributeCount = length;
}
VertexAttributeArray::~VertexAttributeArray(){
    glDeleteVertexArrays(1,&this->VAO);
}
void VertexAttributeArray::use(){
    glBindVertexArray(this->VAO);
}
void VertexAttributeArray::addAttribute(GLuint index, GLint length, cogl::dataType type, bool normalized){
    GLsizei size;
    switch(type){
        case GL_FLOAT:
            size = sizeof(float)*this->attributeCount;
            break;
        case GL_UNSIGNED_INT:
        case GL_INT:
            size = sizeof(int)*this->attributeCount;
            break;
        case GL_DOUBLE:
            size = sizeof(double)*this->attributeCount;
        default:
            return;
    };
    glBindVertexArray(this->VAO);
    glVertexAttribPointer(index,length,type,(normalized)?GL_TRUE:GL_FALSE,size,(void*)this->addPointer);
    glEnableVertexAttribArray(index);
    this->addPointer+=sizeof(float)*length;
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
void ArrayBuffer::setData(cogl::dataSize size, cogl::bufferData data){
    glBindBuffer(this->bufferType,this->VBO);
    glBufferData(this->bufferType,size,data,GL_STATIC_DRAW);
}
void ArrayBuffer::use(){
    glBindBuffer(this->bufferType,this->VBO);
}
void ArrayBuffer::draw(cogl::geometryType geometry, cogl::dataSize amount){
    glBindBuffer(this->bufferType,this->VBO);
    switch(this->bufferType){
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
ArrayBuffer::~ArrayBuffer(){
    glDeleteBuffers(1,&this->VBO);
}