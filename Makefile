CC=gcc
DEPS=main.c

OBJ:=add.o
OBJ+=clear.o
OBJ+=show.o
OBJ+=count.o
OBJ+=close.o
OBJ+=common_m.o
OBJ+=common_d.o
OBJ+=move.o
OBJ+=del.o
OBJ+=month.o
OBJ+=move_only.o
OBJ+=full_clear.o

%.o: %.c
	$(CC) -c -o $@ $< -g

schedule: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ -g

clean:
	rm -f *.o schedule
