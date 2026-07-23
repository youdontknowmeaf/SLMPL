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

int check_collision_rect_rect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    if (x1 + w1 <= x2 || x1 >= x2 + w2 || y1 + h1 <= y2 || y1 >= y2 + h2) {
        return 0; }
    return 1;
}