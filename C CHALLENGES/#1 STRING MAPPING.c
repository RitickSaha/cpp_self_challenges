#include<stdio.h>
#include<string.h>
char str[10]="no",strmap[10],arr[10][2];
int i,j=0,c,inserter=1;
int check(char str){
for(c=0;c<inserter;c++)
if(str==arr[c][0]){
    strmap[i]=arr[c][1];
    return 1;
}
return 0;
}
int main(){
    //scanf("%s",&str);
    for(i=0;i<strlen(str);i++){
        if(isdigit(str[i]))
            {printf("Error");return;}
        for(;j<=i+1;j++)
        {
          if(check(str[i])==1)
               break;
          else{;
            arr[j][0]=str[i];
            arr[j][1]=inserter+48;
            inserter++;
            }
        }
        }printf("%s=%s\n\n%c",str,strmap);
    }

