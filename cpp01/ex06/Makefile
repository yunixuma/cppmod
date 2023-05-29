# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/05/29 15:44:39 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= harlFilter

# Enumeration of files
SRC				= main.cpp Harl.cpp

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
//CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
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
.PHONY: all clean fclean re debug \
	test test_noarg test_toomany test_undefined \
	test_log test_log_ERROR test_log_WARNING test_log_INFO test_log_DEBUG

# Mandatory targets
all: $(NAME)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
debug: fclean all
test: re test_noarg test_toomany test_undefined \
	test_log_ERROR test_log_WARNING test_log_INFO test_log_DEBUG
test_noarg:
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
test_toomany:
	@echo "\033[41mTest case: Too many arguments\033[m"
	-./$(NAME) "DEBUG" "WARNING"
test_undefined:
	@echo "\033[41mTest case: Undefined log level\033[m"
	-./$(NAME) "Undefined"
test_log:
	@echo "\033[42mTest case: $(case) level\033[m"
	-./$(NAME) $(case)
test_log_ERROR:
	$(MAKE) -s case=$(subst test_log_,,$(MAKECMDGOALS)) test_log
test_log_WARNING:
	$(MAKE) -s case=$(subst test_log_,,$(MAKECMDGOALS)) test_log
test_log_INFO:
	$(MAKE) -s case=$(subst test_log_,,$(MAKECMDGOALS)) test_log
test_log_DEBUG:
	@$(MAKE) -s case=$(subst test_log_,,$(MAKECMDGOALS)) test_log

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