#include<glad/glad.h>
#include<string>
namespace cogl{
    class Shader{
        public:
        Shader(GLenum type, std::string code);
        ~Shader();
        unsigned int shader;
        protected:
        GLenum type;
    };
    class ShaderProgram{
        public:
        ShaderProgram();
        ~ShaderProgram();
        void link(Shader* shader);
        bool compile();
        void use();
        void set(std::string variable, int value);
        void set(std::string variable, float value);
        void set(std::string variable, bool value);
        protected:
        unsigned int program;
    };
}