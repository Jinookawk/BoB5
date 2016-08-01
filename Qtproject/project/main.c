/*
#include <stdio.h>
void parse_arg1(char *str, int (*atable)[255]){
    int i = 0, j = 0, k = 0;
    while(*str != '\0'){
        switch(*str){
        case '\\':
            atable[2][k++] = *(++str);
            break;
        case '%':
            atable[1][j++] = *(++str);
            break;
        default:
            atable[0][i++] = *str;
            break;
        }
        str++;
    }
    atable[0][i] = '\0';
}

int main(){
    char *str = "Hello, World!\n";
    int atable[3][255];
    int i = 0;
    parse_arg1(str, atable);
    while(atable[0][i] != '\0'){
        putchar((char)atable[0][i]);
        i++;
    }
    return 0;
}
*/
