#include <stdio.h>
#include "bcm8544.h"


void main(int argc, char* argv[]) {
	int i;
	bcm8544_init();
	clear_screen();
	for (i=1; i<argc; i++) {
		clear_screen();
		write_at(x, y, (argv[i]));
	}
}