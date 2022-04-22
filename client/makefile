CC := gcc

controller: remote_controller.c
	$(CC) $^ -o $@

.PHNOY: clean

clean:
	rm controller

run:
	./controller
	