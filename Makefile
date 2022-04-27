CC = arch -x86_64 cc -I minilibx/ libft/libft.a main.c utils/utils.c utils/rotate.c utils/draw_map.c utils/draw_line.c utils/read_map.c -L minilibx/ -lmlx -framework OpenGl -framework AppKit -o fdf -g
#utils/draw_cols.c utils/draw_rows.c 
all:
	$(CC)
clean:
	rm fdf
re:
	$(CC)

.PHONY: all clean
#utils/draw_map.c
#main.c