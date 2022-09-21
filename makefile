CFLAGS := -std=c99 -pedantic -Wall -Wextra

pq: main.o fraction.o fraction_list.o polynomial.o solution.o int_list.o
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o pq .depend
.PHONY: clean

.depend: main.c fraction.c fraction_list.c polynomial.c solution.c int_list.c
	$(CC) -MM $^ > .depend
include .depend
