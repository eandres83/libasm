NAME = libasm.a
NASM = nasm
AR = ar rcs
RM = rm -f

NASM_FLAGS = -f elf64 -g -F dwarf

SRCS = src/ft_strlen.s \
	src/ft_strcpy.s \
	src/ft_strcmp.s \
	src/ft_read.s \
	src/ft_write.s \
	src/ft_strdup.s \

OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Done"

%.o: %.s
	$(NASM) $(NASM_FLAGS) $< -o $@

clean:
	@echo "Limpiando archivos objeto ..."
	$(RM) $(OBJS)

fclean:
	@echo "Limpriando libreria ..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
