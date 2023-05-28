# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/05/28 18:22:26 by ykosaka          ###   ########.fr        #
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
CPP				= c++
RM				= rm

# Command options (flags)
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
DEBUGCFLAGS		= -g -ggdb -fno-omit-frame-pointer
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif
RMFLAGS			= -r

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
test: re test_regular test_abnormal
test_regular:
	@echo "\n\033[32mRegular tests\033[m"
	@echo "\033[33mCASE search & replace a single character\033[m"
	./$(NAME) Makefile p @
	@echo "\n\033[33mCASE search & replace a string\033[m"
	./$(NAME) main.cpp std NAMESPACE
	@echo "\n\033[33mCASE replace to repeated characters\033[m"
	./$(NAME) main.cpp.replace : ::
test_abnormal:
	@echo "\n\033[32mAbnormal tests\033[m"
	@echo "\033[33mCASE too few arguments\033[m"
	-./$(NAME) Makefile p
	@echo "\n\033[33mCASE too many arguments\033[m"
	-./$(NAME) main.cpp std NAME SPACE 
	@echo "\n\033[33mCASE no such a file\033[m"
	-./$(NAME) no_exists " " "[SPACE]"
	@echo "\n\033[33mCASE determine a directory\033[m"
	-./$(NAME) ./ " " "[SPACE]"

# Recipes
$(NAME):
	$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
