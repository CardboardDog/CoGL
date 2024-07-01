#include<iostream>
#include<glad/glad.h>
namespace cogl{
    class VertexAttributeArray{
        public:
        VertexAttributeArray(int length);
        ~VertexAttributeArray();
        void use();
        void addAttribute(GLuint index, GLint length, GLenum type, bool normalized);
        void disableAttribute(GLuint index);
        void enableAttribute(GLuint index);
        protected:
        GLintptr addPointer = 0;
        unsigned int VAO;
        int attributeCount = 0;
    };
    class ArrayBuffer{
        public:
        ArrayBuffer(GLenum type);
        ~ArrayBuffer();
        void draw(GLenum geometry, GLsizei amount);
        void use();
        void setData(GLsizei size, const void* data);
        protected:
        unsigned int VBO;
        GLenum bufferType;
    };
};