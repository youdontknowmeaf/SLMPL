#include <GL/gl.h>

void singlecolor_draw_triangle(float x1, float y1, float x2, float y2, float x3, float y3, float R, float G, float B) {
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void singlecolor_draw_line(float x1, float y1, float x2, float y2, float R, float G, float B) {
    glBegin(GL_LINES);
    glColor3f(R, G, B);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void singlecolor_draw_rect(float x, float y, float w, float h, float R, float G, float B) {
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);
    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x, y+h);

    glColor3f(R, G, B);
    glVertex2f(x, y+h);
    glVertex2f(x+w, y+h);
    glVertex2f(x+w, y);
    glEnd();
}

void clear_screen(float R, float G, float B, float A) {
    glClearColor(R, G, B, A);
    glClear(GL_COLOR_BUFFER_BIT);
}