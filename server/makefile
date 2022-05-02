CC := gcc
CFLAG := -Wall -lwiringPi -pthread

controller.o: controller.c
	$(CC) $^ -c

server.o: server.c
	$(CC) $^ -c

main: main.c server.o controller.o
	$(CC) $^ -o $@ $(CFLAG)

.PHONY: clean run

clean:
	rm server.o controller.o main

run:
	sudo ./main 54400
