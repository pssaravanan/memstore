clean:
	rm rand.o main.o test_redis

compile:
	gcc -c rand.c main.c server.c
	gcc -o test_redis rand.o main.o server.o