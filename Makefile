clean:
	rm -f rand.o main.o server.o store.o test_redis

compile:
	gcc -c rand.c main.c server.c store.c
	gcc -o test_redis rand.o main.o server.o store.o -v