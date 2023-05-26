# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/05/15 17:21:12 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= phonebook

# Enumeration of files
SRC				= main.c PhoneBook.c Contact.c

# Defination of macro constants

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
OBJDIR			= ./obj

# Aliases of commands
CC				= cc
RM				= rm

# Command options (flags)
CFLAGS		= -Wall -Wextra -Werror
DEBUGCFLAGS		= -g -ggdb -fno-omit-frame-pointer -fsanitize=thread
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
#DEBUGLDFLAGS	= -fsanitize=address
INCLUDES		= -I$(INCDIR)
RMFLAGS			= -r
LDFLAGS			= -lreadline

# Check the platform
OS				= $(shell uname)

# Redefination when the specific target

# Macros to replace and/or integrate
SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re

# Mandatory targets
all: $(NAME)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets

# Recipes
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
