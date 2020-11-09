#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    char *c=(char*)calloc(1,sizeof(char));
    int x=open("students.csv",O_RDONLY);
    printf("%d\n",x);
    int z=read(x,c,1);
    while(z==1){
        //printf("%d\n",z);
        printf("%s",c);
        z=read(x,c,1);
    }
    close(x);
    return 0;
}