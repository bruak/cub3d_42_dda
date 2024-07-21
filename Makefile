NAME		=	cub3d
CC			=	gcc
CFLAGS		=	-g -Wall -Werror -Wextra
LFLAGS		=	-Lget_next_line -Llibft -Lminilibx -lft -lmlx -framework OpenGL -framework AppKit
SOURCES		=	main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				control/controllers.c parser/map.c render/dda.c render/render.c render/draw.c render/image.c parser/load_map_content.c \
				parser/load_map.c parser/load_map_dimentions.c parser/load_metadata_rgb_duplicate_check.c \
				parser/load_metadata.c parser/check_surrounded_by_wall.c memory-allocator/aborter.c memory-allocator/allocator.c \
				exit/graceful_exit.c
OBJ			=	$(SOURCES:%.c=%.o)

all	: $(NAME)

$(NAME)	: $(OBJ)
	make -C libft
	make -C minilibx
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)
	make -C libft clean
	make -C minilibx clean

fclean : clean
	rm	-f $(NAME) minilibx/libmlx.a libft/libft.a

re		:	fclean all
