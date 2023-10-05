clean:
	rm -f rand.o main.o server.o store.o thread.o request.o test_redis

compile: clean
	gcc -c rand.c main.c server.c store.c thread.c request.c
	gcc -o memstore-server rand.o main.o server.o store.o thread.o request.o

debug: clean
	gcc -c -g rand.c main.c server.c store.c thread.c request.c
	gcc -o memstore-server-debug rand.o main.o server.o store.o thread.o request.o
