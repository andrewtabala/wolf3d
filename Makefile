NAME = wolf3d
NAMEL = libft.a
CFLAG = -c
FLAGS = -Wall -Wextra -Werror

BOLD = \033[1m
UNDERLINE = \033[4m
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): 
	cd libft; \
		gcc $(CFLAG) $(FLAGS) *.c; \
		ar rc $(NAMEL) *.o
	@echo "$(BOLD)$(NAMEL)	$(GREEN)$(UNDERLINE)was created$(RESET)" 
	gcc  -I /usr/local/include src/game/wolf3d.c\
		get_next_line/get_next_line.c \
		libft/libft.a \
		src/game/read.c \
		src/game/textures.c \
		src/controls/keyactions.c \
		src/controls/mousemove.c \
		src/game/draw.c \
		src/game/drawline_textured.c \
		src/game/drawline_untextured.c \
		src/game/draw_set_textures.c \
		src/game/indentation.c \
		src/game/img.c \
		src/validation/validation.c \
		minilibx_macos/libmlx.a \
		-L /usr/local/lib \
		-lmlx -framework OpenGL \
		-framework Appkit \
		-o $(NAME)
	@echo "$(BOLD)$(NAME)	$(GREEN)$(UNDERLINE)was created$(RESET)"
clean:
	rm -rf *.o
	@echo "$(BOLD).o's	$(RED)$(UNDERLINE)were deleted$(RESET)"
fclean: clean
	rm -rf $(NAME)
	@echo "$(BOLD)$(NAME)	$(RED)$(UNDERLINE)was deleted$(RESET)"

re: fclean all
