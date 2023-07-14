# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/07/15 02:45:16 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= array

# Enumeration of files
SRC				= main.cpp
SRC_SAMPLE		= main_sample.cpp

# Check the platform
OS				= $(shell uname)

# Defination of macro constants

# Enumeration of directories

# Aliases of commands
CPP				= c++
RM				= rm

# Command options (flags)
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
INCLUDES		= -I
RMFLAGS			= -r
DEBUGCFLAGS		= -g -ggdb -fsanitize=address -fno-omit-frame-pointer
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
DEBUGLDFLAGS	= -fsanitize=address

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	CPPFLAGS	+= $(DEBUGCFLAGS)
	LDFLAGS	+= $(DEBUGLDFLAGS)
	DEF		+= -D DEBUG_MODE=1
endif

ifeq ($(MAKECMDGOALS), sample)
	SRC		=  $(SRC_SAMPLE)
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all fclean re debug

# Mandatory targets
all: $(NAME)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
clean: 
	-$(RM) $(RMFLAGS) *.su
re: fclean all

# Additional targets
debug: fclean all
sample: debug

# Recipes
$(NAME):
	$(CPP) $(CPPFLAGS) $(LDFLAGS) $(SRC) -o $(NAME)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
