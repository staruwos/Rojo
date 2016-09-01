COMPILER_FLAGS = -O2 -w -std=gnu++11 -g

LINKER_FLAGS = -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
SRC_PATH = src/
LIBS_PATH = src/libs/

EXEC_NAME = Rojo

run: build
	@./$(EXEC_NAME)

build: 
	@g++ -o $(EXEC_NAME) $(SRC_PATH)system.cpp $(SRC_PATH)physics.cpp $(SRC_PATH)input.cpp $(SRC_PATH)graphics.cpp $(SRC_PATH)texture.cpp $(SRC_PATH)player_rojo.cpp $(SRC_PATH)main.cpp $(SRC_PATH)objectmanager.cpp  $(SRC_PATH)text.cpp $(LIBS_PATH)inih.o $(LIBS_PATH)Inih.o  $(COMPILER_FLAGS) $(LINKER_FLAGS)


clean:
	@rm -f $(EXEC_NAME)
