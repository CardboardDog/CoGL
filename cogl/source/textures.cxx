#include "textures.hxx"
using namespace cogl;
Texture::Texture(bool mipmaps){
    glGenTextures(1,&this->texture);
    glBindTexture(GL_TEXTURE_2D,this->texture);
    this->mipmaps = mipmaps;
}
void Texture::load(unsigned char** data, GLenum color, int width, int height){
    glBindTexture(GL_TEXTURE_2D,this->texture);
    glTexImage2D(GL_TEXTURE_2D,0,color,width,height,0,color,GL_UNSIGNED_BYTE,*data);
    if(this->mipmaps)glGenerateMipmap(GL_TEXTURE_2D);
}
void Texture::set(GLenum setting, GLint value){
    if( setting == GL_UNPACK_ALIGNMENT  ||
        setting == GL_UNPACK_ROW_LENGTH ||
        setting == GL_UNPACK_SKIP_PIXELS||
        setting == GL_UNPACK_SKIP_ROWS ){
        glPixelStorei(setting,value);
    }else{
        glTexParameteri(GL_TEXTURE_2D,setting,value);
    }
}
void Texture::use(int id){
    glBindTexture(GL_TEXTURE_2D,this->texture);
    glActiveTexture(GL_TEXTURE0+id);
}
Texture::~Texture(){
    glDeleteTextures(1,&this->texture);
}