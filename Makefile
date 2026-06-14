CXX = g++
CXXFLAGS = -std=c++20 -Wall -Iinclude

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=build/%.o)

app: $(OBJ)
	$(CXX) $(OBJ) -o app

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build app