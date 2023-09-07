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
test: debug test_error test_regular test_abnormal \
	test_pseudo test_over_int test_over_float
test_error:
	@echo "\n\033[31;1;3mError handling tests\033[m"
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
	@echo "\033[41mTest case: Too many arguments\033[m"
	-./$(NAME) 4 2
	@echo "\033[41mTest case: Empty string\033[m"
	-./$(NAME) ""
	@echo "\033[41mTest case: Consecutive white spaces\033[m"
	-./$(NAME) "  "
	@echo "\033[41mTest case: Neither number nor single char\033[m"
	-./$(NAME) ".."
	@echo "\033[41mTest case: End w/ consective float signs\033[m"
	-./$(NAME) "123.456ff"
	@echo "\033[41mTest case: Not a pseudo string\033[m"
	-./$(NAME) "NaN"
	@echo "\033[41mTest case: Too long characters value\033[m"
	-./$(NAME) "170141183460469231731687303715884105728"
	@echo "\033[2;3mError handling tests finished\033[m"
test_regular:
	@echo "\n\033[32;1;3mRegular tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\n\033[33;42mTest case: char\033[m"
	-./$(NAME) .
	@echo "\n\033[33;42mTest case: A white space\033[m"
	-./$(NAME) " "
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
	@echo "\033[2;3mRegular tests finished\033[m"
test_abnormal:
	@echo "\n\033[32;1;3mAbnormal tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[31;43mTest case: No integer part\033[m"
	-./$(NAME) ".5"
	@echo "\n\033[31;43mTest case: start w/ white spaces\033[m"
	-./$(NAME) "  123.4567"
	@echo "\033[31;43mTest case: Exponential notation (large number)\033[m"
	-./$(NAME) "1.234567890123456E012"
	@echo "\033[31;43mTest case: Exponential notation (small number)\033[m"
	-./$(NAME) "1.234567890123456e-012"
	@echo "\033[2;3mAbnormal tests finished\033[m"
test_pseudo:
	@echo "\n\033[32;1;3mPseudo tests: \033[m"
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
	@echo "\033[2;3mPseudo tests finished\033[m"
test_over_int:
	@echo "\n\033[33;1;3mOverflow tests for integer: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[31;43mTest case: Over INT_MAX\033[m"
	-./$(NAME) "2147483648"
	@echo "\033[31;43mTest case: Over INT_MAX (+64)\033[m"
	-./$(NAME) "2147483711"
	@echo "\033[31;43mTest case: Under INT_MIN\033[m"
	-./$(NAME) "-2147483649"
	@echo "\033[31;43mTest case: Under INT_MIN (-64)\033[m"
	-./$(NAME) "-2147483712"
	@echo "\033[31;43mTest case: LLONG_MAX\033[m"
	-./$(NAME) "9223372036854775807"
	@echo "\033[31;43mTest case: Over LLONG_MAX\033[m"
	-./$(NAME) "9223372036854775808"
	@echo "\033[31;43mTest case: LLONG_MIN\033[m"
	-./$(NAME) "-9223372036854775808"
	@echo "\033[31;43mTest case: Under LLONG_MIN\033[m"
	-./$(NAME) "-9223372036854775809"
	@echo "\033[2;3mOverflow tests for integer finished\033[m"
test_over_float:
	@echo "\n\033[33;1;3mOverflow tests for floating-point: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[31;43mTest case: Max. value of float data type\033[m"
	-./$(NAME) "3.402823e+38f"
	@echo "\033[31;43mTest case: Min. value of float data type\033[m"
	-./$(NAME) "-3.402823e+38f"
	@echo "\033[31;43mTest case: Min. fractional of float data type\033[m"
	-./$(NAME) "1.00000011920928955078125f"
	@echo "\033[31;43mTest case: Min. absolute of float data type\033[m"
	-./$(NAME) "1.175494e-38f"
	@echo "\033[31;43mTest case: Underflow at float data type\033[m"
	-./$(NAME) "1.000000059604644775390625f"
	@echo "\033[31;43mTest case: Max. value of double data type\033[m"
	-./$(NAME) "1.79769313486231570814527424e+308"
	@echo "\033[31;43mTest case: Min. value of double data type\033[m"
	-./$(NAME) "-1.79769313486231570814527424e+308"
	@echo "\033[31;43mTest case: Min. absolute of double data type\033[m"
	-./$(NAME) "2.225074e-308"
	@echo "\033[31;43mTest case: Min. fractional of double data type\033[m"
	-./$(NAME) "1.00000000000000000011102230246251565404236316680908203125e-309"
	@echo "\033[2;3mOverflow tests for floating-point finished\033[m"

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
