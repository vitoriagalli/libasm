NAME		=	libasm.a

SRC_DIR		=	./src
SRC			=	$(SRC_DIR)/ft_strlen.s \
				$(SRC_DIR)/ft_strcpy.s \
				$(SRC_DIR)/ft_strcmp.s \
				$(SRC_DIR)/ft_write.s \
				$(SRC_DIR)/ft_read.s \
				$(SRC_DIR)/ft_strdup.s \

SRC_BONUS	=	$(SRC_DIR)/ft_atoi_base_bonus.s \
				$(SRC_DIR)/ft_list_push_front_bonus.s \
				$(SRC_DIR)/ft_list_size_bonus.s \
				$(SRC_DIR)/ft_list_sort_bonus.s \
				$(SRC_DIR)/ft_list_remove_if_bonus.s

OBJ_DIR		=	./obj
OBJ			=	$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS	=	$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRC_BONUS))

TESTS_DIR	=	./main_tests
SRC_TESTS	=	$(TESTS_DIR)/test_ft_strlen.c \
				$(TESTS_DIR)/test_ft_strcpy.c \
				$(TESTS_DIR)/test_ft_strcmp.c \
				$(TESTS_DIR)/test_ft_write.c \
				$(TESTS_DIR)/test_ft_read.c \
				$(TESTS_DIR)/test_ft_strdup.c

BONUS_TESTS	=	$(TESTS_DIR)/test_linked_list_bonus.c \
				$(TESTS_DIR)/test_ft_atoi_base_bonus.c

INCLUDE		=	./include

ASM			=	nasm

ASM_FLAG	=	-f elf64

CC			=	clang

CC_FLAGS	=	-Wall -Werror -Wextra -g \
				-L. -lasm

HEADER		=	-I $(INCLUDE) \
				-I.

RM 			=	/bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	mkdir -p $(OBJ_DIR)
	$(ASM) $(ASM_FLAG) $< -o $@

test: $(NAME) $(SRC_TESTS) main.c
	$(CC) main.c $(SRC_TESTS) $(HEADER) $(CC_FLAGS) -o $@

bonus: $(NAME) $(OBJ_BONUS)
	ar rcs $< $(OBJ_BONUS)

testbonus: bonus main_bonus.c
	$(CC) main_bonus.c $(BONUS_TESTS) $(HEADER) $(CC_FLAGS) -o $@

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) test testbonus

re: fclean all

.PONY: all, test, bonus, testbonus, clean, fclean, re
