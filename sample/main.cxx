#include<cogl.hxx>
int main(){
    cogl::GraphicsSystem* GSYS = new cogl::GraphicsSystem("Hello COGL");
    while(GSYS->isAlive()){
        GSYS->setViewport(0,0,GSYS->width,GSYS->height);
        GSYS->clear(0.5,0.5,0.0,0.0);
        GSYS->swapBuffers();
        GSYS->update();
    }
    delete GSYS;
}