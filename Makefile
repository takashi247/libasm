NAME		:= libasm.a

TARGET	:= a.out

NASM		:= nasm

ASFLAGS	:= -f macho64

CC			:= gcc

CFLAGS	:= -Wall -Wextra -Werror

SRCSDIR	:= srcs/

OBJSDIR	:= objs/

TESTDIR	:= test/

AR			:= ar

ARFLAGS	:= -rc # r: replace c: create silently

SRCS		:= ft_strlen.s \
					ft_strcpy.s \
					ft_strcmp.s \
					ft_write.s \
					ft_read.s \
					ft_strdup.s

SRCS_TEST	:= main.c \
					test_strlen.c \
					test_strcpy.c \
					test_strcmp.c \
					test_write.c \
					test_read.c \
					test_strdup.c

OBJS		:= $(addprefix $(OBJSDIR), $(SRCS:.s=.o))

OBJS_TEST		:= $(addprefix $(OBJSDIR), $(SRCS_TEST:.c=.o))

VPATH		:= $(SRCSDIR):$(TESTDIR) # set the paths for make to search source files

INCLUDE	:= -I./include

RM			:= rm -rf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJSDIR)%.o: %.s
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	$(NASM) $(ASFLAGS) $^ -o $@

.PHONY: test
test: $(TARGET)

$(TARGET): $(OBJS_TEST) $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(OBJSDIR)%.o: %.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJSDIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(TARGET)

.PHONY: re
re: fclean all
