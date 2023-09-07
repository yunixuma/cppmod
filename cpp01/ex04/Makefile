# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/09/07 16:27:57 by ykosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= sed

# Enumeration of files
SRC				= main.cpp sed.cpp

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
.PHONY: all fclean re debug test test_regular test_abnormal

# Mandatory targets
all: $(NAME)
fclean:
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
debug: fclean all
test: re test_regular test_abnormal
test_regular:
	@echo "\n\033[32;3mRegular tests\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[42mCASE: search & replace a single character\033[m"
	./$(NAME) Makefile p @
	@echo "\n\033[42mCASE: search & replace a string\033[m"
	./$(NAME) main.cpp std NAMESPACE
	@echo "\n\033[42mCASE: replace to repeated characters\033[m"
	./$(NAME) main.cpp.replace : ::
	@echo "\033[2;3mRegular tests finished\033[m"
test_abnormal:
	@echo "\n\033[31;3mAbnormal tests\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	-./$(NAME) Makefile p
	@echo "\n\033[41mCASE: too many arguments\033[m"
	-./$(NAME) main.cpp std NAME SPACE 
	@echo "\n\033[41mCASE: no such a file\033[m"
	-./$(NAME) no_exists " " "[SPACE]"
	@echo "\n\033[41mCASE: determine a directory\033[m"
	-./$(NAME) ./ " " "[SPACE]"
	@echo "\033[2;3mAbnormal tests finished\033[m"

# Recipes
$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
