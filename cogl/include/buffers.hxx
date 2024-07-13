#include<iostream>
#include<glad/glad.h>
#include<types.hxx>
namespace cogl{
    class VertexAttributeArray{
        public:
        VertexAttributeArray(int length);
        ~VertexAttributeArray();
        void use();
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
        void draw(cogl::geometryType geometry, cogl::dataSize amount);
        void use();
        void setData(cogl::dataSize size, cogl::bufferData data);
        protected:
        unsigned int VBO;
        cogl::bufferType bufferType;
    };
};