CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/Book.c src/Library.c src/BorrowManager.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = library

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

test:
	$(CC) $(CFLAGS) -o test_runner tests/test_book.c tests/test_library.c tests/test_borrow.c tests/test_integration.c $(SRC)
	./test_runner

clean:
	rm -f $(OBJ) $(TARGET) test_runner

.PHONY: all test clean