CC = gcc
CFLAGS = -Wall $(shell pkg-config --cflags sdl2 SDL2_image)
LIBS = $(shell pkg-config --libs sdl2 SDL2_image) -lm
TARGET = build/game
# Vezme všechny .c soubory ze složky src/
SRCS = $(wildcard src/*.c)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)