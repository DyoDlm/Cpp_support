NAME = ClapTrap
CC = c++ -Wall -Wextra -Werror
CPPFLAGS = -std=c++98

SRC = main.cpp ClapTrap.cpp Colors.cpp
OBJ_DIR = objs
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(NAME)

fclean: clean
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
