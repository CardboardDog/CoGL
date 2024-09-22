#include <glad/glad.h>
#include<types.hxx>
namespace cogl{
    class Texture{
        public:
        Texture(bool mipmaps);
        ~Texture();
        void bind(int id);
        void bind();
        void set(cogl::setting setting, GLint value);
        void set(cogl::setting setting, bool value);
        void load(unsigned char** data, cogl::colorType color, int width, int height);
        protected:
        unsigned int texture;
        bool mipmaps;
    };
}