NAME		=	libasm.a

SRC_DIR		=	./src
SRC			=	$(SRC_DIR)/ft_strlen.s	\
				$(SRC_DIR)/ft_strcpy.s	\
				$(SRC_DIR)/ft_strcmp.s	\
				$(SRC_DIR)/ft_write.s	\
				$(SRC_DIR)/ft_read.s	\
				$(SRC_DIR)/ft_strdup.s

SRC_BONUS	=	$(SRC_DIR)/ft_atoi_base_bonus.s \
				$(SRC_DIR)/ft_list_push_front_bonus.s \
				$(SRC_DIR)/ft_list_size_bonus.s \
				$(SRC_DIR)/ft_list_sort_bonus.s \
				$(SRC_DIR)/ft_list_remove_if_bonus.s

OBJ_DIR		=	./obj
OBJ			=	$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC))

OBJ_BONUS	=	$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC_BONUS))

INCLUDE		=	./include

ASM			=	nasm
ASM_FLAG	=	-f elf64

AR_FLAG		=	rcs

RM = /bin/rm -f

CC		=	clang
CC_FLAG	=	-Wall -Werror -Wextra \
			-I $(INCLUDE) \
			-L. -lasm \

TEST		=	main.c
BONUS		=	main_bonus.c

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(AR_FLAG) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	mkdir -p $(OBJ_DIR)
	$(ASM) $(ASM_FLAG) $< -o $@

test:  $(TEST)
	$(CC) $< $(CC_FLAG) -o $@

bonus:  all $(OBJ_BONUS)
	$(AR) $(AR_FLAG) $(NAME) $(OBJ_BONUS)

bonus_test:  $(BONUS) $(NAME) bonus
	$(CC) $< $(CC_FLAG) -o $@

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) test bonus_test

re: fclean all

.PONY: all, test, bonus, clean, fclean, re
