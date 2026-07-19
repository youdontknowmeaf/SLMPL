#include <SDL/SDL.h>
#include <GL/gl.h>

#define DEFAULTSTANDARD 1
#define LEGACYSTANDARD 2

void init_standarized_coordinates(int W, int H, int state) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    switch(state) {
        case 2:
            glOrtho(0.0, (double)W, 0.0, (double)H, -1.0, 1.0);
            break;
        case 1:
            glOrtho(0.0, (double)W, (double)H, 0.0, -1.0, 1.0);
            break;
        default:
            puts("Invalid standard, defaulting to OpenGL default");
            break;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int init_video(int W, int H, int colormode, char *wintitle, char *iconpath) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        fprintf(stderr, "\nSDL FAILED TO INITIALIZE VIDEO ERR CODE %s\n", SDL_GetError());
        return -1;
    }
    SDL_SetVideoMode(W, H, colormode, SDL_OPENGL);
    SDL_WM_SetCaption(wintitle, iconpath);

    return 0;
}

void clean_video() {
    SDL_Quit();
}
