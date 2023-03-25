#include<stdio.h>
int fn(int num,int num2);
int count=0;
int m=16,n=4;
int main(){
	printf("%d",fn(m,n));
	return 0;
}
int fn(int num,int num2){
	if(num==0){
		return count;
	}
	if(num2==0){
		return 0;
	}
	if(num>=num2){
		count+=1;
		return fn(num-num2,num2);
	}
	return count;
}