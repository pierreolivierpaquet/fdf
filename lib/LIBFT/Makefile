# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 10:45:50 by ppaquet           #+#    #+#              #
#    Updated: 2023/06/15 11:58:40 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==================================================================================================|
#---< LIBFT >--------------------------------------------------------------------------------------|
#                                  VARIABLES                                                       |
#==================================================================================================|

# ------------------------------------------------------------------------------------< LIBRARY >---
NAME := libft.a

# ----------------------------------------------------------------------------------< COMPILING >---
CC := gcc
CFLAGS := -g -Wall -Werror -Wextra
AR := ar crs

# --------------------------------------------------------------------------------------< OTHER >---
RM := rm -rf

# -------------------------------------------------------------------------------------< COLORS >---
WTH := \033[0m
GRN := \033[0;32m
RED := \033[0;31m
YEL := \033[0;33m
BLU := \033[0;34m
BLD := \033[1m

# -----------------------------------------------------------------------------------< INCLUDES >---
INCLUDES_PATH := include/
INCL := -I ./$(INCLUDES_PATH)

# -------------------------------------------------------------------------------------< HEADER >---
HEADER_FILE := libft.h
HEADER := $(addprefix $(INCLUDES_PATH), $(HEADER_FILE))

# ------------------------------------------------------------------------------------< SOURCES >---
SRCS_PATH := srcs/
SRCS_FILES := \
\
libft_alpha_digit/ft_atoi.c \
libft_alpha_digit/ft_isalnum.c \
libft_alpha_digit/ft_isalpha.c \
libft_alpha_digit/ft_isascii.c \
libft_alpha_digit/ft_isdigit.c \
libft_alpha_digit/ft_isprint.c \
libft_alpha_digit/ft_itoa.c \
libft_alpha_digit/ft_tolower.c \
libft_alpha_digit/ft_toupper.c \
\
	libft_string/ft_split.c \
	libft_string/ft_strchr.c \
	libft_string/ft_strdup.c \
	libft_string/ft_striteri.c \
	libft_string/ft_strjoin.c \
	libft_string/ft_strlcat.c \
	libft_string/ft_strlcpy.c \
	libft_string/ft_strlen.c \
	libft_string/ft_strmapi.c \
	libft_string/ft_strncmp.c \
	libft_string/ft_strnstr.c \
	libft_string/ft_strrchr.c \
	libft_string/ft_strtrim.c \
	libft_string/ft_substr.c \
\
	libft_utils/ft_putchar_fd.c \
	libft_utils/ft_putendl_fd.c \
	libft_utils/ft_putnbr_fd.c \
	libft_utils/ft_putstr_fd.c \
\
	libft_memory/ft_bzero.c \
	libft_memory/ft_calloc.c \
	libft_memory/ft_memchr.c \
	libft_memory/ft_memcmp.c \
	libft_memory/ft_memcpy.c \
	libft_memory/ft_memmove.c \
	libft_memory/ft_memset.c \
\
	libft_struct_list/ft_lstnew.c \
	libft_struct_list/ft_lstadd_front.c \
	libft_struct_list/ft_lstsize.c \
	libft_struct_list/ft_lstlast.c \
	libft_struct_list/ft_lstadd_back.c \
	libft_struct_list/ft_lstdelone.c \
	libft_struct_list/ft_lstclear.c \
	libft_struct_list/ft_lstiter.c \
	libft_struct_list/ft_lstmap.c \
\
ft_printf/ft_pf_char.c\
ft_printf/ft_pf_hex.c\
ft_printf/ft_pf_nbr.c\
ft_printf/ft_printf.c\
\
get_next_line/get_next_line_bonus.c\
get_next_line/get_next_line_utils_bonus.c\
get_next_line/get_next_line_utils.c\
get_next_line/get_next_line.c\

SRCS := $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# ------------------------------------------------------------------------------------< OBJECTS >---
OBJS_PATH := objs/
OBJS_DIRS := $(addprefix $(OBJS_PATH), ft_printf/ get_next_line/\
	libft_alpha_digit/ libft_memory/ libft_string/ libft_struct_list/\
	libft_utils/)
OBJS := $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

#==================================================================================================|
#---< LIBFT >--------------------------------------------------------------------------------------|
#                                    RULES                                                         |
#==================================================================================================|

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH) 2> /dev/null || true
	@mkdir -p $(OBJS_DIRS) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ $(INCL) -c $< 

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\t\t$(WTH)libft.a ____________________________ $(GRN)$(BLD)[CREATED]"
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS_PATH)

fclean: clean
	@$(RM) $(NAME)
	@echo "\t\t$(WTH)libft.a ____________________________ $(RED)$(BLD)[DELETED]"

re: fclean all

.PHONY: all clean fclean re

