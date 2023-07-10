# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/07/10 19:23:43 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= iter

# Enumeration of files
SRC				= main.cpp

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
DEBUGCFLAGS		= -g -ggdb -fno-omit-frame-pointer
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
DEBUGLDFLAGS	= -fsanitize=address

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	ifneq ($(OS), Darwin)
		CPPFLAGS	+= $(DEBUGCFLAGS)
		LDFLAGS	+= $(DEBUGLDFLAGS)
	endif
	DEF		+= -D DEBUG_MODE=1
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
