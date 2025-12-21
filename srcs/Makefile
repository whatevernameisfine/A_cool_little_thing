# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riramana <riramana@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 13:20:00 by riramana          #+#    #+#              #
#    Updated: 2025/08/23 13:45:00 by riramana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS_NAME = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
LIBS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lpthread

SRCDIR = srcs
OBJDIR = obj
INCDIR = includes

SOURCES = main.c utils.c utils_2.c utils_3.c colors.c fractals.c hooks.c mouse_utils.c utils_multithreading.c
BONUS_SOURCES = main_bonus.c utils_bonus.c utils_2_bonus.c utils_3_bonus.c colors_bonus.c fractals_bonus.c hooks_bonus.c mouse_utils_bonus.c utils_multithreading_bonus.c

SRCS = $(addprefix $(SRCDIR)/, $(SOURCES))
BONUS_SRCS = $(addprefix $(SRCDIR)/, $(BONUS_SOURCES))

OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS_SOURCES:.c=.o))

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)

# Compilation pattern
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Create obj directory if not present
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Targets
bonus: $(BONUS_NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
