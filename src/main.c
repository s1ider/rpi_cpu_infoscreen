#include <stdio.h>
#include <unistd.h>
#include "bcm8544.h"


void main(int argc, char* argv[]) {
	int i;
	int x = 0;
	int y;
	bcm8544_init();

	clear_screen();
	for (i=1; i<argc; i++) {
		y = i - 1

		if argv[i] != '-u' {
			clear_screen();
		} else {

		}


		write_at(x, y, (argv[i]));

	}
}

int main(int argc, char *argv[]){
    int rez=0;
    int x = 0;
    int y = 0;


//	opterr=0;
	while ( (rez = getopt(argc,argv,"xy")) != -1){
		switch (rez){
		case 'x': printf("found argument \"x = %s\".\n",optarg); break;
		case 'y': printf("found argument \"y = %s\".\n",optarg); break;
		case '?': printf("Default\n");break;
        };
	};

};
