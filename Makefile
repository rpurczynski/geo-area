CC=gcc
RM=rm
CFLAGS=-g
LFLAGS=-lm
SRC_DIR=source
OBJS=$(SRC_DIR)/angle.o $(SRC_DIR)/area.o $(SRC_DIR)/edge_intersection.o $(SRC_DIR)/perimeter.o $(SRC_DIR)/main.o

all: polygon

polygon: $(OBJS)
	$(CC) $^ -o $@ $(LFLAGS)

angle.o: angle.c
	$(CC) $(LFLAGS) -c angle.c -o angle.o

area.o: area.c
	$(CC) $(LFLAGS) -c area.c -o area.o

edge_intersection.o: edge_intersection.c
	$(CC) $(LFLAGS) -c edge_intersection.c -o edge_intersection.o

perimeter.o: perimeter.c
	$(CC) $(LFLAGS) -c perimeter.c -o perimeter.o

main.o: main.c
	$(CC) $(LFLAGS) -c main.c -o main.o

clean:
	$(RM) $(SRC_DIR)/*.o
	$(RM) polygon

