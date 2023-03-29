#include<stdio.h>
#include<stdlib.h>
//1.
//int main(){
//	int a=10,b=20;//A
//	int* p=&a;//B
//	int* q=&b;
//	int temp=*p;//C
//	*p=*q;
//	*q=temp;
//	int sum=*p+*q,diff=*p-*q,product=*p*(*q),quotient=*p/(*q);//D
//	printf("%d %d %d %d %d %d",a,b,sum,diff,product,quotient);//E
//	return 0;
//}

//2.
//int main(){
//	int arr[10];//A
//	for(int i=0,j=2;i<10;i++,j+=2)
//		if(i%2==0)
//			arr[i]=j;
//		else
//			arr[i]=-j;
//	int* p=&arr[0];//B
//	int sum=0;//C
//	for(int i=0;i<10;i++)
//		sum+=*(p+i);
//	int max=arr[0],min=arr[0];
//	for(int i=0;i<10;i++){//D
//		if(*p>max){
//		    max=*p;
//			*p++;
//		}
//		else{
//			min=*p;
//			*p++;
//		}
//	}
//	printf("%d %d %d",sum,max,min);//E
//	return 0;
//}

//3.
struct Node{//A
	int data;
	struct Node* next;
};
int main(){
	struct Node* head=(struct Node*)malloc(sizeof(struct Node));//B
	struct Node* second=(struct Node*)malloc(sizeof(struct Node));
	head->data=1;//C
	second->data=2;
	head->next=second;//D
	second->next=NULL;
	struct Node* temp=head;
	while(temp!=NULL){//E
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	temp=head;//F
	head=head->next;
	free(temp);
	
	temp=head;
	while(temp!=NULL){//G
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return 0;
}
