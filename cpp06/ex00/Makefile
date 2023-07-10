# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/07/10 10:44:30 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= convert

# Enumeration of files
SRC				= main.cpp ScalarConverter.cpp

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
test: re test_abnormal test_regular test_pseudo
test_abnormal:
	@echo "\n\033[31;3mAbnormal tests\033[m"
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
	@echo "\033[41mTest case: Too many arguments\033[m"
	-./$(NAME) 4 2
	@echo "\033[41mTest case: Empty string\033[m"
	-./$(NAME) ""
	@echo "\033[41mTest case: Neither number nor single char\033[m"
	-./$(NAME) ".."
	@echo "\033[41mTest case: No integer part\033[m"
	-./$(NAME) ".5"
	@echo "\033[41mTest case: Over int type\033[m"
	-./$(NAME) "2147483648"
	@echo "\033[2;3mAbnormal tests finished\033[m"
test_regular:
	@echo "\n\033[33;42mRegular tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\n\033[33;42mTest case: char\033[m"
	-./$(NAME) .
	@echo "\n\033[33;42mTest case: positive integer (printable char)\033[m"
	-./$(NAME) 42
	@echo "\n\033[33;42mTest case: negative integer (not printable)\033[m"
	-./$(NAME) -42
	@echo "\n\033[33;42mTest case: zero\033[m"
	-./$(NAME) 0
	@echo "\n\033[33;42mTest case: zero w/ sign\033[m"
	-./$(NAME) -0
	@echo "\n\033[33;42mTest case: float\033[m"
	-./$(NAME) 2.7183f
	@echo "\n\033[33;42mTest case: double\033[m"
	-./$(NAME) 2.7183
test_pseudo:
	@echo "\n\033[33;42mPseudo tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\n\033[33;42mTest case: nan\033[m"
	-./$(NAME) nan
	@echo "\n\033[33;42mTest case: nanf\033[m"
	-./$(NAME) nanf
	@echo "\n\033[33;42mTest case: inf\033[m"
	-./$(NAME) inf
	@echo "\n\033[33;42mTest case: inff\033[m"
	-./$(NAME) inff
	@echo "\n\033[33;42mTest case: +inf\033[m"
	-./$(NAME) +inf
	@echo "\n\033[33;42mTest case: +inff\033[m"
	-./$(NAME) +inff
	@echo "\n\033[33;42mTest case: -inf\033[m"
	-./$(NAME) -inf
	@echo "\n\033[33;42mTest case: -inff\033[m"
	-./$(NAME) -inff
	@echo "\033[2;3mRegular tests finished\033[m"

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
