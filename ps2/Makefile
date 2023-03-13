CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wconversion	 
LDLIBS=-lm

TARGET=task
MODULES=k.c
TEST_TARGET=tests/runner
TEST_MODULES=tests/test_k_is_game_won.o tests/test_k_is_move_possible.o

all: $(TARGET) $(TEST_TARGET)

test: $(TEST_TARGET)
	$< -v

clean: 
	rm -f *.o tests/*.o $(TARGET) $(TEST_TARGET)

$(TARGET): k.o $(MODULES)
k.o: k.c k.h

$(TEST_TARGET): tests/runner.o $(TEST_MODULES) $(MODULES)
tests/test_k_is_game_won.o: tests/test_k_is_game_won.c
tests/test_k_is_move_possible.o: tests/test_k_is_move_possible.c

%.o: %.c
	$(CC) $(CFLAGS) $(LDLIBS) -c -o $@ $< 

%: %.o
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^ 


