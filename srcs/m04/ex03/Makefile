NAME = amateria
CC = c++ -Wall -Wextra -Werror #-fsanitize=address -g
CPPFLAGS = -std=c++98

SRC_DIR = srcs
OBJ_DIR = objs

SRC = main.cpp \
      AMateria.cpp \
      Ice.cpp \
      Cure.cpp \
      MateriaSource.cpp \
      Character.cpp \
      Colors.cpp

OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
