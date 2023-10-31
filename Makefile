#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 21:13:25 by maurodri          #+#    #+#              #
#    Updated: 2023/10/30 18:23:25 by maurodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
FILES = ft_printf.c
#BONUS_FILES = 
DEP_FILES = $(patsubst %.c,%.d,$(FILES))
OBJS = $(patsubst %.c,%.o,$(FILES))
#BONUS_DEP_FILES = $(patsubst %.c,%.d,$(BONUS_FILES))
#BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS_FILES))
DEP_FLAGS =  -MP -MD
CFLAGS = -Wall -Wextra -Werror
CC = cc


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o ./$@ $(DEP_FLAGS)

#$(BONUS_OBJS) : %.o : %.c
#	$(CC) $(CFLAGS) -c $< -o ./$@ $(DEP_FLAGS)

#bonus: $(OBJS) $(BONUS_OBJS)
#	ar rcs $(NAME) $^

.Phony: all clean fclean re 

clean:
	rm -fr $(OBJS) $(DEP_FILES) $(BONUS_OBJS) $(BONUS_DEP_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)
