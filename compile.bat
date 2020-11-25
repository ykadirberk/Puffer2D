@echo off
g++ -c ./src/*.cpp -I"C:/SFML/Install/Include" -std=c++11 -Os
@echo [COMPILATION] done.
g++ *.o -g -o ./release/app -L"C:/SFML/Install/lib" -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -Os
@echo [CREATION] app.exe created.
del /f *.o
PAUSE