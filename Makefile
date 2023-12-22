# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 11:51:45 by ppaquet           #+#    #+#              #
#    Updated: 2023/07/05 15:00:30 by ppaquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==================================================================================================|
#                                              BANNERS                                             |
#==================================================================================================|

define TITLE

	\033[0;34m███████\033[0;32m╗ \033[0;34m██████\033[0;32m╗  \033[0;34m███████\033[0;32m╗
	\033[0;34m██\033[0;32m╔════╝ \033[0;34m██\033[0;32m╔══\033[0;34m██\033[0;32m╗ \033[0;34m██\033[0;32m╔════╝
	\033[0;34m█████\033[0;32m╗   \033[0;34m██\033[0;32m║  \033[0;34m██\033[0;32m║ \033[0;34m█████\033[0;32m╗
	\033[0;34m██\033[0;32m╔══╝   \033[0;34m██\033[0;32m║  \033[0;34m██\033[0;32m║ \033[0;34m██\033[0;32m╔══╝
	\033[0;34m██\033[0;32m║      \033[0;34m██████\033[0;32m╔╝ \033[0;34m██\033[0;32m║
	\033[0;32m╚═╝      ╚═════╝  ╚═╝

endef
export TITLE

#==================================================================================================|
#                                             VARIABLES                                            |
#==================================================================================================|

# ---------------------------------------------------------------------------------< EXECUTABLE >---
NAME := fdf

# ----------------------------------------------------------------------------------< COMPILING >---
CC := gcc
CFLAGS := -g -Wextra -Wall -Werror -Wunreachable-code

# --------------------------------------------------------------------------------------< OTHER >---
RM := rm -rf
MK = make
CMK := cmake
DIR := mkdir -p

# --------------------------------------------------------------------------------< DIRECTORIES >---
LIBMLX := ./lib/MLX42
LIBFT := ./lib/LIBFT
INCL_PATH := include/

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -L/Users/$(USER)/.brew/lib -lglfw -pthread -lm $(LIBFT)/libft.a

# -------------------------------------------------------------------------------------< COLORS >---
WTH := \033[0m#         WHITE
GRN := \033[0;32m#      RESET + GREEN
RED := \033[0;31m#      RESET + RED
YEL := \033[0;33m#      RESET + YELLOW
BLU := \033[0;34m#      RESET + PURPLE/BLUE
BLD := \033[1m#         BOLD
MGT := \033[1;35m#      BOLD + MAGENTA
CYA := \033[1;36m#      BOLD + CYAN

# -----------------------------------------------------------------------------------< INCLUDES >---
MAC_LINK := -lglfw(3) -framework Cocoa -framework OpenGL -framework IOKit


# ------------------------------------------------------------------------------------< SOURCES >---
SRCS_PATH := srcs/
SRCS_FILES := \
	main.c \
	fdf_parsing.c \
	fdf_errors.c \
	fdf_free_utils.c \
	fdf_checks.c \
	fdf_bresenham.c \
	fdf_bresenham_utils.c \
	fdf_graphic.c \
	fdf_parsing_utils.c \
	fdf_keyboard_hook.c \
	fdf_keyboard_hook_utils.c \
	fdf.c \

SRCS := $(addprefix $(SRCS_PATH), $(SRCS_FILES))

# -------------------------------------------------------------------------------------< HEADER >---
INCL := -I ./$(INCL_PATH) 

HEADER := -I $(LIBFT)/$(INCL_PATH) -I $(LIBMLX)/$(INCL_PATH)MLX42

# ------------------------------------------------------------------------------------< OBJECTS >---
OBJS_PATH := objs/
OBJS := $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))


#==================================================================================================|
#                                               RULES                                              |
#==================================================================================================|

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c 
	@$(CC) $(CFLAGS) -o $@ $(INCL) $(HEADER) -c $<

all: libmlx libft $(NAME)
	clear
	@echo "$(GRN)$(BLD)\nWELCOME TO\n$(BLU)$$TITLE$(WTH)"

$(NAME): $(OBJS_PATH) $(OBJS)
	@$(CC) $(CFLAGS) $(HEADER) $(OBJS) $(LIBS) -o $@
	@echo "\t\t$(WTH)./fdf executable ___________________ $(GRN)$(BLD)[CREATED]"
	@sleep 2

$(OBJS_PATH):
	@$(DIR) $(OBJS_PATH) 2> /dev/null || true

libmlx:
	@$(CMK) -DDEBUG=1 -DGLFW_FETCH=0 $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 \
		&& $(MK) -C $(LIBMLX)/build -j4 > /dev/null 2>&1

libft:
	@$(MK) -C $(LIBFT) all

clean:
	@$(RM) $(OBJS_PATH)
	@$(RM) $(LIBMLX)/build
	@$(MK) -C $(LIBFT) clean
	@echo "\t\t$(WTH)./fdf executable ___________________ $(RED)$(BLD)[DELETED]"

fclean: clean
	@$(RM) $(NAME)
	@$(MK) -C $(LIBFT) fclean

re: fclean all
	
# --------------------------------------------------------------------------------------< UTILS >---

backup:
	clear
	@echo "\n$(BLD)[BACKING UP FDF]\n"
	@tar -czvf fdf_backup_$(shell date +%Y%m%d_%H%M).tar.gz ./* > /dev/null 2>&1
	@mv fdf_backup_$(shell date +%Y%m%d_%H%M).tar.gz ~/Desktop/
	@sleep 4 && clear
	@echo "\n$(GRN)$(BLD)[FDF BACKUP NOW LOCATED ON DESKTOP]\n"

norm:
	clear
	@echo "$(GRN)$(BLD)[NORMINETTE - LIBFT SOURCE FILES]$(WTH)"
	@norminette -R CheckForbiddenSourceHeader lib/LIBFT/srcs | awk '{ printf("%65s\n", $$0) }'
	@echo "\n$(GRN)$(BLD)[NORMINETTE - FDF SOURCE FILES]$(WTH)"
	@norminette -R CheckForbiddenSourceHeader $(SRCS_PATH) | awk '{ printf("%65s\n", $$0) }'
	@echo "\n$(GRN)$(BLD)[NORMINETTE - INCLUDES]$(WTH)"
	@norminette -R CheckDefine lib/LIBFT/$(INCL_PATH) | awk '{ printf("%65s\n", $$0) }'
	@norminette -R CheckDefine $(INCL_PATH) | awk '{ printf("%65s\n", $$0) }'

clean+: fclean
		@$(RM) fdf.dSYM
		@$(RM) *.pdf
		@$(RM) .vscode
		@$(RM) .DS_Store