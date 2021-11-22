#include<stdio.h>
#include<stdlib.h>
# define MIN(x,y) (x > y) ? y : x

int main(){
    int dropRate, size, dropped, total, present = 0; 
    int rainfall[10] = {0},i = 0, secs, ch;
    printf("Enter the size of the bucket : \n");
    scanf("%d",&size);
    printf("Enter the drop rate: \n");
    scanf("%d",&dropRate);
    do{
        printf("Enter the number of drops at second %d : \n", i+1);
        scanf("%d",&rainfall[i]);
        printf("Enter 1 to insert another element \n");
        scanf("%d",&ch);
        i += 1;
    }while(ch == 1);
    secs = i;
    printf("Second \t Recieved \t Sent \t Dropped \t Remained \n");
    for(i = 0;present || i < secs; i ++){
        printf("%d \t", i+1);
        printf("%d \t",rainfall[i]);
        printf("%d \t",MIN(present + rainfall[i],dropRate));
        total = present + rainfall[i] - dropRate;
        if (total > 0){
            if (total > size){
            present = size;
            dropped = total - size;
            }
            else{
                present = total;
                dropped = 0;
            }
        }
        else{
            present = 0;
            dropped = 0;
        }
        printf("%d \t %d \n",dropped,present);
    }
    return 0;
}