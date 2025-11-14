# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabi-mou <aabi-mou@student.42beirut.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 22:17:03 by aabi-mou          #+#    #+#              #
#    Updated: 2025/11/12 22:18:09 by aabi-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

# Default target
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)


# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

# Full clean (including library)
fclean: clean
	$(RM) $(NAME)

# Recompile from scratch
re: fclean all

.PHONY: all clean fclean re bonus
