##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC	=	./mini_shell.c \
		./mini_shella.c \
		./mini_printf.c \
		./my_strdup.c	\
		./mini_shellb.c \
		./mini_shellc.c \
		./mini_shelld.c

OBJ	= $(SRC:.c=.o)

all: $(OBJ)
	gcc -o mysh $(SRC)

clean:
	rm -f *.o
	rm -f *~
	rm -f #*#

fclean: clean
	rm -f mysh

re: fclean all

tests_run:
	rm -f *.o
	rm -f *~
	rm -f #*#  
