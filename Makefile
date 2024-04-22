CC = g++
CXXFLAGS = -g -Og -Wall -Werror -pedantic -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

OBJ = main.o PTree.o
EXECUTABLE = PTree

# Rule for compiling .cpp files to .o object files
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Rule for linking object files into the final executable
$(EXECUTABLE): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(EXECUTABLE) $(LDFLAGS)

all: $(EXECUTABLE)

lint:
	cpplint --repository=. main.cpp PTree.cpp PTree.hpp

clean:
	rm -f $(OBJ) $(EXECUTABLE)
