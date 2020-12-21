# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:27:16 by tvanessa          #+#    #+#              #
#    Updated: 2020/12/19 19:32:47 by tvanessa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

debug := 1

Fsrcs := fsrcs
FH := fhdr
SS := $(shell cat $(Fsrcs))
CHEADERS := $(shell cat $(FH))
OBJD := obj
SRCD := srcs
FTPRTFD := ft_printf/
OBJS := $(SS:.c=.o)
OBJSD := $(OBJS:srcs/%=obj/%)
OBJSD := $(OBJSD:ft_printf/%=obj/%)
FT_PRINTF = ft_printf
FT_PRINTFA = ft_printf/libftprintf.a

CC := clang
GCF := -g3 -Wall -Wextra -Werror
NAME = libft.a
LIBFT := ft_printf
CFLAGS := -Wall -Wextra -Werror

# Compiller selection
ifdef gcc
CC := gcc
else ifdef clang
CC := clang
else ifdef cc
CC := $(cc)
endif

# Debug mode
ifeq ($(debug), 1)
CFLAGS := $(GCF)
endif
# CFLAGS += -I . -I ft_printf -I includes/
CFLAGS += -I ft_printf -I includes/

all: $(OBJD) $(NAME)

$(NAME): $(OBJSD)
	ar rc $(NAME) $(OBJSD)

obj/%.o: srcs/%.c $(CHEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[32m\033[1;32m.\033[1;0m\033[32m\033[0m\c"

obj/%.o:: ft_printf/%.c $(CHEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[32m\033[1;32m.\033[1;0m\033[32m\033[0m\c"

# libftprintf.a:

# $(FT_PRINTF):
# 	make -C ft_printf/ lib=1

# $(FT_PRINTFA):
# 	cp $(FT_PRINTFA) .
# 	mv libftprintf.a $(NAME)

$(OBJD):
	$(shell mkdir $(OBJD))
	$(shell mkdir $(OBJD)/env)
	$(shell mkdir $(OBJD)/string)
	$(shell mkdir $(OBJD)/mem)

clean:
	@make -C ft_printf/ libclean
	@/bin/rm -fr $(OBJD)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.SILENT: all $(NAME) $(OBJSD) clean fclean re

.PHONY: clean fclean all
