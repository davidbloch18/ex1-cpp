CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
SRC = main.cpp graph.cpp algorithms.cpp ds.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main
TEST_EXEC = test
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

test: $(TEST_EXEC)

$(TEST_EXEC): test.cpp graph.cpp algorithms.cpp ds.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	./$(TEST_EXEC)

valgrind: $(EXEC)
	$(VALGRIND) ./$(EXEC)

clean:
	rm -f $(OBJ) $(EXEC) $(TEST_EXEC)
