#
## Made by	db0
## Contact	db0company@gmail.com
## Website	http://db0.fr/
#

NAME		=	db0chrono
OBJS		=	$(SRCS:.c=.o)

# directories
INCLUDE_DIR	=	include/
SRC_DIR		=	src/

MAIN_DIR	=	$(SRC_DIR)db0chrono/
INIT_DIR	=	$(SRC_DIR)init/
UPDATE_DIR	=	$(SRC_DIR)update/
TOOLS_DIR	=	$(SRC_DIR)tools/
ERR_DIR		=	$(SRC_DIR)errors/

# sources
SRCS		=	$(MAIN_DIR)main.c				\
			$(MAIN_DIR)db0chrono.c				\
			\
			$(INIT_DIR)init_db0chrono.c			\
			\
			$(UPDATE_DIR)update_logfile.c			\
			$(UPDATE_DIR)update_signal.c			\
			\
			$(TOOLS_DIR)strdupcat.c				\
			\
			$(ERR_DIR)print_error.c				\
			$(ERR_DIR)print_perror.c

# commands
CC		=	gcc
RM		=	rm -f

# cc parameters
INCLUDE		=	-I$(INCLUDE_DIR)
CFLAGS		=	-W -Wall -ansi -pedantic -O0

# # # # # # # # #

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

all		:	$(NAME)

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDE)

# clean
clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

# re
re		:	fclean all
