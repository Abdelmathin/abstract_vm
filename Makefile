#  **************************************************************************   #
#                                                                               #
#                                                          :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:     #
#                                                     +:+ +:+         +:+       #
#    By: ahabachi <abdelmathinhabachi@gmail.com>    +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+             #
#    Created: 2024/08/19 17:40:12 by ahabachi          #+#    #+#               #
#    Updated: 2024/09/24 06:34:37 by ahabachi         ###   ########.fr         #
#                                                                               #
#  **************************************************************************   #
#                                                                               #
#                                                                               #
#                                                                               #
#             _    _         _                  _    __     ____  __            #
#            / \  | |__  ___| |_ _ __ __ _  ___| |_  \ \   / /  \/  |           #
#           / _ \ | '_ \/ __| __| '__/ _` |/ __| __|  \ \ / /| |\/| |           #
#          / ___ \| |_) \__ \ |_| | | (_| | (__| |_    \ V / | |  | |           #
#         /_/   \_\_.__/|___/\__|_|  \__,_|\___|\__|    \_/  |_|  |_|           #
#                                                                               #
#                                                                               #
#                                                                               #
#                                                                               #
#                                                                               #
#  **************************************************************************   #
#                                                                               #
#   █████████            ██████████         ██████████         ██████████       #
#   ██     ██                    ██                 ██         ██      ██       #
#          ██                    ██                 ██         ██      ██       #
#          ██                    ██                 ██                 ██       #
#          ██            ██████████         ██████████                 ██       #
#          ██                    ██                 ██                 ██       #
#          ██                    ██                 ██                 ██       #
#          ██                    ██                 ██                 ██       #
#       ████████         ██████████         ██████████                 ██       #
#                                                                               #
#  **************************************************************************   #

.PHONY: clean fclean re push p tests docker-container

CPP=c++
NAME=avm
CPPFLAGS=-Wall -Wextra -Wshadow -Werror
CREATE_DIRECTORY=mkdir -p
REMOVE_FILE=rm -rf
HEADERS_DIR=include
SOURCES_DIR=sources
OBJECTS_DIR=objects

ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Int8.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Float.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Int16.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Stack.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Token.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Int32.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Lexer.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Double.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Client.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Parser.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Server.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/OStream.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Complex.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/IOperand.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/abstract_vm.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/Instruction.hpp
ABSTRACT_VM_HEADERS := $(ABSTRACT_VM_HEADERS) $(HEADERS_DIR)/VirtualMachine.hpp

ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/main.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Int8.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Float.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Int32.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Lexer.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Int16.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Stack.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Token.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Double.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Client.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Server.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Parser.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/OStream.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Complex.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/abstract_vm.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/Instruction.cpp
ABSTRACT_VM_SOURCES := $(ABSTRACT_VM_SOURCES) $(SOURCES_DIR)/VirtualMachine.cpp

ABSTRACT_VM_OBJECTS := $(patsubst $(SOURCES_DIR)/%.cpp, $(OBJECTS_DIR)/%.o, $(ABSTRACT_VM_SOURCES))

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp $(ABSTRACT_VM_HEADERS)
	$(CREATE_DIRECTORY) "$(dir $@)"
	$(CPP) $(CPPFLAGS) -c $< -o $@


$(NAME): $(ABSTRACT_VM_OBJECTS) $(ABSTRACT_VM_HEADERS)
	$(CPP) -o $(NAME) $(ABSTRACT_VM_OBJECTS)

all: $(NAME)

clean:
	$(REMOVE_FILE) $(OBJECTS_DIR)

fclean: clean
	$(REMOVE_FILE) $(NAME)

tests: all
	clear
	./$(NAME) tests/*.$(NAME)

push:
	git add . && git commit -m "update" && git push

p: push

docker-container:
	${sudo} docker run -it -v ${PWD}:/home/abstract_vm gcc:latest bash -c "cd '/home/abstract_vm' && exec bash"

re: fclean all
