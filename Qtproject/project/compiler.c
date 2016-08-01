
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
enum STATE {
    SS, FS, AS, AE, FN, SE,
    VR, TY, EQ
};

enum STATE cs;
char stack[BUFSIZE];
int top=0;
void push(char s);
char pop();

void parse_arg1(char *str, int (*atable)[255]);
void _printf(char *str);
void test(char *str);

typedef struct _var{
    char *name;
    char *type;
    char *value;
}var;

int main(){
    char *code[6];
    var a;
    code[0]="int a,b;";
    code[1]="a=10;";
    code[2]="b=20;";
    code[3]="printf(\"Hello, World!\\n\");";
    code[4]="printf(\"a is %d\\n\",a);";
    code[5]="printf(\"b is %d\\n\",b);";


    test(code[3]);
    return 0;
}

void push(char s){
    if(top>BUFSIZE)
        printf("overflow\n");
    else
        stack[top++]=s;
}

char pop(){
    char ret;
    if(top==0){
        return -1;
    }
    else{
        ret = stack[top-1];
        stack[top-1]=0;
        top--;
        return ret;
    }
}

void parse_arg1(char *str, int (*atable)[255]){
    int i=0, j=0, k=0;
    char *Var=str;
    while(*str != '\0'){
        switch(*str){
        case '\\':
            atable[2][k++]=*(++str);
            if(*str=='n')
                atable[0][i++]=10;
            break;
        case '%':
            atable[1][j++]=*(++str);
            if(*str=='d'){

            }
            break;
        default:
            atable[0][i++]=*str;
            break;
        }
        str++;
    }
    atable[0][i]='\0';
}

void _printf(char *str){
    int atable[3][255];
    int i = 0;
    parse_arg1(str, atable);
    while(atable[0][i] != '\0'){
        putchar((char)atable[0][i]);
        i++;
    }
}

void test(char *str){
    char *ptr=str;
    char arg[50];
    char funcname[20];
    char printf_name[]={'p','r','i','n','t','f'};
    int j=0;
    char tmp;
    while(*ptr!=';')
        ptr++;
    while(ptr!=str-1){
        switch((int)*ptr){
        case 59:    // ';'
            ptr--;
            cs=SS;
            break;
        case 41:    // ')'
            ptr--;
            cs=FS;
            break;
        case 40:    // '('
            ptr--;
            cs=FN;
            break;
        case 34:    // '\"'
            if(cs==FS || cs==VR){
                cs=AS;
            }
            else if(cs==AS){
                cs=AE;
                push('\0');
            }
            ptr--;
            break;
        case 44:    // ','
            if(cs==VR){
                push('\0');
            }
            else if(cs==AS)
                push(*ptr);
            ptr--;
            break;
        default:
            if(cs==SS){
                cs=VR;
                push(*ptr);
            }
            else if(cs==VR){
                push(*ptr);
            }
            else if(cs==FS){
                cs=VR;
                push(*ptr);
            }
            else if(cs==AS)
                push(*ptr);
            else if(cs==FN)
                push(*ptr);
            ptr--;
            break;
        }
    }
    if(cs==FN){
        while((tmp=pop())!='\0')
            funcname[j++]=tmp;
        funcname[j]='\0';
        j=0;
    }
    while((tmp=pop())!=-1)
        arg[j++]=tmp;
    arg[j]='\0';

    if(cs==FN){
        for(j=0;j<6;j++){
            if(funcname[j]!=printf_name[j])
                break;
        }
        if(j==6)
            _printf(arg);
    }
}

