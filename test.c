#include<stdio.h>
#include<stdlib.h>
//1
// int useWhile(char* str){
//     int count=0;
//     int i=0;
//     while(str[i]!='\0'){
//         if(str[i]>='A' && str[i]<='z')
//             count+=1;
//         i+=1;
//     }
//     return count;
// }
int useWhile(char* str){
    int count=0;
    while(*str!='\0'){
        if(*str>='A' && *str<='z')
            count+=1;
        str++;
    }
    return count;
}
int useFor(char *str){
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='A' && str[i]<='z')
            count+=1;
    }
    return count;
}
int useRecur(char*str,int i){
    int count=0;
    if(str[i]=='\0')
        return count;
    if(str[i]>='A' && str[i]<='z')
        count+=1;
    return count+useRecur(str,i+1);
}
// int useRecur(char*str,char* v){
//     static int count=0;
//     if(!v)
//         v=str;
//     if(v=='\0'){
//         int a=count;
//         count=0;
//         return a;
//     }
//     if(*v>='A' && *v<='z')
//         count+=1;
//     return useRecur(str,v+1);
// }
int main(){
    char str1[]="1a1b1c ";
	char str2[]="2Z2Z2Z Zz2";
	char str3[]="";
	char str4[]={'a',66,'A',0,'a',0};
	char str5[]="aA  b\nnNxy";
    printf("%d %d %d %d %d\n",useWhile(str1),useWhile(str2),useWhile(str3),useWhile(str4),useWhile(str5));
    printf("%d %d %d %d %d\n",useFor(str1),useFor(str2),useFor(str3),useFor(str4),useFor(str5));
    printf("%d %d %d %d %d",useRecur(str1,0),useRecur(str2,NULL),useRecur(str3,NULL),useRecur(str4,NULL),useRecur(str5,NULL));
}

//2,3
// struct node{
//     int data;
//     struct node*next;
// };
// int main(){
//     //2
//     struct node* first=(struct node*)malloc(sizeof(struct node));
//     struct node* second=(struct node*)malloc(sizeof(struct node));
//     struct node* third=(struct node*)malloc(sizeof(struct node));
//     struct node* forth=(struct node*)malloc(sizeof(struct node));
//     first->data=10;
//     first->next=second;
//     second->data=20;
//     second->next=third;
//     third->data=30;
//     third->next=forth;
//     forth->data=40;
//     forth->next=0;
//     struct node* head=first;
//     //3
//     struct node*temp=third;
//     third=third->next;
//     free(temp);
//     temp=forth;
//     free(forth);
//     second->next=0;
//     return 0;
// }

// //5
// #define ch(x) ((x)>=('A') && (x)<=('z')) ? 1 : 0