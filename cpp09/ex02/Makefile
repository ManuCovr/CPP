NAME     = PmergeMe
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS     = main.cpp
OBJS     = $(SRCS:.cpp=.o)

export TMP  := /tmp
export TEMP := /tmp

RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
YELLOW = \033[33m
CYAN   = \033[36m
RED    = \033[31m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "$(BOLD)$(GREEN)  ✓  $(NAME) compiled successfully$(RESET)\n"

%.o: %.cpp
	@printf "$(CYAN)  →  Compiling $<...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@printf "$(YELLOW)  ✗  Objects removed$(RESET)\n"

fclean: clean
	@rm -f $(NAME) $(NAME).exe
	@printf "$(RED)  ✗  $(NAME) removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
