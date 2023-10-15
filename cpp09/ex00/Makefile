# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 15:04:04 by ykosaka           #+#    #+#              #
#    Updated: 2023/10/15 23:53:45 by Yoshihiro K      ###   ########.fr        #
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
test: debug test_sample test_arg test_except test_edge
test_sample:
	@echo "\n\033[32;1;3mRegular tests: \033[m"
	@echo "\n\033[33;42mTest case: sample\033[m"
	-./$(NAME) ./res/input.txt
test_arg:
	@echo "\n\033[31;1;3mError handling tests for arguments\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
	@echo "\033[41mTest case: Too many arguments\033[m"
	-./$(NAME) ./res/input.txt ./res/input.txt
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
	-mv ./data.csv ./res/data_original.csv
	-./$(NAME)
	@echo "\033[41mTest case: Invalid date format\033[m"
	-cp -r ./res/data_dateformat.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: Outdate (before 19700101)\033[m"
	-cp -r ./res/data_toopast.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: Outdate (after 20380119)\033[m"
	-cp -r ./res/data_toofuture.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: Negative amount\033[m"
	-cp -r ./res/data_negative.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: No amount\033[m"
	-cp -r ./res/data_noamount.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: Multiple delimiters\033[m"
	-cp -r ./res/data_delims.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: Empty line contains in data\033[m"
	-cp -r ./res/data_emptyline.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: No data\033[m"
	-cp -r ./res/data_emptydata.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: Empty data file\033[m"
	-cp -r ./res/data_empty.csv ./data.csv
	-./$(NAME) ./res/input.txt
	@echo "\033[41mTest case: Only \\\n in data file\033[m"
	-cp -r ./res/data_onlynl.csv ./data.csv
	-./$(NAME) ./res/input.txt
	-mv ./res/data_original.csv ./data.csv
	@echo "\033[31;43mTest case: Empty parameter file\033[m"
	-./$(NAME) ./res/input_empty.txt
test_edge: 
	@echo "\n\033[32;1;3mEdge case tests: \033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[31;43mTest case: Invalid date format\033[m"
	-./$(NAME) ./res/input_dateformat.txt
	@echo "\033[31;43mTest case: Outdate (before 19700101)\033[m"
	-./$(NAME) ./res/input_toopast.txt
	@echo "\033[31;43mTest case: Outdate (after 20380119)\033[m"
	-./$(NAME) ./res/input_toofuture.txt
	@echo "\033[31;43mTest case: Not issued yet\033[m"
	-./$(NAME) ./res/input_notissue.txt
	@echo "\033[31;43mTest case: Negative amount\033[m"
	-./$(NAME) ./res/input_negative.txt
	@echo "\033[31;43mTest case: No amount\033[m"
	-./$(NAME) ./res/input_noamount.txt
	@echo "\033[31;43mTest case: Multiple delimiters\033[m"
	-./$(NAME) ./res/input_delims.txt
	@echo "\033[31;43mTest case: Empty line contains in parameters\033[m"
	-./$(NAME) ./res/input_emptyline.txt
	@echo "\033[31;43mTest case: No parameters\033[m"
	-./$(NAME) ./res/input_emptyparam.txt
	@echo "\033[31;43mTest case: Only \\\n in parameters\033[m"
	-./$(NAME) ./res/input_onlynl.txt
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
