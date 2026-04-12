CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = *.cpp
OBJ = $(SRC:.cpp=.o)

app: $(OBJ)
	$(CXX) $(OBJ) -o app

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o app