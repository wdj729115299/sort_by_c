CFLAGS+= -DTEST -g
TARGET = merge_sort
SOURCES = ${wildcard *.c}
OBJS = $(SOURCES:.c=.o) 

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
.c.o:
	$(CC) $(CFLAGS) -Wall -c $<

clean:
	rm -f $(OBJS) $(TARGET)
