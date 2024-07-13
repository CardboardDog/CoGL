g++ -c cogl/source/* -I cogl/include/ -lGL -lX11 -lglfw -g -Isample
g++ -o cogltest sample/main.cxx *.o -I cogl/include/ -lGL -lX11 -lglfw -g -Isample