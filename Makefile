# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 20:01:28 by tlukanie          #+#    #+#              #
#    Updated: 2023/06/27 12:13:29 by tlukanie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS 		:= -Wall -Werror -Wextra 
NAME 		:= fractol
LIBFT		:= ./libs/libft/srcs/
LIBMLX 		:= ./libs/MLX/
HEADERS 	:= -I includes -I libs/libft/srcs -I libs/MLX/include 
SRCDIR		:= ./srcs/
BONUSDIR 	:= ./bonus/

ifeq ($(OS), Windows_NT)
	include Makefile_windows.mk 
else 
	include Makefile_unix.mk
endif

# to automatically initialize the submodules for people who cannot read READMEs
ifeq ($(SUBM_STATE),)
SUBM_FLAG	= submodule
else 
SUBM_FLAG	= 
endif

all : $(SUBM_FLAG) $(OBJS) libft libmlx compile

submodule: 
	git submodule init 
	git submodule update

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@echo ${Q}${NL}${BLUE}======== libft ========${NC}${Q}
	@$(MAKE) -C $(LIBFT)

libmlx:
	@echo ${Q}${NL}${BLUE}======== MLX42 ========${NC}${Q}
	@$(MAKE) -C $(LIBMLX)

compile:
	@echo ${Q}${NL}${PURPLE}Fractol compiling!${NC}${Q}
	$(CC) $(CFLAGS) -g $(HEADERS) $(SRCS) $(LIBMLX)libmlx42.a $(LIBFT)libft.a $(LIBS) $(DEBUG) -o $(NAME)

bonus: $(SUBM_FLAG) libft libmlx
	@echo "${NL}${PURPLE}Fractol + bonus compiling!${NC}"
	$(CC) $(CFLAGS) -g  $(HEADERS) $(LIBS) $(BONUS) $(LIBMLX)libmlx42.a $(LIBFT)libft.a $(DEBUG) -o $(NAME)

# run this to install the required packages for Linux
install on linux:
	@sudo apt update && sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev


clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -rf $(NAME) fractal
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

re: fclean all

.PHONY: all, libft, libmlx, compile, install on linux, clean, fclean, re, bonus
