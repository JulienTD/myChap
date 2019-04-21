##
## EPITECH PROJECT, 2019
## NWP_mychap_2018
## File description:
## Makefile
##

NAME				=	client

SRC					=	main.c

DIR					=	./src/

SRC_CHAP			=	chap/chap_fill.c \
						chap/chap_init.c \
						chap/chap_listen.c

SRC_PACKET			=	packet/packet_calculate_checksum.c \
						packet/packet_configure_dest.c \
						packet/packet_configure_ip.c \
						packet/packet_configure_src.c \
						packet/packet_configure_udp.c \
						packet/packet_init.c \
						packet/packet_send.c

SRCS				=	$(addprefix $(DIR), $(SRC_CHAP)) \
						$(addprefix $(DIR), $(SRC_PACKET))

SRC_MAIN			=	$(addprefix $(DIR), $(SRC))

OBJ_MAIN			=	$(SRC_MAIN:.c=.o)

OBJ					=	$(SRCS:.c=.o)

CFLAGS				=	-W -Wall -Wextra -I./include/ -I./lib/include/

CC					=	gcc

all: $(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
			# make -C ./lib/ re
			$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ) -o $(NAME)
			# -L./lib/ -lmy

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

debug:	re $(OBJ) $(OBJ_MAIN)
			# make -C ./lib/ re
			$(CC) -fsanitize=address $(CFLAGS) $(OBJ) $(OBJ_MAIN) -lasan -o $(NAME)

re:			fclean all

tests_run:	$(SRC_MAIN) $(SRCS)
			# make -C ./lib/ re
			$(CC) $(CFLAGS) $(SRCS) $(SRCS_CRITERION) -lcriterion --coverage -o test
			./test

clean:
			# make -C ./lib/ clean
			rm -f $(OBJ) $(OBJ_MAIN) *~ \#*\# *.gcno *.gcda

fclean:		clean
			# make -C ./lib/ fclean
			rm -f $(NAME)
			rm -f test

.PHONY:		all valgrind wc debug re tests_run clean fclean $(NAME)