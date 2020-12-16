# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvanessa <tvanessa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 18:55:16 by gmentat           #+#    #+#              #
#    Updated: 2020/12/10 20:25:28 by tvanessa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = 
SS = $(S)ft_printf.c $(S)ft_newarg.c $(S)parsing_str_format.c $(S)check_flags.c $(S)check_flags_mod.c $(S)use_mod.c $(S)ft_newarg_flags.c $(S)revers_str.c $(S)ft_itoa_long.c $(S)ft_itoa_long_un.c $(S)use_flags_d_i.c $(S)use_flags_x_x.c $(S)use_flags_o.c $(S)use_flags_u.c $(S)use_flags_c.c $(S)use_flags_s.c $(S)use_flags_p.c $(S)use_flags_proc.c $(S)struct_flugs.c $(S)ft_fundel.c $(S)parse_flags_point.c $(S)parse_flags_length.c $(S)parse_flags_width.c $(S)parse_flags_basic.c $(S)finish_mod.c $(S)free_struct_args.c $(S)free_struct_flugs.c $(S)struct_flugs_length_d_i.c $(S)struct_flugs_length_o.c $(S)struct_flugs_length_u.c $(S)struct_flugs_length_x_x.c $(S)use_mod_point.c $(S)use_mod_width.c $(S)exeption_null.c $(S)use_flags_f.c $(S)parsing_str_format_fd.c $(S)ft_dprintf.c $(S)finish_mod_fd.c $(S)float.c $(S)arr_helper.c $(S)ft_math.c $(S)vector_helpers.c $(S)vector_round.c $(S)vector_core.c $(S)vector_to_str.c $(S)vector_math.c
ifeq ($(lib), 1)
H :=  -I ../ -I ../includes
else
H := -I libft/includes -I libft/ -I . 
endif
NAME = libftprintf.a
CC = clang
CF = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CF) $(H) -c -o $@ $<

$(NAME): $(SS:.c=.o)
ifeq ($(lib), 0)
	make -C libft/
	cp libft/libft.a .
	mv libft.a $(NAME)
endif
	ar r $(NAME) $(SS:.c=.o)
	ranlib $(NAME)

clean:
	make -C libft/ clean 
	/bin/rm -f $(SS:.c=.o)

fclean: clean
	make -C libft/ fclean 
	/bin/rm -f $(NAME)

re: fclean all

# lib: 
# 	LIB=1
# 	$(NAME)
# $(SS:.c=.o)
# 	ar r $(NAME) $(SS:.c=.o)
# 	ranlib $(NAME)

libclean: 
	/bin/rm -f $(SS:.c=.o)

libfclean:  libclean
	/bin/rm -f $(NAME)

.SILENT: all $(NAME) $(OBJSD) libclean libfclean clean fclean re
