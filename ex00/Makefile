# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/03/07 04:19:29 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= megaphone

# Enumeration of files
SRC				= $(NAME).cpp

# Defination of macro constants
DEF				= -DN_RESOURCE=2

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
OBJDIR			= ./obj

# Aliases of commands
CPP				= c++
RM				= rm

# Command options (flags)
//CPPFLAGS			= -Wall -Wextra -Werror -std=c++98
DEBUGCFLAGS		= -g -ggdb -fno-omit-frame-pointer -fsanitize=thread
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
#DEBUGLDFLAGS	= -fsanitize=address
OPTCFLAGS		= -O3 -march=native
OPTCFLAGS_FAST	= -Ofast -march=native
INCLUDES		= -I$(INCDIR)
RMFLAGS			= -r

# Check the platform
OS				= $(shell uname)

# Redefination when the specific target

# Macros to replace and/or integrate

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all fclean re

# Mandatory targets
all: $(NAME)
fclean:
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets

# Recipes
$(NAME):
	$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
