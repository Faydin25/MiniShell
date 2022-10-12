SRC = main.c ft_echo.c ft_cd.c ft_env.c ft_export.c ft_copy_env.c ft_unset.c ft_for_env.c ft_process.c ft_dollar.c
LIB	= ./lib/.minishell
NAME = minishell

all: $(NAME)

$(NAME) : $(LIB) $(SRC)
	@make -sC ./libft
	@gcc $(SRC) -Wall -Wextra -Werror -fsanitize=address -g ./libft/libft.a -lreadline -o $(NAME) -g -L${HOME}/readline/lib -I${HOME}/readline/include/
	@echo "Compiled!"

$(LIB):
	@make -C ./lib


clean:
	@make fclean -sC ./libft
	@rm -rf minishell

fclean : clean
	@echo "Cleaned!"

run: $(NAME)
	./$(NAME)
