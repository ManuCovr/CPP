NAME = Template

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp 

CC = c++
CCFLAGS = -std=c++98 -Wall -Wextra -Werror -g

OBJ_DIR = obj
OBJS = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

GREEN   = $'\033[1;32m'
BLUE    = $'\033[1;34m'
RESET   = $'\033[0m'

MSG1 = @echo -e "${GREEN}Compiled Successfully ✔︎${RESET}"
MSG2 = @echo -e "${GREEN}Cleaned Successfully ✔︎${RESET}"
MSG3 = @echo -e "${GREEN}Cleaned ${NAME} Successfully ✔︎${RESET}"
HOWTO = @echo -e "${BLUE}To run the program write:./${NAME} [ARGUMENT]${RESET}"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CCFLAGS) -o $(NAME)
	$(MSG1)
	$(HOWTO)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(OBJ_DIR)
	$(MSG2)
	
fclean: clean
	@rm -f $(NAME)
	$(MSG3)

re: fclean all

.PHONY:         all clean fclean re
