#include <stdio.h>
#include "KEYS.h"
#include "SLMPL.h"

int check_collision_rect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if (x1 + w1 <= x2 || x1 >= x2 + w2 || y1 + h1 <= y2 || y1 >= y2 + h2) {
		return 0; }
	return 1;
}


int main(int argc, char *argv[]) {
	int runs = 1;
	float TEST = 0;
	int TESTX = 0;
	int TESTY = 0;

	init_video(640, 480, 32, "Test window", NULL);
	init_standarized_coordinates(640, 480, DEFAULTSTANDARD);
	
	while(runs) {
		while(get_events_poll()) {
			if(window_should_close()) runs = 0;
			if(get_pressed_key() == KEY_SPACE) TEST += 2.0f;
			if(get_pressed_key() == KEY_LEFT) TESTX -= 2.0f;
			if(get_pressed_key() == KEY_RIGHT) TESTX += 2.0f;
			if(get_pressed_key() == KEY_UP) TESTY -= 2.0f;
			if(get_pressed_key() == KEY_DOWN) TESTY += 2.0f;
		}
		
		clear_screen(0.0f, 0.0f, 0.0f, 0.0f);

		singlecolor_draw_triangle(100, 10, 300, 50, 150, 70, 1.0f, 1.0f, 0.0f);
		singlecolor_draw_rect(20, 20, 50, TEST, 1.0f, 0.0f, 0.0f);
		singlecolor_draw_rect(TESTX, TESTY, 50, 50, 1.0f, 0.0f, 0.0f);
		singlecolor_draw_line(1, 1, 639, 479, 1.0f, 0.0f, 0.0f);

		goto_next_frame();

		if (check_collision_rect(20, 20, TEST, 50, TESTX, TESTY, 50, 50) == 1) {printf("Collision detected.\n");}
		/*else {printf("\rCollision not detected.");}*/
		printf("R1: %d,%d,%d,%d | R2: %d,%d,%d,%d\n", 20, 20, (int)TEST, 50, TESTX, TESTY, 50, 50);
	}

	clean_video();
	return 0;
}



/*
 I had to remove these comments cuz this is ansii c and I used C++ style comments.
 */