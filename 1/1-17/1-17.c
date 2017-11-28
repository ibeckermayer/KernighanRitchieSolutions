#include <stdio.h>
#define MAXLENGTH 1000
#define LIMIT 80
int getline2(char [],int);
void copy(char [],char []);
int main()
{
    int len = 0;
    char line[MAXLENGTH],over80[MAXLENGTH];
    while((len=getline2(line,MAXLENGTH))>0)
        if(len>LIMIT){
            copy(over80,line);
	    printf("%s", over80);
        }
    printf("\n");
    return 0;
}

int getline2(char line[],int limit)
{
    int i,c;
    for(i=0;i<limit-1&&(((c=getchar())!=EOF)&&(c!='\n'));i++)
        line[i]=c;
    if(i==(limit-1)){
        while((c=getchar())!='\n'){
            ++i;
        }
    }
    if(c=='\n'){        
        line[i]=c;
        ++i;
    }
    line[i]='\0';       
    return i;
}

void copy(char to[],char from[])
{
    int i=0;
    while((to[i]=from[i])!='\0')
        ++i;
}
