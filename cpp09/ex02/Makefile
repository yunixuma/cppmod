# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/11/14 20:08:24 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= PmergeMe

# Enumeration of files
SRC				= main.cpp PmergeMe.cpp PmergeMe_lst.cpp PmergeMe_vec.cpp

# Check the platform
OS				= $(shell uname)

# Defination of macro constants

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
OBJDIR			= ./obj

# Aliases of commands
CXX				= c++
RM				= rm

# Command options (flags)
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
INCLUDES		= -I$(INCDIR)
RMFLAGS			= -r
DEBUGCFLAGS		= -g -ggdb -fsanitize=address -fno-omit-frame-pointer
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
DEBUGLDFLAGS	= -fsanitize=address

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	CXXFLAGS	+= $(DEBUGCFLAGS)
	LDFLAGS		+= $(DEBUGLDFLAGS)
	DEF			+= -D DEBUG_MODE=1
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
test: debug test_error test_small test_large
test_error:
	@echo "\n\033[31;1;3mIrregular tests\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
	@echo "\033[43mTest case: Only one arguments\033[m"
	-./$(NAME) 9
	@echo "\033[41mTest case: Empty string\033[m"
	-./$(NAME) 9 3 5 ""
	@echo "\033[41mTest case: Non-numerical argument\033[m"
	-./$(NAME) 9 3 5 8 6 x
	@echo "\033[2;3mIrregular tests finished\033[m"
test_small:
	@echo "\n\033[32;1;3mSmall tests: \033[m"
	@echo "\033[43mTest case:  5 elements\033[m"
	-./$(NAME) `jot -r 5 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case:  6 elements\033[m"
	-./$(NAME) `jot -r 6 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case:  7 elements\033[m"
	-./$(NAME) `jot -r 7 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case:  8 elements\033[m"
	-./$(NAME) `jot -r 8 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case:  9 elements\033[m"
	-./$(NAME) `jot -r 9 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case: 10 elements\033[m"
	-./$(NAME) `jot -r 10 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case: 11 elements\033[m"
	-./$(NAME) `jot -r 11 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case: 12 elements\033[m"
	-./$(NAME) `jot -r 12 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case: 13 elements\033[m"
	-./$(NAME) `jot -r 13 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case: 14 elements\033[m"
	-./$(NAME) `jot -r 14 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case: 15 elements\033[m"
	-./$(NAME) `jot -r 15 0 9 | tr '\n' ' '`
	@echo "\033[43mTest case: 16 elements\033[m"
	-./$(NAME) `jot -r 16 0 9 | tr '\n' ' '`
	@echo "\033[2;3mSmall tests finished\033[m"
test_large:
	@echo "\n\033[32;1;3mLarge tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[43mTest case: 3000 elements (trial 1)\033[m"
	-./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`
	@echo "\033[43mTest case: 3000 elements (trial 2)\033[m"
	-./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`
	@echo "\033[43mTest case: 3000 elements (trial 3)\033[m"
	-./$(NAME) `jot -r 3000 1 100000 | tr '\n' ' '`
	@echo "\033[2;3mLarge tests finished\033[m"

# Recipes
$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
