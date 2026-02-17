# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 15:34:34 by stanaka2          #+#    #+#              #
#    Updated: 2026/02/17 16:26:59 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# -------------------------- #
#         Phony Rules        #
# -------------------------- #

.PHONY: all clean fclean re norm debug san format tidy

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

SHELL =	/bin/bash

ifeq ($(filter re,$(MAKECMDGOALS)),re)
MAKEFLAGS += --no-print-directory
else
MAKEFLAGS += --no-print-directory -j
endif

RM = rm -f

# -------------------------- #
# 　　　　　　Target　　　      #
# -------------------------- #

NAME = hi_this_is_brain

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic-errors

ifeq ($(filter san,$(MAKECMDGOALS)),san)
CXXFLAGS	+= -g -fsanitize=address,undefined
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
CXXFLAGS	+= -g
endif

# -------------------------- #
#        Source Files        #
# -------------------------- #


SRCS	=	main.cpp


# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

# patsubst: Pattern substitution function
OBJ_DIR		=	.obj
OBJS		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
 

# -MT: Set the target name in the dependency file (uses automatic variable $@ for current target)
# -MMD: Generate dependency file (.d) during compilation, excluding system headers
# -MP: Add phony targets for each dependency to avoid errors when header files are deleted
# -MF: Specify the output path for the dependency file ($* is the stem without extension)
DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
DEPS		=	$(patsubst %.cpp, $(DEP_DIR)/%.d, $(notdir $(SRCS)))

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# -------------------------- #
#        Main Targets        #
# -------------------------- #

all	: $(NAME)

# Link object files to create executable
# $^: All prerequisites (all .o files)
# $@: Target name ($(NAME))
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo -e "[CPP_MODULE_01] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#        Build Rules         #
# -------------------------- #

# Pattern rule: compile .cpp to .o with dependency generation
# |: Order-only prerequisites (directories must exist but don't trigger rebuild)
# $<: First prerequisite (the .cpp file)
# $@: Target (the .o file)
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	@$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

# Create object directory if it doesn't exist
# -: Ignore errors (no error if directory already exists)
$(OBJ_DIR):
	@-mkdir -p $@

# Create dependency directory if it doesn't exist
$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

# Build with AddressSanitizer and UndefinedBehaviorSanitizerr
san:	$(NAME)

# Build with debug symbols
debug:  $(NAME)

# Static analysis with scan-build (Clang static analyzer)
sbuild:
	@$(MAKE) fclean
	scan-build make
	@$(MAKE) fclean


# -------------------------- #
#    Format / Lint Rules     #
# -------------------------- #

format:
	@echo -e "[CPP_MODULE_01] $(BLUE)Run clang-format$(DEF_COLOR): *.cpp"
	@clang-format -i $(SRCS)

tidy:
	@echo -e "[CPP_MODULE_01] $(BLUE)Run clang-tidy$(DEF_COLOR): *.cpp"
	@/usr/bin/clang-tidy-12 $(SRCS) -- $(CXXFLAGS)

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

# Remove object and dependency files only
clean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[CPP_MODULE_01] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

# Remove everything including executable and directories
fclean:
	@$(RM) $(OBJS) $(DEPS)
	@echo -e "[CPP_MODULE_01] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[CPP_MODULE_01] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)"

# Full rebuild: clean everything and rebuild
re:	fclean all

# -------------------------- #
#         Test Rules         #
# -------------------------- #

# test:
# 	bash tests/test.sh > tests/test.log

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

# Include all .d files (dependency files generated by -MMD)
# -: Ignore errors if .d files don't exist yet (first build)
-include $(DEPS)
