#include<stdio.h>
int sum(int a[],int num1);
int arr[10]={1,2,3,4,5,6,7,8,9,10};
int main(){
    int ans=0;
    ans=sum(arr,sizeof(arr)/sizeof(int));
    printf("%d",ans);
    return 0;
}
int sum(int a[],int num1){
    int total=0;
    for(int i=0;i<num1;i++){
        total+=a[i];
    }
    return total;
}