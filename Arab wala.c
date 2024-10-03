
#include <stdio.h>
#include <stdlib.h>
int main(){
    char str[100]="no";
    //scanf("%s",str);
    int l = strlen(str),i,j,num=1;
    int arr[l];
    for(i = 0;i< l;i++)
        arr[i] =0;
        for(i = 0;i<l;i++)
        if(isdigit(str[i])){
            printf("Error");
            return;
        }
    for(i = 0;i<l;i++){
            if(arr[i] == 0){
                for(j = i ; j < l ; j++){
                    if(arr[j] == 0){
                        if(str[j] == str[i])
                            arr[j] = num;
                    }
                }
                num++;
            }
    }
for(i =0;i<l;i++)
    printf("%d",arr[i]);
return 0;
}
