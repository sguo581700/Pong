CC = g++ -std=c++2a
COMPILER_FLAGS = -Wall
SDL2 = -framework SDL2 -framework SDL2_image -framework SDL2_ttf
LINKER_FLAGS = $(SDL2) -F /Library/Frameworks -I /Library/Frameworks/SDL2.framework/Versions/A/Headers
OBJ = Pong.cpp
DEPS = Ball.h Bat.h Background.h Player.h 
OBJ_NAME = Pong

all: $(OBJ) $(DEPS)
	$(CC) $(COMPILER_FLAGS) $(SDL2) $(OBJ) -o $(OBJ_NAME)

.phony: clean
clean:
	rm -f $(OBJ_NAME) *.o
