#include <SDL/SDL.h>

static SDL_Event event;
int get_events_poll() {
    return SDL_PollEvent(&event);
}
int window_should_close() {
    return (event.type == SDL_QUIT);
}
int get_pressed_key() {
    if(event.type == SDL_KEYDOWN) {
        return event.key.keysym.sym;
    }
    return 0;
}

void goto_next_frame() {
    SDL_GL_SwapBuffers();
}