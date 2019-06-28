NAME = ft_ls

LIBFT_PATH = ./libft/

FLAGS = -Wall -Werror -Wextra
INC =  -I ./includes/ft_ls.h -I $(LIBFT_PATH)libft.h

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) -o $(NAME)  ft_ls.c $(LIBFT_PATH)libft.a

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf *.o

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)

re: fclean all
