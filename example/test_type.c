#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	char *s="double";
	char *data_type[] =
	{ "char", "int", "float", "double", "short", "long", "unsigned", "bool",
 	 "struct", "union", "enum", "void" };

	char **dest;
	dest = data_type;
	while(strcmp(s, (*dest)) != 0){
		printf("%s\n", *dest);
		dest++;
	}
	printf("%s\n", *dest);
	return 0;
}
