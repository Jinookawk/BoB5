#include <stdio.h>
#include <stdbool.h>

bool rcheck(char *str1, char *str2) {
	if(*str1 == *str2 ) {
		if(*str1 == '\0') return true;
		else rcheck(str1+1, str2+1);
	}
	else return false;
}

/*
int main() {
	char *org = "help";
	char *dst = "help";
	char *dif = "hell";

	if(rcheck(org, dst)) printf("TRUE\n");
	if(!rcheck(org, dif)) printf("FALSE\n");

	return 0;
}
*/

