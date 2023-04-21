#Define the compiler
CC = gcc

# Define the flags to pass to the compiler
CFLAGS = -Wall -Wextra -Werror

# Define the source files for the push_swap executable
SRC = push_swap.c ./utils/check_sorting.c ./utils/filling_stacks.c ./utils/free.c ./utils/handle_args.c  ./utils/sort_more_utils.c ./utils/ft_split.c ./utils/ft_substr.c  ./src/sort_three.c  ./src/sort_four.c ./src/sort_five.c ./src/sort_more.c ./src/operations_a.c ./src/operations_b.c ./src/operations_double.c ./utils/int_length.c ./utils/leaks.c ./utils/utils.c ./utils/ft_strlen_2d.c ./utils/ft_strlen.c ./utils/ft_strjoin.c ./utils/has_dup.c ./utils/is_number.c ./utils/ft_atoi.c ./utils/ft_isdigit.c ./utils/display_error.c

# Define the object files for the push_swap executable, generated from the source files
OBJ = $(SRC:.c=.o)

# Define the name of the push_swap executable to be generated
NAME = push_swap

# Define the default target to be built
all: $(NAME)

# Rule to generate the push_swap executable from the object files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to generate the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.c,%.o,$<)

# Clean target to remove generated files
clean:
	rm -f $(OBJ)

# Fclean target to remove executable files and perform clean
fclean: clean
	rm -f $(NAME)

# Re target to rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean
