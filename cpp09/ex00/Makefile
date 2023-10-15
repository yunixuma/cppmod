# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/10/15 17:17:34 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= btc

# Enumeration of files
SRC				= main.cpp BitcoinExchange.cpp MonthlyData.cpp \
				  Parser.cpp DateConverter.cpp

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
test: re test_sample test_arg test_except test_edge
test_sample:
	@echo "\n\033[32;1;3mRegular tests: \033[m"
	@echo "\n\033[33;42mTest case: sample\033[m"
	-./$(NAME) ./files/input.txt
test_arg:
	@echo "\n\033[31;1;3mError handling tests for arguments\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
	@echo "\033[41mTest case: Too many arguments\033[m"
	-./$(NAME) ./files/input.txt ./files/input.txt
	@echo "\033[41mTest case: Empty string\033[m"
	-./$(NAME) ""
	@echo "\033[41mTest case: Directory\033[m"
	-./$(NAME) "./"
	@echo "\033[41mTest case: Input file not exists\033[m"
	-./$(NAME) nonexists.txt
test_except:
	@echo "\n\033[31;1;3mError handling tests for exceptions\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[41mTest case: Data file not exists\033[m"
	-mv ./files/data.csv ./files/data_original.csv
	-./$(NAME)
	@echo "\033[41mTest case: Invalid date format\033[m"
	-cp -r ./files/data_dateformat.csv ./files/data.csv
	-./$(NAME) ./files/input.txt
	@echo "\033[41mTest case: Outdate (before 19700101)\033[m"
	-cp -r ./files/data_toopast.csv ./files/data.csv
	-./$(NAME) ./files/input.txt
	@echo "\033[41mTest case: Outdate (after 20380119)\033[m"
	-cp -r ./files/data_future.csv ./files/data.csv
	-./$(NAME) ./files/input.txt
	@echo "\033[41mTest case: Negative amount\033[m"
	-cp -r ./files/data_negative.csv ./files/data.csv
	-./$(NAME) ./files/input.txt
	@echo "\033[41mTest case: No amount\033[m"
	-cp -r ./files/data_noamount.csv ./files/data.csv
	-./$(NAME) ./files/input.txt
	@echo "\033[41mTest case: Multiple delimiters\033[m"
	-cp -r ./files/data_delims.csv ./files/data.csv
	-./$(NAME) ./files/input.txt
test_edge: 
	@echo "\n\033[32;1;3mEdge case tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[31;43mTest case: Invalid date format\033[m"
	-./$(NAME) ./files/input_dateformat.txt
	@echo "\033[31;43mTest case: Outdate (before 19700101)\033[m"
	-./$(NAME) ./files/input_toopast.txt
	@echo "\033[31;43mTest case: Outdate (after 20380119)\033[m"
	-./$(NAME) ./files/input_toofuture.txt
	@echo "\033[31;43mTest case: Not issued yet\033[m"
	-./$(NAME) ./files/input_notissue.txt
	@echo "\033[31;43mTest case: Negative amount\033[m"
	-./$(NAME) ./files/input_negative.txt
	@echo "\033[31;43mTest case: No amount\033[m"
	-./$(NAME) ./files/input_noamount.txt
	@echo "\033[31;43mTest case: Multiple delimiters\033[m"
	-./$(NAME) ./files/input_delims.txt
	@echo "\033[2;3mAbnormal tests finished\033[m"

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
