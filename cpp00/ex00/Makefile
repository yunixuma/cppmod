# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/09/07 16:27:57 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= megaphone

# Enumeration of files
SRC				= $(NAME).cpp

# Check the platform
OS				= $(shell uname)

# Aliases of commands
CXX				= c++
RM				= rm

# Command options (flags)
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
DEBUGCFLAGS		= -g -ggdb -fsanitize=address -fno-omit-frame-pointer
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
RMFLAGS			= -r

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	CXXFLAGS	+= $(DEBUGCFLAGS)
	LDFLAGS		+= $(DEBUGLDFLAGS)
	DEF			+= -D DEBUG_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all fclean re

# Mandatory targets
all: $(NAME)
fclean:
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
debug: fclean all

# Recipes
$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
