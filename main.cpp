/* The following code increments a seven segment display
 *
 * The following code is for a 5161ah seven segment display
 * The code assumes that you are wiring the gpio pins in incremental order
 * to the pins on the display. 
 *   ie gpio1 to seven segment pin A, 2 to B, and so on
 */


#include <stdio.h>
#include "pico/stdlib.h"


#define GPIO_FIRST_PIN 2
#define GPIO_BUTTON (GPIO_FIRST_PIN + 7	)

// table of hex values for display output
const int bits[10] = {
	0x3f,  // 0
	0x06,  // 1
	0x5b,  // 2
	0x4f,  // 3
	0x66,  // 4
	0x6d,  // 5
	0x7d,  // 6
	0x07,  // 7
	0x7f,  // 8
	0x67   // 9
};

int main()
{
	stdio_init_all(); // Do I even need this?

	for (int i = GPIO_FIRST_PIN; i < GPIO_FIRST_PIN + 7;++i) {
		gpio_init(i);
		gpio_set_dir(i, GPIO_OUT);
	}

	puts("We are ready to go!\n");

	// runs forever
	while (true) {
		// truth be told, this is a c++ range based for loop
		for (auto val : bits) {
			int32_t mask = val <<  GPIO_FIRST_PIN;
			gpio_set_mask(mask);
			sleep_ms(500);
			gpio_clr_mask(mask);
		}
	}

	return 0;
}
