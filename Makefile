CC = arch -x86_64 cc -I minilibx/ libft/libft.a main.c src/utils.c src/rotate.c src/draw_map.c \
	src/draw_line.c src/read_map.c src/matrix_values.c src/key_hook.c src/put_string.c \
	-L minilibx/ -lmlx -framework OpenGl -framework AppKit -o fdf
#src/draw_cols.c src/draw_rows.c 
all:
	$(CC)
clean:
	rm fdf
re:
	$(CC)

.PHONY: all clean
#src/draw_map.c
#main.c