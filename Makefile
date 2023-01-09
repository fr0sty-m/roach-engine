run: compile
	./launcher.exe

compile:
	g++ -Iinclude -IC:/dev/libraries/SDL2-VSCODE/include -LC:/dev/libraries/SDL2-VSCODE/lib/x64 -o launcher src/main.cpp src/game/*.* -lSDL2main -lSDL2 -lSDL2_image