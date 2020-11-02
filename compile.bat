@echo off
g++ -c ./src/*.cpp ./src/UI/*.cpp -I"C:/SFML/Install/Include" -std=c++11
@echo [COMPILATION] done.
g++ *.o -o ./release/app -L"C:/SFML/Install/lib" -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
@echo [CREATION] app.exe created.
del /f *.o
PAUSE