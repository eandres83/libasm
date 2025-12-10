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

SRCS_BONUS = src_bonus/ft_list_size.s \
		src_bonus/ft_list_push_front.s \
		src_bonus/ft_list_sort.s \

OBJS_BONUS = $(SRCS_BONUS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Done"

%.o: %.s
	$(NASM) $(NASM_FLAGS) $< -o $@

clean:
	@echo "Limpiando archivos objeto ..."
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:
	@echo "Limpriando libreria ..."
	$(RM) $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	@echo "Done bonus"
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all clean fclean bonus re
