#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "bcm8544.h"

#define USAGE "Usage: lcd_update TEXT [-xX] [-yY] [-u]\n"


int main(int argc, char *argv[]){
    int rez=0;
    int x = 0;
    int y = 0;
    bool update = false;
    char *msg;

    bcm8544_init();

	while ( (rez = getopt(argc,argv,"x:y:u")) != -1){
		switch (rez){
		case 'x':
			x=atoi(optarg);
			update = true;
			break;
		case 'y':
			y=atoi(optarg);
			update = true;
			break;
		case 'u':
			update = true;
			break;
		case '?':
			printf(USAGE);
			break;
        };
	};

	if (!update) {
		clear_screen();
		for (i=1;i<argc;i++) {
			write_at(0, i -1, argv[i]);
		}
	}

	msg = argv[optind];
 	if (msg == NULL) {
 		printf("your TEXT is empty\n");
		printf(USAGE);
		return 1;
	}
    // printf("message: %s at %i, %i\n", msg, x, y);
    write_at(x, y, msg);

    return 0;
};
