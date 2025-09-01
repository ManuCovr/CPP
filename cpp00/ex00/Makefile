CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC       = megaphone.cpp
OBJ       = $(SRC:.cpp=.o)
NAME      = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "It's ready to run boss."

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "All clean boss."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable file cleaned boss."

re: fclean all

.PHONY: all clean fclean re
