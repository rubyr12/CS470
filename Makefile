
CC=gcc

CFLAGS=-Wall -g

TARGET=ProcessManagement

all: $(TARGET)

$(TARGET): $(TARGET).c
		$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c