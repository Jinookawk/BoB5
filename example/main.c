#include <stdio.h>
#include "option.h"

/* My code Start
int option_filter(char *arg){
	if(*(arg + 1) == 'j' || *(arg + 1) == 'J')
		return 1;
	else if(*(arg + 1) == '-') {
		int i = 2, j = 0;
		char jump[] = "jump";
		char tmp;
		while(*(arg + i) != '\0') {
			if((int)*(arg + i) < 97) tmp = (int)*(arg + i) + 32;
			else tmp = *(arg + i);
			if((char)tmp != jump[j++]) break;
			i++;
		}
		if(j == 4) return 1;
	}
	return -1;
}

My code End */

int main(int argc, char *argv[]) {
	enum options { NO_ARG, JUMP, HELP, VERBOSE, VERTICAL }; // Option Flag Set
	enum options flag = NO_ARG;
	char *help = "help";
	char *jump = "jump";
	char *verbose = "verbose";
	char *vertical = "vertical";

	if(argc < 2) { // Filtering Non-Argument
		printf("Usage : %s [argument]\n", argv[0]);
		return 0;
	}

	int a = 0; // Returning result of printf

	for(int i = 1; i < argc; i++) { // Repeat loop as argc
		char *tmp;
		if(argv[i][0] == '-') { // Filtering Options
			int res = 0;
			/* Start of original
			switch(argv[i][1]) {
			case 'j':
			case 'J':
				flag = JUMP;
				break;
			default:
				break;
			}
			End of original */
			// int option_filter(char *)
			//res = option_filter(argv[i]);
			//if(res == 1) flag = JUMP;
			if(*(argv[i] + 1) == '-') tmp = argv[i] + 2;
			else tmp = argv[i] + 1;
			if(rcheck(tmp, help)) flag = HELP;
			if(rcheck(tmp, jump)) flag = JUMP;
			if(rcheck(tmp, verbose)) flag = VERBOSE;
			if(rcheck(tmp, vertical)) flag = VERTICAL;
		}
		else {
			a += printf("%s", argv[i]);
			if(flag == JUMP) printf("\n");
			else printf(" ");
		}
	}

	if(flag != JUMP) printf("\n");

	if(a > 0) return 0;
	else return -1;
}
