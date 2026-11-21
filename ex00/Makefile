NAME = Template

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
HEADERS = templates.hpp

.PHONY: all clean fclean re

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $@

all : ${NAME}

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ) : $(HEADERS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all