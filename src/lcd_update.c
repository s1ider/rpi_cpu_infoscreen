#include <stdio.h>
#include <unistd.h>
#include "bcm8544.h"


// void main(int argc, char* argv[]) {
// 	int i;
// 	bcm8544_init();
// 	clear_screen();
// 	for (i=1; i<argc; i++) {
// 		write_at(x, y, (argv[i]));
// 	}
// }

int main(int argc, char *argv[]){
    int rez=0;
    int x = 0;
    int y = 0;
    char *msg;


//	opterr=0;
	while ( (rez = getopt(argc,argv,"xyc")) != -1){
		switch (rez){
		case 'x':
			printf("found argument \"x = %s\".\n",optarg);
			x=optarg;
			break;
		case 'y':
			printf("found argument \"y = %s\".\n",optarg);
			y=optarg;
			break;
		case 'c':
			printf("found argument \"c = %s\".\n",optarg);
			clear_screen();
		case '?':
			printf("Default\n");
			msg = optopt;
			break;
        };
        write_at(x, y, msg)
	};
};
