/* your solution to sw09 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "board.h"
#include "supervisor.h"

/* flashing light (led) with period 50ms ... 2s i.e. 0.5 Hz ... 20 Hz */

static void flasher_run(uint32_t period);
static uint32_t user_interface_run(void);

int main(void) {
	init();

	uint32_t period = 1000;  /*period [ms] */

	while (true) {
		period = user_interface_run();
		flasher_run(period);
		supervisor_run();
	}

	return(0);
}

/* turns led on and off according to period [ms] */
static void flasher_run(uint32_t period) {

	/* your code starts here */
	static bool led_on = false;
	static uint32_t old_time = 0;

	if (old_time+period/2 <= get_ms_since_start()) {
		old_time = get_ms_since_start();
		if(led_on){
			set_output(PTD0, low_level);
			led_on = false;
		}else{
			set_output(PTD0, high_level);
			led_on = true;
		}
	}
	/* your code ends here */
}

/* check buttons and determines required period of flashing */
static uint32_t user_interface_run(void) {

	/* your code starts here */
	static uint32_t period_set = 1000;
	static uint32_t old_time = 0;
	static uint32_t minus_pressed_since = 0;
	static uint32_t plus_pressed_since = 0;
	static uint32_t plus_difference = 0;
	static uint32_t minus_difference = 0;

	if (old_time+10 <= get_ms_since_start()) {
		old_time = get_ms_since_start();

		if (get_input(PTA2) == low_level) {
			if (period_set > 50){
				if (minus_pressed_since == 0){
					minus_pressed_since = get_ms_since_start()/100;
				}

				minus_difference = get_ms_since_start()/100 - minus_pressed_since;
				if ((period_set - minus_difference) > 50) {
					period_set = period_set - minus_difference;
				} else {
					period_set = 50;
				}
			}
		} else {
			if (minus_pressed_since != 0){
				minus_pressed_since = 0;
			}
		}
		if (get_input(PTA1) == low_level) {
			if (period_set < 2000){
				if (plus_pressed_since == 0){
					plus_pressed_since = get_ms_since_start()/100;
				}

				plus_difference = get_ms_since_start()/100 - plus_pressed_since;
				if ((period_set + plus_difference) < 2000) {
					period_set = period_set + plus_difference;
				} else {
					period_set = 2000;
				}
			}
		} else {
			if (plus_pressed_since != 0){
				plus_pressed_since = 0;
			}
		}
	}
	if (period_set >= 2000){
		set_output(PTD2, high_level);
		set_output(PTD1, low_level);
	}else if (period_set <= 50){
		set_output(PTD1, high_level);
		set_output(PTD2, low_level);
	}else{
		set_output(PTD1, low_level);
		set_output(PTD2, low_level);
	}
	return period_set; /* [ms] */
	/* your code ends here */
}