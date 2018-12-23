vpath %.c src
vpath %.h include
CC=gcc
CFLAGS=-Wall
OBJS=main.o readfile.o getprops.o create.o lnsoft.o copyfile.o delete.o
custom_demo:$(OBJS)
	@$(CC) $(CFLAGS) -o custom_demo $^
%.o:%.c %.h 
	@$(CC) $(CFLAGS) -c -I include $<
.PHONY:clean
clean:
	rm -f *.o 
