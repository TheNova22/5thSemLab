#include<stdio.h>
#include<string.h>
#define N strlen(poly)

char input[20], crcs[20], poly[] = "1011";
int ipLength, i , j, k;

void xor(){
    for(k = 1; k < N; k++){
        crcs[k] = (crcs[k] == poly[k]) ? '0' : '1';
    }
}

void crc(){
    for(i = 0; i < N; i++){
        crcs[i] = input[i];
    }
    do{
        if (crcs[0] == '1'){
            xor();
        }
        for(j = 0; j < N - 1; j++){
            crcs[j] = crcs[j+1];
        }
        crcs[j] = input[i];
        i += 1;
    }while(i < ipLength + N);
}



void main(){
    printf("Enter the input data: \n");
    scanf("%s",input);
    printf("The polynomial is: %s \n", poly);
    ipLength = strlen(input);
    for(i = ipLength; i < ipLength + N - 1;i++){
        input[i] = '0';
    }
    printf("Padded input is : %s \n",input);

    crc();
    printf("CRC is : %s \n",crcs);
    for(i = ipLength; i < ipLength + N - 1; i++){
        input[i] = crcs[i - ipLength];
    }
    printf("Output message(0 errors) shall  be : %s \n",input);
    printf("Do you want to send a erroneous message? 1 if yes \n");
    scanf("%d",&i);
    if (i == 1){
        printf("Enter message with same length as the output message\n");
        scanf("%s",input);
    }
    crc();
    i = 0;
    while((i < N - 1) && crcs[i] != '1'){
        i += 1;
    }
    if (i < N - 1){
        printf("You my friend have sent a wrong message\n");
    }
    else{
        printf("No errors, LESGO \n");
    }
}

// #include<stdio.h>
// #include<string.h>
// #define N strlen(g)

// char t[28],cs[28],g[]="1011";
// int a,e,c;

// void xorfunction(){
//     for(c = 1;c < N; c++)
//     cs[c] = (( cs[c] == g[c])?'0':'1');
// }

// void crc(){
//     for(e=0;e<N;e++)
//         cs[e]=t[e];
//     do{
//         if(cs[0]=='1')
//             xorfunction();
//         for(c=0;c<N-1;c++)
//             cs[c]=cs[c+1];
//         cs[c]=t[e++];
//     }while(e<=a+N-1);
// }

// int main()
// {
//     printf("\nEnter data : ");
//     scanf("%s",t);
//     printf("\n----------------------------------------");
//     printf("\nGenerating polynomial : %s",g);
//     a=strlen(t);
//     for(e=a;e<a+N-1;e++)
//         t[e]='0';
//     printf("\n----------------------------------------");
//     printf("\nPaded data is : %s",t);
//     printf("\n----------------------------------------");
//     crc();
//     printf("\nCRC is : %s",cs);
//     for(e=a;e<a+N-1;e++)
//         t[e]=cs[e-a];
//     printf("\n----------------------------------------");
//     printf("\nFinal data to be sent : %s",t);
//     printf("\n----------------------------------------");
//     printf("\nTest error detection 0(yes) 1(no)? : ");
//     scanf("%d",&e);
//     if(e==0)
//     {
//         do{
//             printf("\nEnter the position where error is to be inserted : ");
//             scanf("%d",&e);
//         }while(e==0 || e>a+N-1);
//         t[e-1]=(t[e-1]=='0')?'1':'0';
//         printf("\n----------------------------------------");
//         printf("\nErroneous data : %s\n",t);
//     }
//     crc();
//     for(e=0;(e<N-1) && (cs[e]!='1');e++);
//         if(e<N-1)
//             printf("\nError detected\n\n");
//         else
//             printf("\nNo error detected\n\n");
//             printf("\n----------------------------------------\n");
//         return 0;
// }