#include<glad/glad.h>
namespace cogl{
    typedef GLsizei dataSize;
    typedef GLbitfield clearBuffer;
    typedef unsigned char* textureData;
    typedef const void* bufferData;
    typedef GLenum setting;
    typedef GLenum colorType;
    typedef GLenum shaderType;
    typedef GLenum bufferType;
    typedef GLenum geometryType;
    typedef GLenum dataType;
}
#define coglTriangles GL_TRIANGLES
#define coglQuads GL_QUADS
#define coglVertexShader GL_VERTEX_SHADER
#define coglFragmentShader GL_FRAGMENT_SHADER
#define coglTextureRepeatX GL_TEXTURE_WRAP_S
#define coglTextureRepeatY GL_TEXTURE_WRAP_T
#define coglTextureUpscale GL_TEXTURE_MAG_FILTER
#define coglTextureDownscale GL_TEXTURE_MIN_FILTER
#define coglTextureAutoAlgin GL_UNPACK_ALIGNMENT
#define coglRepeat GL_REPEAT
#define coglNearest GL_NEAREST
#define coglLinear GL_LINEAR
#define coglTrue GL_TRUE
#define coglFalse GL_FALSE
#define coglRGB GL_RGB
#define coglRGBA GL_RGBA
#define coglR GL_R
#define coglElementArray GL_ELEMENT_ARRAY_BUFFER
#define coglVertexArray GL_ARRAY_BUFFER
#define coglFloat GL_FLOAT
#define coglInt GL_INT
#define coglDouble GL_DOUBLE
#define coglUnsignedInt GL_UNSIGNED_INT
#define coglGeometryMode GL_FRONT_AND_BACK
#define coglWireframe GL_LINE
#define coglFull GL_FILL
#define coglDepthTesting GL_DEPTH_TEST
#define coglAlways GL_ALWAYS
#define coglNever GL_NEVER
#define coglLess GL_LESS
#define coglGreater GL_GREATER
#define coglCulling GL_CULL_FACE
#define coglBack GL_BACK
#define coglFront GL_FRONT
#define coglDither GL_DITHER // dithering will be ignored on platforms with 32bit color
#define coglModelView GL_MODELVIEW
#define coglProjection GL_PROJECTION
#define coglDepthBuffer GL_DEPTH_BUFFER_BIT
#define coglColorBuffer GL_COLOR_BUFFER_BIT
#define coglStencilBuffer GL_STENCIL_BUFFER_BIT