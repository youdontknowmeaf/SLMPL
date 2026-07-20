#include <stddef.h>
#include "KEYS.h"
#include "SLMPL.h"

int main(int argc, char *argv[]) {
	int runs = 1;
	float TEST = 0;

	init_video(640, 480, 32, "Test window", NULL);
	init_standarized_coordinates(640, 480, DEFAULTSTANDARD);
	
	while(runs) {
		while(get_events_poll()) {
			if(window_should_close()) runs = 0;
			if(get_pressed_key() == KEY_SPACE) TEST += 2.0f;
		}
		
		clear_screen(0.0f, 0.0f, 0.0f, 0.0f);

		singlecolor_draw_triangle(100, 10, 300, 50, 150, 70, 1.0f, 1.0f, 0.0f);
		singlecolor_draw_rect(20, 20, TEST, 50, 1.0f, 0.0f, 0.0f);
		singlecolor_draw_line(1, 1, 639, 479, 1.0f, 0.0f, 0.0f);

		goto_next_frame();
	}

	clean_video();
	return 0;
}



/*
 I had to remove these comments cuz this is ansii c and I used C++ style comments.
 */