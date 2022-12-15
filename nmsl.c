#include <stdio.h>
int temp(int a[],int num1);
int arr[10]={2,3,5,7,11,13,17,23,29,31};
int main(){
    int ans=0;
    ans=temp(arr,sizeof(arr)/sizeof(int));
    if(ans==0){
    	printf("%s","False");
	}
	else if(ans==1){
		printf("%s","True");
	}
    return 0;
}
int temp(int a[],int num1){
    int prime=0;
    for(int i=0;i<num1;i++){
        for(int j=1;j<=a[i];j++){
        	if((a[i]%j)==0){
        		prime+=1;
			}
		}
		if(prime>2){
			return 0;
		}
		prime=0;
    }
    return 1;
}