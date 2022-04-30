NAME    =   so_long
CC      =   gcc
SRCS    =   check_map.c init.c key_hook.c map.c move.c output.c so_long.c \
			src.c get_next_line.c get_next_line_utils.c minilibx/libmlx.a
FLAGS   =   -Werror -Wextra -Wall -o ${NAME} -framework OpenGl -framework AppKit -D BUFFER_SIZE=30
.PHONY  :   all clean fclean re bonus
all     :
	make -C minilibx
	gcc $(SRCS) $(FLAGS)
clean   :

fclean  :   clean
	make -C minilibx clean
	rm ${NAME}
re      :   fclean all
bonus   :   all
