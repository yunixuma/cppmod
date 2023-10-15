# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/10/16 03:15:34 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= RPN

# Enumeration of files
SRC				= main.cpp RPN.cpp

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
test: debug test_sample test_regular test_error
test_sample:
	@echo "\n\033[32;1;3mSample tests: \033[m"
	-./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	-./$(NAME) "7 7 * 7 -"
	-./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	-./$(NAME) "(1 + 1)"
	@echo "\033[2;3mSample tests finished\033[m"
test_regular:
	@echo "\n\033[32;1;3mRegular tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[33;42mTest case: Stack 3 vals (=> 24)\033[m"
	-./$(NAME) "3 6 2 + *"
	@echo "\033[33;42mTest case: Stack 1 vals (=> 3)\033[m"
	-./$(NAME) "3"
	@echo "\033[33;42mTest case: Cotain consecutive white spaces (=> 3)\033[m"
	-./$(NAME) "   1 2    +  "
	@echo "\033[33;42mTest case: No delimiters (=> 24)\033[m"
	-./$(NAME) "362+*"
	@echo "\033[2;3mRegular tests finished\033[m"
test_error:
	@echo "\n\033[31;1;3mError handling tests\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
	@echo "\033[41mTest case: Too many arguments\033[m"
	-./$(NAME) 4 2
	@echo "\033[41mTest case: Empty string\033[m"
	-./$(NAME) ""
	@echo "\033[41mTest case: Only white spaces\033[m"
	-./$(NAME) " "
	@echo "\033[41mTest case: No operators\033[m"
	-./$(NAME) "1 2"
	@echo "\033[41mTest case: Too few operators\033[m"
	-./$(NAME) "1 2 3 -"
	@echo "\033[41mTest case: End w/ too many operators\033[m"
	-./$(NAME) "1 2 ++"
	@echo "\033[41mTest case: End w/ multiple operators\033[m"
	-./$(NAME) "1 + 2 -"
	@echo "\033[41mTest case: End w/ a invalid token\033[m"
	-./$(NAME) "1 2 + x"
	@echo "\033[41mTest case: Divide by zero\033[m"
	-./$(NAME) "4 2 + 0 /"
	@echo "\033[2;3mError handling tests finished\033[m"

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
