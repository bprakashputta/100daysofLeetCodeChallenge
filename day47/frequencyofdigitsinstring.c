#include<stdio.h>

int main(){
    char str[1000];
    scanf("%s", &str);

    int freq[10];
    for(int i=0; i<=9; i++){
        freq[i]=0;
    }
    int len = 0;
    for(int i=0; str[i]!='\0'; i++){
        len++;
    }
    // iterate array and find frequency
    for(int i=0; i<len; i++){
        if(str[i]>='0'&&str[i]<='9'){
            freq[str[i]-'0']++;
        }
    }
    // print frequency of characters
    for(int i=0; i<=9; i++){
        printf("%d ",freq[i]);
    }
    printf("\n");
return 0;
}