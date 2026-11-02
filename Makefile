CC = gcc
CFLAGS = -Wall -g -fsanitize=address $(shell pkg-config --cflags sdl2 SDL2_image)
LIBS = $(shell pkg-config --libs sdl2 SDL2_image) -lm -fsanitize=address
TARGET = build/game

SRCS = $(wildcard src/*.c)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)