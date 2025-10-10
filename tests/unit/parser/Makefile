# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 21:44:39 by pecavalc          #+#    #+#              #
#    Updated: 2025/10/10 23:10:49 by pecavalc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Parser Unit Tests Makefile

# Unit test directories, sources and binaries
TEST_SRC_DIR 		= ./src
TEST_BIN_DIR 		= ./bin
TEST_SRC 			= $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_BIN 			= $(patsubst $(TEST_SRC_DIR)/%.c, $(TEST_BIN_DIR)/%, $(TEST_SRC))

# Parser module directories and object files
PARSER_OBJ_DIR 			= ../../../obj/parser
PARSER_PUB_HEADER_DIR	= ../../../include
PARSER_LOC_HEADER_DIR	= ../../../src/parser
PARSER_OBJ 				= $(shell find $(PARSER_OBJ_DIR) -name '*.o')

# Libft
LIBFT_DIR 			= ../../../libs/Libft-2.1.1
LIBFT_HEADER_DIR	= $(LIBFT_DIR)/include
LIBFT 				= $(LIBFT_DIR)/libft.a

# Ensure bin folder exists
$(shell mkdir -p $(TEST_BIN_DIR))

CFLAGS  := -Wall -Wextra -Werror -I$(PARSER_PUB_HEADER_DIR) \
								 -I$(PARSER_LOC_HEADER_DIR) \
           						 -I$(LIBFT_HEADER_DIR) \
          						 -I$(TEST_SRC_DIR)

# Default target: build all parser tests
all: $(TEST_BIN)

# Rule to build each test binary
$(TEST_BIN_DIR)/%: $(TEST_SRC_DIR)/%.c $(LIBFT)
	make -C ../../../
	cc $(CFLAGS) $(TEST_SRC_DIR)/$*.c $(PARSER_OBJ) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean fclean re

# Clean only parser test binaries
clean:
	rm -f $(TEST_BIN)
	rm -f $(PARSER_OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

# Full clean (optional)
fclean: clean 
	rm -f $(TEST_BIN_DIR)/*
	$(MAKE) fclean -C $(LIBFT_DIR)

# Rebuild all parser tests
re: fclean all
