CC := gcc
CFLAG := -Wall -lwiringPi

controller: controller.c
	$(CC) $^ -c

server: server.c
	$(CC) $^ -c

main: main.c server.o controller.o
	$(CC) $^ -o $@ $(CFLAG)

.PHONY: clean run

clean:
	rm server.o controller.o main

run:
	sudo ./main 54400
