# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 18:20:14 by nfinkel           #+#    #+#              #
#    Updated: 2019/04/05 15:26:32 by nfinkel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Environment
OS :=					$(shell uname)

#	Output
NAME :=					libfts.a

#	Compiler
CC :=					gcc
FPIC :=					-fPIC
VERSION :=				-std=c11

ifeq ($(OS), Darwin)
	THREADS := 			$(shell sysctl -n hw.ncpu)
	FORMAT :=			-f macho64
	NASM :=				nasm64
	BONUS_DIR :=		./bonus_macho64/
	SRC_DIR :=			./src_macho64/
else
	THREADS :=			4
	FORMAT :=			-f elf64
	NASM :=				nasm
	BONUS_DIR :=		./bonus_elf64/
	SRC_DIR :=			./src_elf64/
endif

FAST :=					-j$(THREADS)
FLAGS :=				-Wall -Wextra -Werror
O_FLAG :=				-O2

#	Directories
OBJDIR :=				./build/

#	Sources
BONUS +=				ft_abs.s ft_itoa.s ft_memcmp.s ft_strcmp.s ft_memmove.s
SRC +=					ft_bzero.s ft_isalpha.s ft_isdigit.s ft_puts.s
SRC +=					ft_isalnum.s ft_isascii.s ft_isprint.s
SRC +=					ft_tolower.s ft_toupper.s ft_strlen.s ft_cat.s
SRC +=					ft_memset.s ft_memcpy.s ft_strcat.s ft_strdup.s

OBJECTS =				$(patsubst %.s,$(OBJDIR)%.o,$(SRCS))

SRCS +=					$(BONUS)
SRCS +=					$(SRC)

TESTMAIN :=				main.c

vpath %.s $(BONUS_DIR)
vpath %.s $(SRC_DIR)

#################
##    RULES    ##
#################

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $@ $(patsubst %.s,$(OBJDIR)%.o,$(SRCS))
	@ranlib $@
	@printf "\033[92m\033[1;32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-13s\033[32m[✔]\033[0m\n"

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o: %.s
	@printf "\033[1;92mCompiling $(NAME)\033[0m %-28s\033[32m[$<]\033[0m\n"
	@$(NASM) $(FORMAT) $< -o $@
	@printf "\033[A\033[2K"

clean:
	@/bin/rm -rf $(OBJDIR)
	@printf "\033[1;32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1;32m:\033[0m%-13s\033[32m[✔]\033[0m\n"

fast:
	@$(MAKE) --no-print-directory $(FAST)

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "\033[1;32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1;32m:\033[0m%-13s\033[32m[✔]\033[0m\n"

mrproper: fclean
	@/bin/rm -f test cat.test ft_cat.test

re: fclean fast

test: $(NAME)
	@printf "\033[92m\033[1;32mCompiling -------------> \033[91mtest.c\033[0m:\033[0m%-15s\033[32m[✔]\033[0m\n"
	@$(CC) $(TESTMAIN) $(FLAGS) $(O_FLAG) $(NAME) -o $@

.PHONY: all cat clean fast fclean mrproper re test

#################
##  WITH LOVE  ##
#################

