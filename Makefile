CC=g++
CFLAGS=-g
ALLOBJ=main.o hash.o lru_cache.o
DEPS=node.h hash.h lru_cache.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(ALLOBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean

clean:
	rm -f main
	rm -f $(ALLOBJ)
