/*
#include <stdio.h>
#include <string.h>
int main(){
    int num,i,j,k,n;
    char *s[3]={"   *  ","  *** "," *****"};
    char buf[60][160];
    scanf("%d",&num);
    /*
    for(i=0;i<num;i++){
        for(j=0;j<3;j++){
            for(k=3*num-a;k>0;k--){
                printf(" ");
            }
            a++;
            for(l=0;l<i+1;l++){
                for(m=0;m<2*j+1;m++){
                    printf("*");
                }
                for(n=0;n<5-2*j;n++){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    *//*
    n=num;
    for(i=0;i<3*num;i++){
        if(i!=0&&i%3==0)
            n--;
        for(k=0;k<num-n;k++){
            strcpy(&buf[i][3*k],"   ");
        }
        switch(i%3){
        case 0:
            for(j=0;j<n;j++){
                strcpy(&buf[i][6*j+3*k],s[2]);
            }
            break;
        case 1:
            for(j=0;j<n;j++){
                strcpy(&buf[i][6*j+3*k],s[1]);
            }
            break;
        case 2:
            for(j=0;j<n;j++){
                strcpy(&buf[i][6*j+3*k],s[0]);
            }
            break;
        }
    }

    for(i=3*num-1;i>=0;i--){
        printf("%s\n",buf[i]);
    }
    return 0;
}
*/
