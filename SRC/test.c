#include <stdio.h>
#include "KEYS.h"
#include "SLMPL.h"

int main(int argc, char *argv[]) {
	int runs = 1;
	int TEST = 0;
	int TESTX = 0;
	int TESTY = 0;

	init_video(640, 480, 32, "Test window", NULL);
	init_standarized_coordinates(640, 480, DEFAULTSTANDARD);
	
	while(runs) {
		while(get_events_poll()) {
			if(window_should_close()) runs = 0;
			if(get_pressed_key() == KEY_SPACE) TEST += 2;
			if(get_pressed_key() == KEY_LEFT) TESTX -= 2;
			if(get_pressed_key() == KEY_RIGHT) TESTX += 2;
			if(get_pressed_key() == KEY_UP) TESTY -= 2;
			if(get_pressed_key() == KEY_DOWN) TESTY += 2;
		}
		
		clear_screen(0.0f, 0.0f, 0.0f, 0.0f);

		singlecolor_draw_triangle(100, 10, 300, 50, 150, 70, 1.0f, 1.0f, 0.0f);
		singlecolor_draw_rect(20, 20, 50, TEST, 1.0f, 0.0f, 0.0f);
		singlecolor_draw_rect(TESTX, TESTY, 50, 50, 1.0f, 0.0f, 0.0f);
		singlecolor_draw_line(1, 1, 639, 479, 1.0f, 0.0f, 0.0f);

		goto_next_frame();

		if (check_collision_rect_rect(20, 20, 50, TEST, TESTX, TESTY, 50, 50) == 1) {printf("\r1");} else {
			printf("\r0");
		}
		fflush(stdout);
	}

	clean_video();
	return 0;
}