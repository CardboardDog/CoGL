#include <glad/glad.h>
namespace cogl{
    class Texture{
        public:
        Texture(bool mipmaps);
        ~Texture();
        void use(int id);
        void use();
        void set(GLenum setting, GLint value);
        void set(GLenum setting, bool value);
        void load(unsigned char** data, GLenum color, int width, int height);
        protected:
        unsigned int texture;
        bool mipmaps;
    };
}