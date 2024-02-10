# $@: name of the target file (one before colon)
# $<: name of first prerequisite file (first one after colon)
# $^: names of all prerequisite files (space separated)
# $*: stem (bit which matches the % wildcard in rule definition)
#
# VAR = val: Normal setting - values within are recursively expand when var used.
# VAR := val: Setting of var with simple expansion of values inside - values are expanded at decl time.
# VAR ?= val: Set var only if it doesn't have a value.
# VAR += val: Append val to existing value (or set if var didn't exist).

# Program name and output directory
OUTPUT_DIR := 	.
NAME := 		$(OUTPUT_DIR)/so_long

# Other directories
SOURCES_DIR :=	scrs
INCLUDES_DIR :=	incl
OBJECTS_DIR :=	objs

# Files
HEADERS :=		$(wildcard $(INCLUDES_DIR)/*.h)
SOURCES :=		$(wildcard $(SOURCES_DIR)/*.c)
OBJECTS :=		$(patsubst $(SOURCES_DIR)/%.c, $(OBJECTS_DIR)/%.o,$(SOURCES))

#libraries
LIBFT_DIR :=			libs/libft
LIBFT_INCLUDES_DIR :=	$(LIBFT_DIR)/incl
LIBFT :=				$(LIBFT_DIR)/libft.a

OS := $(shell uname)
ifeq ($(OS), Darwin)
	OS :=					__APPLE__
	LIBMLX_DIR := 			libs/minilibx_opengl_20191021
	LIBMLX_INCLUDES_DIR :=	$(LIBMLX_DIR)
	LIBMLX :=				$(LIBMLX_DIR)/libmlx.a
	LIBMLX_LL_FLAGS := 		-lft -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(OS), Linux)
	OS :=					__linux__
	LIBMLX_DIR := 			libs/minilibx-linux
	LIBMLX_INCLUDES_DIR :=	$(LIBMLX_DIR)
	LIBMLX :=				$(LIBMLX_DIR)/libmlx_Linux.a
	LIBMLX_LL_FLAGS :=		-lft -lmlx_Linux -lXext -lX11 -lm -lz
endif
LIBX_LINUX_URL := 			https://github.com/42Paris/minilibx-linux.git

# BONUS_SOURCES = \
# 	$(wildcard $(BONUS_DIR)/*.c)
# BONUS_OBJECTS = 	$(BONUS_SOURCES:.c=.o)
# BONUS_OBJECTS += 	$(OBJECTS)

# Compiler and options
CC := 		cc
W3_FLAGS := -Wall -Wextra -Werror
UI_FLAGS :=	-I $(INCLUDES_DIR) -I $(LIBFT_INCLUDES_DIR) -I $(LIBMLX_INCLUDES_DIR) -D$(OS)
UL_FLAGS := -L $(LIBFT_DIR) -L $(LIBMLX_DIR)
LL_FLAGS := $(LIBMLX_LL_FLAGS)

# Phony targets
.PHONY: all clean fclean re
.PHONY: libft libmlx bonus
.PHONY: aclean ac rec ar

# Link Targets
all: $(NAME)
$(NAME): $(OBJECTS) | libft libmlx
	@echo "--------------------------------"
	@echo "preparing done.\n"
	$(CC) $(UI_FLAGS) $(UL_FLAGS) $^ -o $@ $(LL_FLAGS) -fsanitize=address -fsanitize=undefined
	@echo "--------------------------------"
	@echo "make $(NAME) done.\n"
	chmod 777 $(NAME)
	@echo "--------------------------------"
	@echo "change permission of $(NAME) done.\n"

# Compile Targets
$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.c | $(OBJECTS_DIR)
	$(CC) $(W3_FLAGS) $(UI_FLAGS) -c $< -o $@ -fsanitize=address -fsanitize=undefined
$(OBJECTS_DIR):
	mkdir $(OBJECTS_DIR)

# Clean Targets
clean:
	rm -f $(OBJECTS)
	rm -d $(OBJECTS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) clean
re: fclean all

# libft
libft: $(LIBFT)
$(LIBFT):
	@echo "Compiling libft library..."
	make -C $(LIBFT_DIR) -s
	@echo "--------------------------------"
	@echo "make libft done.\n"

# minilibx
libmlx: $(LIBMLX)
$(LIBMLX): $(LIBMLX_DIR)
	@echo "Compiling Minilibx library..."
	make -C $(LIBMLX_DIR) -s
	@echo "--------------------------------"
	@echo "make libmlx done.\n"
$(LIBMLX_DIR):
	ifeq ($(OS), Linux)
		@echo "Cloning Minilibx repository..."
		git clone $(LIBMLX_URL) $(LIBMLX_DIR)
	else
		@echo "no Minilibx dir!"
	endif

# # bonus
# bonus: all $(BONUS_OBJECTS)
# 	ar rcs $(NAME) $(BONUS_OBJECTS)

# non mandatory
aclean: all clean
ac: all clean
rec: re clean
ar:
	ar rcs $(OUTPUT_DIR)/$(NAME) $(OBJECTS)