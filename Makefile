#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 21:13:25 by maurodri          #+#    #+#              #
#    Updated: 2023/11/09 00:48:38 by maurodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
FILES = ft_printf.c \
		parser.c \
		parser_utils.c \
		parser_format_args.c \
		presenter.c \
		presenter_utils.c \
		presenter_utils2.c \
		present_string.c \
		present_base10.c \
		present_ubase10.c \
		present_char.c \
		present_escape.c \

#BONUS_FILES =
VPATH = ./parser/ ./presenter/
DEP_FILES = $(patsubst %.c,%.d,$(FILES))
OBJS = $(patsubst %.c,%.o,$(FILES))
PARSER_DEP_FILES = $(patsubst %.c,%.d,$(PARSER_FILES))
PARSER_OBJS = $(patsubst %.c,%.o,$(PARSER_FILES))
#BONUS_DEP_FILES = $(patsubst %.c,%.d,$(BONUS_FILES))
#BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS_FILES))
DEP_FLAGS =  -MP -MD
CFLAGS = -Wall -Wextra -Werror
CC = cc


all: $(NAME)

$(NAME): $(OBJS) $(PARSER_OBJS)
	ar rcs $(NAME) $^

$(OBJS) $(PARSER_OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o ./$@ $(DEP_FLAGS)

#$(BONUS_OBJS) : %.o : %.c
#	$(CC) $(CFLAGS) -c $< -o ./$@ $(DEP_FLAGS)

#bonus: $(OBJS) $(BONUS_OBJS)
#	ar rcs $(NAME) $^

.Phony: all clean fclean re 

clean:
	rm -fr $(OBJS) $(DEP_FILES) \
			$(BONUS_OBJS) $(BONUS_DEP_FILES) \
			$(PARSER_OBJS) $(PARSER_DEP_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)
