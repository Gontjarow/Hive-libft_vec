SOURCES = \
	atom.c \
	mat_identity.c \
	mat_mul.c \
	mat_new_axang.c \
	mat_new_rotx.c \
	mat_new_roty.c \
	mat_new_rotz.c \
	mat_new_scale_center.c \
	mat_new_scale.c \
	mat_new_translation.c \
	mat_persp_fov.c \
	mat_persp_ortho.c \
	mat_persp_wh.c \
	mat_transpose.c \
	mat_rotate.c \
	mtov.c \
	qtom.c \
	qtov.c \
	quat_norm.c \
	vec2_add.c \
	vec2_cross.c \
	vec2_dot.c \
	vec2_lerp.c \
	vec2_mag.c \
	vec2_mul.c \
	vec2_norm.c \
	vec2_rad.c \
	vec2_rot.c \
	vec2_slope.c \
	vec2_sub.c \
	vec3_add.c \
	vec3_cross.c \
	vec3_dist.c \
	vec3_div.c \
	vec3_dot.c \
	vec3_mag.c \
	vec3_mul.c \
	vec3_mulmat.c \
	vec3_norm.c \
	vec3_rot.c \
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
	@echo "$(MSG)$(NAME) compiled!$(END)"

$(OBJ): $(SRCDIR)%.o : $(SRCDIR)%.c
	@gcc $(FLAGS) -c $< -o $@ $(INC)

clean:
	@rm -f $(OBJ)
	@echo "$(MSG)Cleaned $(NAME)!$(END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MSG)Removed $(NAME)!$(END)"

re: fclean all

test:
	@rm -f a.out
	@echo "$(MSG)Compiling test...$(END)"
	gcc $(file) -l vector-math -L . $(INC)
	@echo "$(MSG)Running...$(END)"
	./a.out
