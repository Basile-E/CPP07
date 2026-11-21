NAME = Iternet

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
HEADERS = iter.hpp Print.hpp

.PHONY: all clean fclean re

all : ${NAME}

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ) : $(HEADERS)

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all