NAME    = HiThisIsBrain

SRC_DIR = src
SRC     = $(SRC_DIR)/main.cpp
CC      = @c++
CFLAGS  = -std=c++98 -Wall -Wextra -Werror

OBJ_DIR = obj
OBJS    = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

GREEN   = $'\033[1;32m'
BLUE    = $'\033[1;34m'
RESET   = $'\033[0m'

all: $(NAME)
	@echo -e "$(GREEN)*-------------------------*$(RESET)"
	@echo -e "$(GREEN)| Compilation finished!   |$(RESET)"
	@echo -e "$(GREEN)*-------------------------*$(RESET)"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo -e "$(BLUE)*------------------*$(RESET)"
	@echo -e "$(BLUE)| Cleaning done!   |$(RESET)"
	@echo -e "$(BLUE)*------------------*$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
