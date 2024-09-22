#include<glad/glad.h>
#include<string>
#include<types.hxx>
namespace cogl{
    class Shader{
        public:
        Shader(cogl::shaderType type, std::string code);
        ~Shader();
        unsigned int shader;
        protected:
        cogl::shaderType type;
    };
    class ShaderProgram{
        public:
        ShaderProgram();
        ~ShaderProgram();
        void link(Shader* shader);
        bool compile();
        void bind();
        void set(std::string variable, int value);
        void set(std::string variable, float value);
        void set(std::string variable, bool value);
        protected:
        unsigned int program;
    };
}