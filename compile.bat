g++ -c ./src/*.cpp -I"C:/SFML/Install/Include" -std=c++11
g++ *.o -o ./release/app -L"C:/SFML/Install/lib" -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
del /f *.o
PAUSE