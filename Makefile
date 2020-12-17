NAME = minishell

COMP = gcc
COMP_FLAG = -g -Wall -Werror -Wextra

LIB = ./libft/libft.a
LIB_DIR = ./libft
LIB_RULE = $(addsuffix .lib, $(LIB_DIR))

INC = -I ./libft/ -I ./inc/
SRC_DIR = ./src/
SRC =	main.c \
		ft_envir.c \
		ft_pwd.c \
		ft_prompt.c \
		ft_exe.c \
		ft_cmd_split.c \
		ft_path_parse.c \
		ft_builtin.c \
		ft_setenv.c \
		ft_unsetenv.c \
		ft_cd.c \
		ft_echo.c \
		ft_putnstr.c \
		ft_free.c \
		ft_cd_aux.c \
		ft_exe_aux.c \
		ft_input_parse.c \
		ft_pipe.c \
		ft_pipe_check.c \
		ft_cmd.c

BUILD_DIR = ./build/
BUILD_OBJ = $(addprefix $(BUILD_DIR), $(SRC:.c=.o))

all: $(BUILD_DIR) $(LIB_RULE) $(NAME)

$(BUILD_DIR):
	@ mkdir -p $(BUILD_DIR)

%.lib:
	@ make -sC $(LIB_DIR)

$(NAME): $(LIB) $(BUILD_OBJ)
	@ $(COMP) $(COMP_FLAG) -o $(NAME) $(BUILD_OBJ) $(LIB)
	@ echo "\033[37;1;42m minishell done \033[0m"

$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@ $(COMP) $(COMP_FLAG) $(INC) -o $@ -c $<
	@ echo "\033[33m $< \033[0m"

$(LIB) :
	@ make -sC ./libft/

clean:
	@ rm -rf $(BUILD_DIR)
	@ make clean -C ./libft/

fclean: clean
	@ rm -rf $(NAME)
	@ make fclean -C ./libft/

re: fclean all

.PHONY: all clean fclean re
