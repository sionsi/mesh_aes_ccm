CC = gcc
TARGET = test
SRCS = aes.c \
	   common.c \
	   aes-ccm.c \
	   aes-enc.c \
	   test.c

OBJS=$(SRCS:.c=.o)

CFLAGS  ?= -Wall -g
LDFLAGS ?=


$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(OBJS)
