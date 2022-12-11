SRCS    = main.c ft_split.c get_next_line.c get_next_line_utils.c \
		  error_management.c window_management.c ft_itoa.c gen_window.c\
          error_management_bis.c tools1.c event_action.c tools2.c\
		  fd_opening.c flood_fill.c update.c map_reading.c movement.c   
		  
HEADER  = so_long.h

OBJS    = ${SRCS:.c=.o}

NAME    = so_long

CC      = cc

RM      = rm -f

CFLAGS = -I../minilibx-linux 

CFLAGS1 = -Wall -Wextra -Werror -L../minilibx-linux -lmlx_Linux -lmlx  -lXext -lX11 -lm -g3
#CFLAGS1 = -Wall -Wextra -Werror -L../minilibx-linux -lmlx_Linux -lmlx  -lXext -lX11 -lm -g3 -fsanitize=address

OPT     = valgrind  --leak-check=full

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
				

${NAME}  :${OBJS} ${HEADER}
		make -C ../minilibx-linux
		${CC} ${SRCS} -o ${NAME} ${CFLAGS1}

all:    ${NAME}

clean:  
		make clean -C ../minilibx-linux
		${RM} ${OBJS}


fclean: clean
		${RM} ${NAME}


re:     fclean all

.PHONY:         all clean fclean re
