clean:
	rm -f rand.o main.o server.o store.o thread.o request.o test_redis

compile: clean
	gcc -c rand.c main.c server.c store.c thread.c request.c
	gcc -o test_redis rand.o main.o server.o store.o thread.o request.o