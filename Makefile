# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccliffor <ccliffor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/28 18:23:53 by ccliffor          #+#    #+#              #
#    Updated: 2018/09/05 15:17:49 by ccliffor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program #
NAME = RTv1
SRC_FILES = main.c init.c input.c ray.c render.c update.c read_scene.c \
	load_entities.c
SRC_DIR = src
SRCS = $(SRC_FILES:%=$(SRC_DIR)/%)
SDL2_CONFIG = SDL2/bin/sdl2-config
SDL2_SRCS = SDL2-2.0.8
LIBFT = libft
LIB3D = lib3d

## Compiling, lib
INCLUDE = include
HEADER_FILES = window.h scene.h camera.h light.h object.h
HEADERS = $(HEADER_FILES:%=$(INCLUDE)/%)
CC = clang
WFLAGS = -Wall -Werror -Wextra
CFLAGS = $(WFLAGS) -I$(INCLUDE) $(LIBFT)/libft.a $(LIB3D)/lib3d.a

## Colours
COLOR_CLEAR = \033[0m
COLOR_CYAN = \033[01;36m
COLOR_GREEN = \033[01;32m
COLOR_RED = \033[01;31m

.PHONY: clean fclean re

# Rules #

## Core
all: $(NAME)

$(NAME): $(LIBFT) $(LIB3D) $(SDL2_CONFIG) $(SRCS) $(HEADERS)
	@$(CC) $(CFLAGS) $(SRCS) -o $@ $(shell ./$(SDL2_CONFIG) --cflags --libs)
	@echo "$(COLOR_CYAN)$(NAME)\t\t$(COLOR_GREEN)Binary compiled$(COLOR_CLEAR)"

$(LIB3D):
	@git clone https://github.com/cjclifford/lib3d.git $(LIB3D)
	make -C lib3d

$(LIBFT):
	@git clone https://github.com/cjclifford/libft.git $(LIBFT)
	@make -C libft

$(SDL2_CONFIG):
	@git clone https://github.com/davidsiaw/SDL2.git $(SDL2_SRCS)
	cd $(SDL2_SRCS);\
	mkdir -p build;\
	cd build;\
	../configure --prefix=$(CURDIR)/SDL2;\
	make -j6; make install

## General
clean:
	@echo "$(COLOR_RED)There are no object files to clean$(COLOR_CLEAR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_CYAN)$(NAME)\t\t$(COLOR_RED)Binary removed$(COLOR_CLEAR)\n"

re: fclean all

run: re
	./RTv1 scenes/light-test
