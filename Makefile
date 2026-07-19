CC = gcc -std=c89 -pedantic
SRC = main.c
CFLAGS = -Wall -Wextra -O2
CINCLUDE = -I. -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
CLIBS = -L. -l SLMPL -lSDL -lGL

ARCMD = ar rcs

renderer = OpenGL_render.c
events = SDL_events.c
init = SDL_init.c

all:
	@echo "Compiling..."
	$(CC) $(CFLAGS) -c $(renderer) -o render.o
	$(CC) $(CFLAGS) -c $(events) -o events.o
	$(CC) $(CFLAGS) -c $(init) -o init.o
	@echo "Making a lib..."
	$(ARCMD) libSLMPL.a init.o render.o events.o
	@echo "Cleanup..."
	rm -r *.o

test:
	$(CC) $(CFLAGS) $(CINCLUDE) $(SRC) $(CLIBS)

clean:
	rm -r *.a