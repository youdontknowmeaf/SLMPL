CC = tcc -std=c89
SRC = SRC/main.c
CFLAGS = -Wall -Wextra
CINCLUDE = -I./INCLUDE -I/usr/include -D_GNU_SOURCE=1 -D_REENTRANT
CLIBS = -L./LIB -L/usr/lib/x86_64-linux-gnu -lSLMPL -lSDL -lGL

ARCMD = ar rcs

renderer = SRC/OpenGL_render.c
events = SRC/SDL_events.c
init = SRC/SDL_init.c

all:
	@echo "Compiling..."
	$(CC) $(CFLAGS) $(CINCLUDE) -c $(renderer) -o render.o
	$(CC) $(CFLAGS) $(CINCLUDE) -c $(events) -o events.o
	$(CC) $(CFLAGS) $(CINCLUDE) -c $(init) -o init.o
	@echo "Making a lib..."
	$(ARCMD) LIB/libSLMPL.a init.o render.o events.o
	@echo "Cleanup..."
	rm -r *.o

test:
	$(CC) $(CFLAGS) $(CINCLUDE) $(SRC) $(CLIBS)

clean:
	rm -r *.a
