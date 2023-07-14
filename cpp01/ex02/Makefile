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
NAME			= brain

# Enumeration of files
SRC				= main.cpp

# Check the platform
OS				= $(shell uname)

# Aliases of commands
CPP				= c++
RM				= rm

# Command options (flags)
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
DEBUGCFLAGS		= -g -ggdb -fsanitize=address -fno-omit-frame-pointer
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
RMFLAGS			= -r

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	CPPFLAGS	+= $(DEBUGCFLAGS)
	LDFLAGS		+= $(DEBUGLDFLAGS)
	DEF			+= -D DEBUG_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all fclean re debug

# Mandatory targets
all: $(NAME)
fclean:
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
debug: fclean all

# Recipes
$(NAME):
	$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
