CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic
LIB =  -lboost_regex -lboost_date_time
L_OBJECTS = main.o

all: ps7

ps7: $(L_OBJECTS)
	$(CC) $(CFLAGS) -o ps7 $(L_OBJECTS) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm ps7 *.o