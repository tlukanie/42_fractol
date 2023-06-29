# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_unix.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 20:01:16 by tlukanie          #+#    #+#              #
#    Updated: 2023/06/28 22:32:02 by tlukanie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS 		:= $(shell uname -s)
ARCH 	:= $(shell uname -m)
SUBM_STATE := $(shell find libs/libft -type f)
DEBUG 		:= -fsanitize=address 

BONUS	:= ./libs/libft/srcs/*.c \
			./bonus/burning_ship_set.c \
		  ./bonus/julia_set.c \
		  ./bonus/mandelbrot_set.c \
		  ./bonus/fractol.c \
		  ./bonus/hooks_functions.c \
		  ./bonus/viewport_utils.c \
		  ./bonus/manage_colors.c \

SRCS	:= ./libs/libft/srcs/*.c \
		  ./srcs/burning_ship_set.c \
		  ./srcs/julia_set.c \
		  ./srcs/mandelbrot_set.c \
		  ./srcs/fractol.c \
		  ./srcs/hooks_functions.c \
		  ./srcs/viewport_utils.c \
		  ./srcs/manage_colors.c \

NL		:= \n
Q		:= "
NC		:= \033[0m
RED 	:= \033[1;31m
GREEN 	:= \033[1;32m
BLUE 	:= \033[1;34m
PURPLE	:= \033[35;1m

# determining architecture for the Mac
ifeq ($(ARCH), x86_64)
GLFW 	:= libs/MLX/lib/lib-x86_64/libglfw3.a
else ifeq ($(ARCH), arm)
GLFW 	:= libs/MLX/lib/lib-arm64/libglfw3.a
else 
GLFW 	:= libs/MLX/lib/lib-universal/libglfw3.a
endif

# for cross-platform compatibility
ifeq ($(OS), Darwin)
LIBS	:= -framework Cocoa -framework OpenGL, -framework IOKit $(GLFW)
else ifeq ($(OS), Linux)
LIBS	:= -ldl -lglfw
endif
