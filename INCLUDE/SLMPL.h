#ifndef SLMPL_H
#define SLMPL_H

/* Standards for coordinates */
#define DEFAULTSTANDARD 1 /* Default common */
#define LEGACYSTANDARD 2 /* Mathematical */

    /* Drawing functions */
    void singlecolor_draw_triangle(float x1, float y1, float x2, float y2, float x3, float y3, float R, float G, float B);
    void singlecolor_draw_line(float x1, float y1, float x2, float y2, float R, float G, float B);
    void singlecolor_draw_rect(float x, float y, float w, float h, float R, float G, float B);
    void clear_screen(float R, float G, float B, float A);
    /* Events related functions */
    int get_events_poll();
    int window_should_close();
    int get_pressed_key();
    void goto_next_frame();
    int check_collision_rect_rect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
    /* Initialization functions */
    void init_standarized_coordinates(int W, int H, int state);
    int init_video(int W, int H, int colormode, char *wintitle, char *iconpath);
    void clean_video();
#endif
