#include<iostream>
#include<glad/glad.h>
#include<types.hxx>
namespace cogl{
    class VertexAttributeArray{
        public:
        VertexAttributeArray(int length);
        ~VertexAttributeArray();
        void bind();
        void unbind();
        void addAttribute(GLuint index, GLint length, cogl::dataType type, bool normalized);
        void disableAttribute(GLuint index);
        void enableAttribute(GLuint index);
        protected:
        GLintptr addPointer = 0;
        unsigned int VAO;
        int attributeCount = 0;
    };
    class ArrayBuffer{
        public:
        ArrayBuffer(cogl::bufferType type);
        ~ArrayBuffer();
        void bind();
        void unbind();
        void setData(cogl::dataSize size, cogl::bufferData data);
        protected:
        unsigned int VBO;
        cogl::bufferType bufferType;
    };
};