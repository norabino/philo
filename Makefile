SRCS = src/main.c src/ft_init.c src/ft_atol.c src/ft_routine.c src/ft_monitor.c src/ft_parse.c src/ft_checks.c src/ft_utils.c src/ft_time.c 
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev:
	make fclean; git add .; git commit -m "dev"; git push --force

.PHONY: all clean fclean re dev