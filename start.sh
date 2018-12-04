#norminette -R CheckForbiddenSourceHeader get_next_line.c get_next_line.h libft
make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

#./test_gnl basic_tests/1
#./test_gnl basic_tests/2
#./test_gnl basic_tests/3

#./test_gnl middle_tests/1
#./test_gnl middle_tests/2
#./test_gnl middle_tests/3

#./test_gnl advanced_tests/1
#./test_gnl advanced_tests/2
#./test_gnl advanced_tests/3
#./test_gnl advanced_tests/4
#./test_gnl advanced_tests/5
#./test_gnl advanced_tests/6
#./test_gnl advanced_tests/7


