#include <stdio.h>

#ifdef CAP
#define upper_printf print
#else
#define lower_printf print
#endif

int lower_printf(char *str){
	char *p;
        p = str;
        int count = 0;
        while(*p != '\0'){
                char tmp = *p;
                int gap = (int)('A' - 'a');
                if(tmp >= 'A' && tmp <= 'Z') tmp -= gap;
                putchar(tmp);
                p++;
                count++;
        }
        return count;
}

int upper_printf(char *str){
	char *p;
	p = str;
	int count = 0;
	while(*p != '\0'){
		char tmp = *p;
		int gap = (int)('A' - 'a');
		if(tmp >= 'a' && tmp <= 'z') tmp += gap;
		putchar(tmp);
		p++;
		count++;
	}
	return count;
}
int main(){
	char *message="Hello,World!";
	lower_printf(message);
	upper_printf(message);
	printf(message);
	print(message);
	return 0;
}
	
