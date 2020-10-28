@echo off
g++ -c ./src/main.cpp -I"C:/SFML/Install/Include"
g++ main.o -o ./release/app -L"C:/SFML/Install/lib" -lsfml-graphics -lsfml-window -lsfml-system
del /f main.o