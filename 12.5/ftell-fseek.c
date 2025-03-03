#include<stdio.h>

int main(){
    FILE *fp;
    long n;
    char c;
    fp = fopen("test.txt","w");

    while((c=getchar()) != EOF){
        putc(c,fp);
    }

    printf("No of character entered = %ld\n", ftell(fp));
    fclose(fp);
    fp = fopen("test.txt","r"); 
    n=0L;

    while(feof(fp) == 0){
        fseek(fp, n, 0);
        printf("Position of %c is %ld\n",getc(fp),ftell(fp));
        n = n+5L;
    }
    putchar('\n');

    fseek(fp,-1L,2);
    do{
        putchar(getc(fp));
    }
    while(!fseek(fp,-2L,1));

    fclose(fp);

    return 0;
}