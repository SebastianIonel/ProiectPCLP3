CC=gcc
DEPS=main.c 


%.o: %.c
	$(CC) -c -o $@ $< -g

schedule: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ -g

clean:
	rm -f *.o tema3
