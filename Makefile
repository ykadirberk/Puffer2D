FIRST_POS = ./src/*.cpp
INCLUDE_DIR = -I"C:/SFML/Install/Include"
COMPILER_INST = -std=c++11 -Os
STATIC_LINKING = -static -static-libgcc -static-libstdc++
OBJECTS_POS = *.o
DESTINATION_POS =./release/app
LIBRARY_DIR = -L"C:/SFML/Install/lib"
LINKING_INST = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
all: $(FIRST_POS)
	g++ -c $(FIRST_POS) $(INCLUDE_DIR) $(COMPILER_INST)
	g++ $(STATIC_LINKING) $(OBJECTS_POS) -g -o $(DESTINATION_POS) $(LIBRARY_DIR) $(LINKING_INST)
	del $(OBJECTS_POS)