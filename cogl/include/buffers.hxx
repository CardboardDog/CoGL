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
};