cat:
	@clear;
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@#\`.\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@:\`\`\`,.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@.\`:\`\`.,,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@,.;,\`\`\`,,.\`,\`#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`:;\`\`  \`\`,::::.\`\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@#;;\`;\`   \`\`\`\`::::,\`+@@@@@;\`\`\`..,,,:,,,,.\`\`:#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;:\`\`;\`\`   \`\`\`\`\`,:::.\`,,::::::::::::::::::::,,..#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;,\`\`\`;\`\`    \`\`\`\`\`,::::::::::,,,,,,,,,,::::::::::,\`;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:,##+\`:,\`\`   \` \`\`\`\`,.:,\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.,::::::,\`\`@@@@@@@@@@@@@@@@@@@@@@@@\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.;#@;+\`;;\`\`   \`\`\`\`\`\` \`\`\`\`\`\`   \`\`\`\`\`\`   \`\`\`\`\`\`\`\`.::::::,\`@@@@@@@@@@@@@@@@@@@@@. @@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,\`#@##+:+;\`\`   \`\`\`\`    \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`  \`\`\`:::::::,.@@@@@@@@@@@@@@@@@\`,,\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`\`\`@#\`@@@#;\`\`  \`\`\`\`   \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`::::::::,\`#@@@@@@@@@@@@#\`::.\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`,:\`;@@@@@\`\`\`  \`\`\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`:::::::::,.@@@@@@+;:..::::\`\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:,#:@@@@@@@\`\`\`  \`\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`,:::::::::,::\`.:::::::::\`\`\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.;##@@@@@@@@:\`       \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`.::::::::::.::::::::,\`\` \`.@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.;##@@@@@@@@#.\`  \`   \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`,:::::::::,:.\`\`\`\`\`\`\` \`:,@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;\`,\`@@@@@@@@@#\`\`   \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`\`::::::::::\`\` \`\`\`   \`\`\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#;.\`\`@@@@@@@@#;\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`.:::::::::\`\` \`\`  \`;:@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,:.\`;#@@@##,\`\`\`   \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`  \`\`\`.::::::::\`\`    \`:.@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:+.:+#\`+#:\`\`\`\`\`\`   \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.:::::::\`\`\` \`+;\`@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`;\`::#\`.\`\`\`\`\` \`\`   \`\`\`  \`\`\`\`\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.:::::,\` \`:\`+\`@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@.+\` \`\`\`\`\`\`\` \`\`\`\`\`\`\`\`\`   \`\`\`\`\`\`\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`\`\`\`,:::,\`\`#+:;@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`.\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`\`\`###+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`\`\`\`.:\`#+\`\`@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@:\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`+##@@@@#+.\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`\`\`.:+#;\`@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@:\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`+#@@@@@@@@#:\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`,,:;;@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@@@@@@@@#;\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`:,\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@,:\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`@@@@@@@@@@@@@#,\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`:\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@,\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@@@@@@@@@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`,.@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`;#@@@@@@@@@@@@@@@+\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`;##\`\`\`\`,#@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@+;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@@##+\`+##@@@@#.\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@+\`\`\`,\`@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@,:\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@#,:...:+#@@@@+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@\`\`\`\`,@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@,,\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`:#@@@#,.,,,,,,\`#@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`:#@@@#\`\`\`,:@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@:\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`@@@#\`,,,,,,,,:+@@@#;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`+@@@@#;\`\`\`.@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+@@@#:,,,,,,,,,:#@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@@#\`\`\`,@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@;\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@#,,,,,,,,,,,#@@@#\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`####@@#\`\`\`.\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`;\` \`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@:,,,,,,,,,,,,#@@@.\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+:;+@@#:\`\`\`.@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@;;\` \`   \`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,,.,,,,,;#@@@;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`:,,:#@@+\`\`\`.@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@.;\`\`    \`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#;,,,,\` \`,,,,,#@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`:,,,+@@#\`\`\`\`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`:\`\` \`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,\`  ,,,,.+@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.,,,,#@#\`\`\`\`#@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`:\`\`\`\`  \`\`\`\`\`\`\`\`\`\`\`\` \`#@@#:,,,,   .,,,,;@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`,,,,;#@#\`\` \`;@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`:\`  \`  \`\`\`\`\`\`\`\`\`\`\`\` \`#@@#:,,,,   \`,,,,:#@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`,,,,:#@#.\`\`\`.@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`:\`  \`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,    ,,,,:#@@#\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`,\`.,,+@#:\`  \`@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`:\`     \`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,    ,,,,:#@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.. \`,,+@#;\`   @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`:\`     \`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,    ,,,,:#@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.  ,.\`@@;\`   @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@\`;\`    \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,\`   ,,,,:#@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`  ,.;@#;\` \` @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@.;\`\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+@@#:,,,,.  \`,,,;;#@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`  ,.;@#:\`\`\` @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@:\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`@@@:,,,,,  .,,#@@@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`  ,.;##:\`\`\` @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@+\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`;#@@#.,,,,\`\`,,,#@@@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`  ,.;##,\`\`\` @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,,,,,,,.+@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`,:#@#\`\`\`\` @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@#:,,,,,,,,,,,#@@@+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`. .,@@@#\`\`\`  @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@,,\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+@@@+,,,,,,,,,,;#@@@;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`,\`,,#@@#\`\`\`  @@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@.;\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`:#@@#,,,,,,,,,,;@@@#.\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`,,,,:@@#\`\`\` \`@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@;,\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@#:,,,,,,,:#@@@#\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`.,,,+@@+\`\`\` \`@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@+\`:\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+@@@##:,,,,,:#@@@@+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`:,,:#@#;\`\`\` \`@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@,:.\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.#@@@@#\`:::;#@@@@#\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`;::\`#@#.\` \` \`@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@+;\` \`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+@@@@@@####@@@@@+\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`:#\`#@@#\`\`\`\` @@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`;\`    \`\`\`\`\`\`\`\`\`\`\`\`\`\`.#@@@@@@@@@@@@@#.\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@\`\`\`\`\` @@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;.  \`\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@@@@@@@@#+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@#.\`\`\` \`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;;\` \`:,\`\`  \`\`\`\`\`\`\`\` \`\`+#@@@@@@@@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+@@@#\`\`\`\` \`@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.;\` \`;;,\` \`  \`\`\`\`\`\`\`\`\`+@@@@@@@@##\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`,#@#.\`\`\`\` @@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.:  \`\`\`\`;\`\`\`\`\`\`\`\`\`\`\`\`\`\`#@@@@##+\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`+#,\`\`    @@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@,\`  .\`\`\`\`;.\`\`\`  \`\`\`\`\`\`\`;+++,\`\`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`\`\`  \`\` #@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@;.@@@@@@@@@@@@@@.\`  ,\`\`\`\`\`;:\`\`       \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`  \`   @@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@\`;\`\`@@@@@@@@@@@@.\` \`:\`\`\`\`\`#+\`,\`\`\`\` \` \`\` \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`    @@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@\`+;:\`;@@@@@@@@@@.\` \`:\`\`\`\`@@@@#+;\`\`\`\`\`\`\`  \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\` \`\`   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@\`+\`\`\`;;;;;;;;;;;:,\` \`:\`\`\`+@@@@@@@##\`.\`\`\`\`\`\`    \`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`   \`\`\`\`.\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@.+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`;.  ,\`\`\`#@@@@@@@@@@##\`,\`\`\`\`\`\`    \`\` \`  \`\`\`\`\`\`\`\`\`\`\`   \`     \`\`.\`#:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@:+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`;\`  .;\`\`@@@@@@@@@@@@@@@##\`:.\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`.\`#@@\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@#\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`;.  \`;\`\`@@@@@@@@@@@@@@@@@@@@####+;,..\`\`\`\`\`\`\`\`\`\`\`\`\`.:\`###@@@@\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@\`+\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`\`;:\` \`;\`+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@########@@@@@@@@@@@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@:+\`\`\`\`\`\`\`::::,:::::,\` \`.;\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@.+\`\`\`\`\`\`:::,.,,,,.,,,\`\`\`:\`#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@.+\`\`\`\`\`;:::,,,..,,,,..\`\`\`\`#@@@@@@@@@@@@@@@@@@#@@@@@@@@@@#@@@@@@@@+@@#+,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@,+\`\`\`\`\`\`;::::,,,,,,,,,.\`\`,\`@@@@@@@@@@@@@@@@@##@@@@@@@@#.#@@@@@#+@@#.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@\`+\`\`\`\`\`\`\`;;::,,,,,,,,,,..\`.+#@@@@@@@@@@@@@@@#;#@@@##,##;+##;\`#@#,\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:+\`\`\`\`\`\`;;;;::,,,,,,,,..,.\`;#@@@@@@@@@@@@@@@#+::+#@@@@@##@##.;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,\`\`\`\`\`;;;:,,,:;;:,,,.,.\`.\`,,.\`##@@@@@@@@@@@@@@@@@@@@@@@#\`.+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`\`;;;;;;;;;;;;::,,. \`.  .,,,\`\`.\`###@@@@@@@@@@@@@@##;\`;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#..,;;,:;;;;;;:,,,....      ,,,,,,\`\`\`\`.,:\`\`+++++\`:,.:#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@:,;;;;\`\`\`;;;,,....,,,,,,.\`      ,,::::,,\`\`      \`...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@,+\`\`\`\`\`\`\`\`;;:,,,,,,,,\`         ,,:::::::,,.\`\`\`\`\`...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:+\`\`\`\`\`\`\`\`;;::,,,,,.          ::::::::::::::,,,,.+:\`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:+\`\`\`\`\`\`\`\`;;;:,.\`.:\`         :;::::::::::::::,\`  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`:\`\`\`\`\`\`\`\`;;:\`+@#\`\`          ,;;::::::::::::,.     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,:\`\`\`;;,.#@@@\`\`            .;\`\`:::::::::,;,   .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#;:@@@@@@\`\`              \`;\`\`\`;::::::\`\`:     #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:.                 \`;\`\`\`\`\`\`\`\`\`\`;       .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+,                   \`,;\`\`\`\`\`\`\`\`;     .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:\`                      .;\`\`\`\`\`\`;\`     \`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\`\`          .\`             \`:;\`\`\`;\`     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:          .:\`               \`.;\`;\`      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,\`          @.,                  \`.        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;,          ;@\`:                             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
	@echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,\`          @@,;                              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
