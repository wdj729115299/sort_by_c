CC = gcc
EXEC = sort
OBJS = sort.o
CFLAGS = -Wall
LDFLAGS = -lm
#default:$(EXEC)
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
#all:$(EXEC)
$(EXEC):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
clean:
	rm -f $(EXEC) $(OBJS)
