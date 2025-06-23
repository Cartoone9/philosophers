# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ******* <*******@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 22:11:33 by *******           #+#    #+#              #
#    Updated: 2025/05/20 00:23:56 by *******          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -pthread

S_DIR = srcs
O_DIR = .objs

SRCS = srcs/main.c srcs/threads.c srcs/monitor.c srcs/monitor_meal.c \
	   \
	   srcs/threads_actions.c srcs/threads_actions_eat.c \
	   \
	   srcs/time.c srcs/sleep.c srcs/sleep_wait.c \
	   \
	   srcs/utils_one.c srcs/utils_two.c srcs/atoll.c srcs/printer.c \
	   \
	   srcs/check_n_fill_table.c srcs/fill_table_utils.c srcs/make_spoon_n_philo.c \
	   \
	   srcs/error.c srcs/error_mtx.c srcs/error_thread.c \
	   \
	   srcs/free.c srcs/exit.c srcs/exit_utils.c \
	   \
	   srcs/tester.c \
	   \
	   \
	   libft/ft_strlen.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_itoa.c \

OBJS = $(SRCS:%.c=$(O_DIR)/%.o)

RESET = \033[0m
GREEN = \033[0;32m
RED	= \033[0;31m

COUNTER_FILE = .counter_makefile

all: reset_counter $(NAME)
	@if [ ! -f .built_makefile ]; then \
		echo "$(NAME): everything is already up to date."; \
	fi
	@rm -f .built_makefile
	@rm -f .counter_makefile

$(O_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I./hdrs/ -c $< -o $@
	@count=`cat $(COUNTER_FILE)`; \
	count=`expr $$count + 1`; \
	echo $$count > $(COUNTER_FILE); \
	echo -n "\rphilo: compiling... $$count/$(words $(SRCS))"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I./hdrs/ $(OBJS) $(LIBS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME)$(RESET) has been compiled."
	@rm $(COUNTER_FILE)
	@touch .built_makefile

clean:
	@rm -rf $(O_DIR) $(COUNTER_FILE) .built_makefile
	@echo "$(NAME): ${RED}${O_DIR}${RESET} has been deleted."

fclean:
	@rm -rf $(O_DIR) $(NAME) $(COUNTER_FILE) .built_makefile
	@echo "$(NAME): ${RED}${O_DIR}${RESET} and ${RED}${NAME}${RESET} have been deleted."

re: fclean all

reset_counter:
	@echo 0 > $(COUNTER_FILE)

.PHONY: all clean fclean re reset_counter
