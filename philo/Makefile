# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakobori <hakobori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 17:20:29 by hakobori          #+#    #+#              #
#    Updated: 2024/09/23 07:53:32 by hakobori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		 = philo
SRCS_DIR	 = ./
INCLUDE_DIR  = ./includes/
CFLAGS 		 = -Wall -Wextra -Werror -I.
# CFLAGS		+= -g -fsanitize=address
# CFLAGS		+= -g -fsanitize=thread
SRCS 		 = main.c \
			   get_time.c \
			   args_digits_plus.c \
			   args_overflow.c \
			   is_philosopher_under_200.c \
			   get_info_with_mutex.c \
			   get_info_with_mutex_long.c \
			   get_info_with_mutex_philosophers.c \
			   set_value_safe.c \
			   take_fork_odd_even.c \
			   check_is_dead_and_print.c \
			   print_error.c \
			   treat_thread.c \
			   thread_eat_sleep_think.c \
			   thread_is_arrive.c \
			   is_dead_mutex.c \
			   ft_bzero.c \
			   ft_calloc.c \
			   ft_atoi.c \
			   ft_isdigit.c \
			   ft_isspace.c \
			   ft_strlen.c 
OBJS 		 = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
