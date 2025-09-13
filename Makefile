NAME=	fdf

FLAGS=	-Wall -Wextra -Werror

LIB=	mlx_linux/libmlx.a

FILES=	fdf.c \
		hooks.c \
		make_line.c \
		make_map_array.c \
		points.c \
		traversal.c \
		array_helpers.c \
		ft_split.c \
		get_next_line_utils.c \
		get_next_line.c \
		len_functions.c \
		parsing.c \
		print_functions.c \
		termination.c

OBJS=	fdf.o \
		hooks.o \
		make_line.o \
		make_map_array.o \
		points.o \
		traversal.o \
		array_helpers.o \
		ft_split.o \
		get_next_line_utils.o \
		get_next_line.o \
		len_functions.o \
		parsing.o \
		print_functions.o \
		termination.o

all: minilibx $(NAME)

$(NAME): $(OBJS) $(LIB)
	cc $(FLAGS) $(OBJS) $(LIB) -lXext -lX11 -lm -lz -o $(NAME)

minilibx:
	make -C mlx_linux

$(OBJS): $(FILES)
	cc -c $(FLAGS) $(FILES) -I/usr/include -Imlx_linux

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
