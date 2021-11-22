#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int size, i, j,fsize, frames[50];
    printf("Enter the window size : \n");
    scanf("%d",&size);
    printf("Enter the total frames : \n");
    scanf("%d",&fsize);
    printf("Enter the frames: \n");
    for(i = 1; i <= fsize; i++){
        scanf("%d",&frames[i]);
    }
    for(i = 1; i <= fsize; i++){
        if (i % size == 0){
            printf("%d \n",frames[i]);
        }
        else{
            printf("%d ",frames[i]);
        }
    }
    return 0;
}