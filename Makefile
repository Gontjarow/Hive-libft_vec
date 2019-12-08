SOURCES = \
	atom.c \
	matrix_identity.c \
	matrix_multiply.c \
	matrix_scale.c \
	matrix_translation.c \
	matrix_transpose.c \
	mtov.c \
	qtom.c \
	qtov.c \
	quat_norm.c \
	vec3_add.c \
	vec3_cross.c \
	vec3_dist.c \
	vec3_div.c \
	vec3_dot.c \
	vec3_mag.c \
	vec3_mult.c \
	vec3_norm.c \
	vec3_rotate.c \
	vec3_sub.c \
	vec4_between.c \
	vtom.c \
	vtoq.c

NAME = libvector-math.a
FLAGS = -Wall -Wextra #-Werror

SRCDIR = sources/
INCDIR = includes/
SRC = $(addprefix $(SRCDIR),$(SOURCES))
OBJ = $(SRC:.c=.o)
INC = -I $(INCDIR) -lm

MSG = \033[0;91m
END = \033[0m

.PHONY: all, clean, fclean, re, test, file

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(MSG)Compiled library!$(END)"

$(OBJ): $(SRCDIR)%.o : $(SRCDIR)%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

clean:
	@rm -f $(OBJ)
	@echo "$(MSG)Removed objects!$(END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MSG)Removed library!$(END)"

re: fclean all

test:
	@rm -f a.out
	@echo "$(MSG)Compiling test...$(END)"
	gcc $(file) -l vector-math -L . $(INC)
	@echo "$(MSG)Running...$(END)"
	./a.out
