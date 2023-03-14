NAME		:= libasm.a

TARGET	:= a.out

NASM		:= nasm

ASFLAGS	:= -f macho64

CC			:= gcc

CFLAGS	:= -Wall -Wextra -Werror

SRCSDIR	:= srcs/

SRCS_BONUSDIR	:= srcs_bonus/

OBJSDIR	:= objs/

OBJS_BONUSDIR	:= objs_bonus/

TESTDIR	:= test/

TEST_BONUSDIR	:= test_bonus/

AR			:= ar

ARFLAGS	:= -rc # r: replace c: create silently

SRCS		:= ft_strlen.s \
					ft_strcpy.s \
					ft_strcmp.s \
					ft_write.s \
					ft_read.s \
					ft_strdup.s

SRCS_BONUS	:= ft_atoi_base.s

SRCS_TEST	:= main.c \
						test_strlen.c \
						test_strcpy.c \
						test_strcmp.c \
						test_write.c \
						test_read.c \
						test_strdup.c \

SRCS_TEST_BONUS	:= main_bonus.c \
									test_atoi_base_bonus.c

OBJS		:= $(addprefix $(OBJSDIR), $(SRCS:.s=.o))

OBJS_BONUS		:= $(addprefix $(OBJS_BONUSDIR), $(SRCS_BONUS:.s=.o))

OBJS_TEST		:= $(addprefix $(OBJSDIR), $(SRCS_TEST:.c=.o))

OBJS_TEST_BONUS		:= $(addprefix $(OBJS_BONUSDIR), $(SRCS_TEST_BONUS:.c=.o))

VPATH		:= $(SRCSDIR):$(SRCS_BONUSDIR):$(TESTDIR):$(TEST_BONUSDIR) # set the paths for make to search source files

INCLUDE	:= -I./include

INCLUDE_BONUS	:= -I./include_bonus

RM			:= rm -rf

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJSDIR)%.o: %.s
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	$(NASM) $(ASFLAGS) $^ -o $@

.PHONY: bonus
bonus: $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

$(OBJS_BONUSDIR)%.o: %.s
	@if [ ! -d $(OBJS_BONUSDIR) ]; then mkdir $(OBJS_BONUSDIR); fi
	$(NASM) $(ASFLAGS) $^ -o $@

.PHONY: test
test: $(TARGET)

$(TARGET): $(OBJS_TEST) $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(OBJSDIR)%.o: %.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: test_bonus
test_bonus: $(OBJS_TEST_BONUS) $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE_BONUS) $^ -o $(TARGET)

$(OBJS_BONUSDIR)%.o: %.c
	@if [ ! -d $(OBJS_BONUSDIR) ]; then mkdir $(OBJS_BONUSDIR); fi
	$(CC) $(CFLAGS) $(INCLUDE_BONUS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJSDIR)
	$(RM) $(OBJS_BONUSDIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(TARGET)

.PHONY: re
re: fclean all
