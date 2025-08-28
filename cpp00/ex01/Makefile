# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 12:37:31 by mde-maga          #+#    #+#              #
#    Updated: 2025/08/15 12:49:07 by mde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC       = main.cpp Contact.cpp PhoneBook.cpp
OBJ       = $(SRC:.cpp=.o)
NAME      = phonebook

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
