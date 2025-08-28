# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 14:30:32 by mde-maga          #+#    #+#              #
#    Updated: 2025/08/26 10:34:06 by mde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS      = Account.cpp tests.cpp
OBJS      = $(SRCS:.cpp=.o)
NAME      = bank
RM        = rm -f

ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Bank executable is ready boss."

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "All object files cleaned boss."

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable cleaned boss."

re: fclean all

.PHONY: all clean fclean re
