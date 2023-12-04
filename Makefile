#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 21:13:25 by maurodri          #+#    #+#              #
#    Updated: 2023/11/27 15:57:09 by maurodri         ###   ########.fr        #
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
		present_hexa_lower.c \
		present_hexa_upper.c \
		present_pointer.c

HEADERS = ft_printf.h \
		ft_printf_internals.h \
		parser/parser.h \
		parser/parser_utils.h \
		presenter/presenter.h \
		presenter/presenter_utils.h

BONUS_FILES =  ft_printf_bonus.c \
		parser_bonus.c \
		parser_utils_bonus.c \
		parser_format_args_bonus.c \
		presenter_bonus.c \
		presenter_utils_bonus.c \
		presenter_utils2_bonus.c \
		present_string_bonus.c \
		present_base10_bonus.c \
		present_ubase10_bonus.c \
		present_char_bonus.c \
		present_escape_bonus.c \
		present_hexa_lower_bonus.c \
		present_hexa_upper_bonus.c \
		present_pointer_bonus.c

VPATH = ./parser/ ./presenter/ ./parser_bonus/ ./presenter_bonus/
DEP_FILES = $(patsubst %.c,%.d,$(FILES))
OBJS = $(patsubst %.c,%.o,$(FILES))
BONUS_DEP_FILES = $(patsubst %.c,%.d,$(BONUS_FILES))
BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS_FILES))
DEP_FLAGS =  -MP -MD
CFLAGS = -g -Wall -Wextra -Werror
CC = cc

ifdef WITH_BONUS
	OBJS = $(BONUS_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(NAME)
	ar rcs $(NAME) $^
	etags $(wildcard *.c) $(wildcard */*.c) $(HEADERS) 

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(DEP_FLAGS)

bonus:
	$(MAKE) WITH_BONUS=1

.Phony: all clean fclean re 

test: $(NAME)
	$(CC) $(CFLAGS) -g main.c $<
	./a.out

clean:
	rm -fr $(OBJS) $(DEP_FILES) \
			$(BONUS_OBJS) $(BONUS_DEP_FILES) \
			*~

fclean: clean
	rm -f $(NAME) TAGS ./a.out

re: fclean all

-include $(DEP_FILES)
