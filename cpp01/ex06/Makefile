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
CXX				= c++
RM				= rm

# Command options (flags)
//CXXFLAGS		= -Wall -Wextra -Werror -std=c++98
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
.PHONY: all clean fclean re debug \
	test test_abnormal test_level test_levels

# Mandatory targets
all: $(NAME)
clean:
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
debug: fclean all
test: re test_abnormal test_levels
test_abnormal:
	@echo "\n\033[31;3mAbnormal tests\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	@echo "\033[41mTest case: No arguments\033[m"
	-./$(NAME)
	@echo "\033[41mTest case: Too many arguments\033[m"
	-./$(NAME) "DEBUG" "WARNING"
	@echo "\033[41mTest case: Undefined log level\033[m"
	-./$(NAME) "Undefined"
	@echo "\033[2;3mAbnormal tests finished\033[m"
test_level:
	@echo "\033[42mTest case: $(case) level\033[m"
	-./$(NAME) $(case)
test_levels:
	@echo "\n\033[32;3mRegular tests\033[m"
	@echo "To continue, hit the [Enter] key"
	-@read _
	-@$(MAKE) -s case=ERROR		test_level
	-@$(MAKE) -s case=WARNING	test_level
	-@$(MAKE) -s case=INFO		test_level
	-@$(MAKE) -s case=DEBUG		test_level
	@echo "\033[2;3mRegular tests finished\033[m"

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
