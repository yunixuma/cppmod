# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/06/29 17:54:07 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= conversion

# Enumeration of files
SRC				= main.cpp Conversion.cpp

# Check the platform
OS				= $(shell uname)

# Defination of macro constants

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
OBJDIR			= ./obj

# Aliases of commands
CPP				= c++
RM				= rm

# Command options (flags)
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
INCLUDES		= -I$(INCDIR)
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

# Macros to replace and/or integrate
SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.cpp=.d)))

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re debug

# Mandatory targets
all: $(NAME)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
debug: fclean all

# Recipes
$(NAME): $(OBJS)
	$(CPP) $(LDFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
