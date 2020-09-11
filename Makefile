CC=g++
CFLAGS=-g
ALLOBJ=main.o hash.o lru_cache.o
DEPS=node.h hash.h lru_cache.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lru_cache_tests: $(ALLOBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean

clean:
	rm -f lru_cache_tests
	rm -f $(ALLOBJ)
