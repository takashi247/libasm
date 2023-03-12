NAME		:= libasm.a

NASM		:= nasm

ASFLAGS	:= -f macho64

AR			:= ar

ARFLAGS	:= -rc # r: replace c: create silently

SRCS		:= ft_strlen.s

OBJS		:= $(SRCS:.s=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.s.o:
	$(NASM) $(ASFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm a.out

.PHONY: re
re: fclean all