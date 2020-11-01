@echo off
g++ -c ./src/*.cpp ./src/UI/*.cpp -I"C:/SFML/Install/Include" -std=c++11
@echo [COMPILATION] done.
g++ *.o -o ./release/app -L"C:/SFML/Install/lib" -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
@echo [CREATION] app.exe created.
del /f *.o
@echo Both compilation and creation is done. You can run app.exe in release folder to see if your code works properly.
PAUSE