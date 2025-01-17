#include<cogl.hxx>
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"

// put image path here!
const char IMAGE_PATH[] = "example.jpg";

int main(){
    std::string fragmentCode = "#version 330 core\nout vec4 FragColor;\nin vec3 ourColor;\nin vec2 TexCoord;\nuniform sampler2D texture1;\nvoid main()\n{\n\tFragColor = texture(texture1, TexCoord);\n}";
    std::string vertexCode = "#version 330 core\nlayout (location = 0) in vec3 aPos;\nlayout (location = 1) in vec3 aColor;\nlayout (location = 2) in vec2 aTexCoord;\nout vec3 ourColor;\nout vec2 TexCoord;\nvoid main()\n{\n\tgl_Position = vec4(aPos, 1.0);\n\tourColor = aColor;\n\tTexCoord = vec2(aTexCoord.x, aTexCoord.y);\n}";
    cogl::GraphicsSystem* GSYS = new cogl::GraphicsSystem("Hello COGL");
    cogl::Shader* vertexShader = new cogl::Shader(coglVertexShader, vertexCode);
    cogl::Shader* fragmentShader = new cogl::Shader(coglFragmentShader, fragmentCode);
    cogl::ShaderProgram* shaderProgram = new cogl::ShaderProgram();
    shaderProgram->link(vertexShader);
    shaderProgram->link(fragmentShader);
    shaderProgram->compile();
    delete vertexShader; // dont need frag/vert shaders anymore
    delete fragmentShader;
    float vertices[] = { // p.x, p.y, p.z, r, g, b, uv.x, uv.y
        0.8f,0.8f,0.0f,1.0f,1.0f,0.0f,1.0f, 1.0f,
        0.8f,-0.8f,0.0f,1.0f,1.0f,0.0f,1.0f, 0.0f,
        -0.8f,-0.8f,0.0f,1.0f,1.0f,1.0f,0.0f, 0.0f,
        -0.8f,0.8f,0.0f,1.0f,1.0f,0.0f,0.0f, 1.0f
    };
    unsigned int indices[] = {0,1,3,1,2,3};
    cogl::VertexAttributeArray* VAO = new cogl::VertexAttributeArray(8);
    cogl::ArrayBuffer* VBO = new cogl::ArrayBuffer(coglVertexArray);
    cogl::ArrayBuffer* EBO = new cogl::ArrayBuffer(coglElementArray);
    VBO->setData(sizeof(vertices),&vertices);
    EBO->setData(sizeof(indices),&indices);
    VAO->addAttribute(0,3,coglFloat,false); // vertices
    VAO->addAttribute(1,3,coglFloat,false); // colors
    VAO->addAttribute(2,2,coglFloat,false); // UVs
    VAO->unbind();
    EBO->unbind();
    VBO->unbind();
    cogl::Texture* texture = new cogl::Texture(true);
    texture->set(coglTextureRepeatX,coglRepeat); // some settings
    texture->set(coglTextureRepeatY,coglRepeat);
    texture->set(coglTextureUpscale,coglLinear);
    texture->set(coglTextureDownscale,coglNearest);
    texture->set(coglTextureAutoAlgin,true);
    stbi_set_flip_vertically_on_load(1);
    int width, height, channels;
    unsigned char* data = stbi_load(IMAGE_PATH,&width,&height,&channels,0);
    if(data){
        texture->load(&data,coglRGB,width,height);
    }else std::cout << "could not load image at: "<<IMAGE_PATH<<" - "<<stbi_failure_reason()<<std::endl;
    stbi_image_free(data); // cleanup stb's data
    while(GSYS->isAlive()){ // check if the user has closed the app
        GSYS->setViewport(0,0,GSYS->width,GSYS->height);
        GSYS->clear(1.0f,0.6f,0.2f,0.0);
        texture->bind(0);
        shaderProgram->bind();
        VAO->bind();
        EBO->bind();
        GSYS->drawActiveBuffer(coglTriangles,6,coglElementArray);
        VAO->unbind();
        EBO->unbind();
        VBO->unbind();
        GSYS->swapBuffers();
        GSYS->update();
    }
    delete VBO; // you dont have to delete your objects, but it is a good practice.
    delete VAO;
    delete EBO;
    delete texture;
    delete GSYS;
}