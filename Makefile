#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 21:13:25 by maurodri          #+#    #+#              #
#    Updated: 2024/01/12 19:53:45 by maurodri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := libftprintf.a

FILES := ft_printf.c \
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

HEADERS := ft_printf.h \
		ft_printf_internals.h \
		parser/parser.h \
		parser/parser_utils.h \
		presenter/presenter.h \
		presenter/presenter_utils.h

BONUS_FILES :=  ft_printf_bonus.c \
		flag_utils_bonus.c \
		parser_bonus.c \
		parser_utils_bonus.c \
		parser_format_args_bonus.c \
		presenter_bonus.c \
		presenter_utils_bonus.c \
		presenter_utils2_bonus.c \
		presenter_utils3_bonus.c \
		present_string_bonus.c \
		present_base10_bonus.c \
		present_ubase10_bonus.c \
		present_char_bonus.c \
		present_escape_bonus.c \
		present_hexa_bonus.c \
		present_pointer_bonus.c

BONUS_HEADERS := ft_printf_bonus.h \
				 ft_printf_internals_bonus.h \
				 parser_bonus/parser_bonus.h \
				 parser_bonus/parser_utils_bonus.h \
				 presenter_bonus/presenter_bonus.h \
				 presenter_bonus/presenter_utils_bonus.h

VPATH = ./parser/ ./presenter/ ./parser_bonus/ ./presenter_bonus/

MANDATORY_OBJS := $(patsubst %.c,%.o,$(FILES))
BONUS_OBJS := $(patsubst %.c,%.o,$(BONUS_FILES))

DEP_FLAGS := -MP -MD -MF
CFLAGS := -Wall -Wextra -Werror
CC := cc

ifdef WITH_BONUS
	INCLUDES := -I./ -I./presenter_bonus -I./parser_bonus
	CLEAR := $(MANDATORY_OBJS)
	OBJS := $(BONUS_OBJS)
else
	INCLUDES := -I./ -I./presenter -I./parser
	CLEAR := $(BONUS_OBJS)
	OBJS := $(MANDATORY_OBJS)
endif

DEP_DIR := ./dep/
DEP_FILES := $(addprefix $(DEP_DIR), $(addsuffix .d,$(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	@rm -f $(NAME) $(CLEAR)
	@ar rcs $(NAME) $^

$(OBJS): %.o : %.c | $(DEP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) $(DEP_FLAGS) "$(DEP_DIR)$@.d"

$(DEP_DIR):
	@mkdir -p $@  

bonus:
	@$(MAKE) --no-print-directory WITH_BONUS=1

.PHONY: all clean fclean re bonus

clean:
	rm -fr $(OBJS) \
			$(BONUS_OBJS) \
			$(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP_FILES)
