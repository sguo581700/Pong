CC = g++ -g -Og -std=c++2a
COMPILER_FLAGS = -Wall
LIB_SDL2 = -framework SDL2
LIB_SDL2_IMG = -framework SDL2_image
LIB_SDL2_TTF = -framework SDL2_ttf
OBJ = Pong.cpp
DEPS = Ball.h Bat.h Background.h Player.h GameEngine.h
OBJ_NAME = Pong

all: $(OBJ) $(DEPS)
	$(CC) $(COMPILER_FLAGS) $(LIB_SDL2) $(LIB_SDL2_IMG) $(LIB_SDL2_TTF) $(OBJ) -o $(OBJ_NAME)

.phony: clean
clean:
	rm -f $(OBJ_NAME) *.o
