#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checksum(int mode){
    char input[25];
    int i, sum = 0, temp, n;
    scanf("%s",input);
    if (strlen(input) % 2 == 0){
        n = strlen(input) / 2;
    }
    else{
        n = (strlen(input) + 1)/ 2;
    }

    for(i = 0; i < n; i++){
        temp = input[i*2];
        temp = (temp * 256) + input[(i*2) + 1];
        sum += temp;
    }
    if (mode == 1){
        printf("Enter the checksum value: \n");
        scanf("%x",&temp);
        sum += temp;
    }
    if (sum % 65536 != 0){
        n = sum % 65536;
        sum = (sum / 65536) + n;
    }
    sum = 65535 - n;
    printf("%x \n",sum);
    return sum;
}


void main(){
    int ch,sum;
    do{
        printf("1.Encode 2.Decode Else.Exit \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the string\n");
            sum = checksum(0);
            break;
        case 2:
            printf("Enter the string\n");
            sum = checksum(1);
            break;
        default:
            break;
        }
    }while(ch == 1 || ch == 2);
}