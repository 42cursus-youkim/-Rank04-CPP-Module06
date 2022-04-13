NAME := convert
CXX  := c++
CXXFLAGS := -g -Wall -Wextra -Werror -std=c++98 -pedantic -Iinclude/

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:%.cpp=%.o)

.PHONY: run re clean

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

all: $(NAME)
re: clean all
run: all
	@for num in '0' 'nan' '42.0f'; do\
		echo [[case $$num]];\
		./$(NAME) $$num;\
	done

test: all
	pytest --tests-per-worker auto

clean:
	$(RM) $(wildcard $(OBJ)) $(NAME)

leak: all
	colour-valgrind --leak-check=full ./$(NAME)
