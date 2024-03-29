// #include<iostream>
// using namespace std;
// #define DEFAULT_STACK_SIZE 10
// class Stack{
// private:
//     int top;
//     int*arr;
// public: 
//     /*在此定義完整的stack類別，使得main()可以完美執行*/     
//     int len=DEFAULT_STACK_SIZE;                                 
//     Stack() : top(-1) {
//         arr=new int[DEFAULT_STACK_SIZE];
//     }
//     Stack(int size) : top(-1) {
//         if (size <= 0) {
//             cout << "Invalid stack size!\n";
//             exit(EXIT_FAILURE);
//         }
//         arr = new int[size];
//         len=size;
//     }
//     Stack(const Stack& s) : top(s.top) {
//         arr = new int[DEFAULT_STACK_SIZE];
//         for (int i = 0; i <= top; i++) {
//             arr[i] = s.arr[i];
//         }
//     }
//     bool is_empty() { 
//         return top == -1;
//     }
//     bool is_full() {
//         return top==len-1;
//     }
//     void push(int element) {
//         if (is_full()) {
//             cout << "Stack overflow error!\n";
//             exit(EXIT_FAILURE);
//         }
//         arr[++top] = element;
//     }
//     int pop() {
//         if (is_empty()) {
//             cout << "Stack underflow error!\n";
//             exit(EXIT_FAILURE);
//         }
//         return arr[top--];
//     }
//     int peek(){
//         if(is_empty()){
//             cout<<"Stack is empty~\n";
//             exit(EXIT_FAILURE);
//         }
//         return arr[top];
//     }
//     void print_stack(){
//         if(is_empty()){
//             cout<<"Stack is empty~\n";
//             return;
//         }
//         cout<<"Elements in the stack: ";
//         for(int i=top;i>=0;i--){
//             cout<<arr[i]<<" ";
//         }
//         cout<<"\n";
//     }
//     Stack& operator<<(int data){
//         if(!is_full())
//             push(data);
//         return *this;
//     }
//     Stack& operator<<(Stack &s){
//         Stack temp(s);
//         while (!temp.is_empty()) {
//             push(temp.pop());
//         }
//         return *this;
//     }
//     Stack& operator=(const Stack& s){
//         if(this == &s){
//             return *this;
//         }
//         Stack temp(s),temp2;
//         while(!temp.is_empty()){ 
//             temp2.push(temp.pop()); 
//         }
//         while(!temp2.is_empty()){
//             push(temp2.pop()); 
//         }
//         return *this;
//     }
//     Stack& operator+=(Stack& s) {
//         if(s.is_empty()){
//             return *this;
//         }
//         else{
//             Stack temp(s),temp2; 
//             while(!temp.is_empty()){
//                 temp2.push(temp.pop()); 
//             }
//             while(!temp2.is_empty()){
//                 if(!is_full())
//                     push(temp2.pop()); 
//                 else
//                     break;
//             }
//         }
//         return *this;
//     }
//     Stack& operator-() {
//         if(!is_empty()) {
//             pop();
//         }
//         else{
//             cout << "Stack is empty!\n";
//         }
//         return *this;
//     }
//     int operator~() {
//         return peek();
//     }
//     void operator!() {
//         while (!is_empty()) {
//             pop();
//         }
//         // cout << "Stack is empty!\n";
//     }
// };
// ostream& operator<<(ostream&os, Stack&s){   //cout
//     s.print_stack();
//     return os;
// }
// int main(){
//     int m=5;
//     Stack s1,s2(m),s3(s1);  //overloading constructors
//     cout<<s1<<s2<<s3;       //display the stack content
//     s1<<1<<2<<3;            // << : push element
//     cout<<s1<<s2<<s3;       //overloading <<
//     s2<<8<<9;               //s1:123 s2:89
//     s3=s2+=s1<<4;           // +=: copy content to other stack //先做<< //s1:1234 //s2+=s1 //s2=89123 //s3=s2 //注意長度
// //    s3=(s2+s1)<<4;
//     cout<<s1<<s2<<s3;       
//     cout<<-s1<<-s2<<-s3;    // -: pop
//     cout<<s1<<s2<<s3;       
//     cout<<~s1<<~s2<<5;      // ~:peek
//     !s1;                    // empty stack  
//     s1<<0<<s2;              //overloading <<  // 我將 "<<" 設定為 s1原本的資料保留，然後將s2裡的資料由top丟進s1，
//     cout<<s1<<(s2<<-1)<<s3; 
//     return 0;
// }
#include <stdio.h>
class Actor{
    int left, right;
public:
    Actor(int);
    Actor(int, int);
    Actor(Actor&);
    Actor& operator+(Actor);
    int operator!();
};
Actor::Actor(int n):left(n), right(-n){}
Actor::Actor(int m, int n){ left=-m; right=m-n;}
Actor::Actor(Actor& actor):left(actor.right), right(actor.left){}
Actor& Actor::operator+(Actor actor){
    left+=actor.left;
    right=actor.right;
    actor.left=actor.right=0;
    return *this;
}
int Actor::operator!(){
    if(left>right)
    printf("%d%d\n", left,right);
    else
    printf("%d\n", right-left);
    return left+right;
}
int main(){
    Actor joe(11111102 % 5), mary(11111102 % 10, 11111102 % 2);
    Actor peter(mary);
    !joe; // (1)
    !!mary; // (2)
    printf("%d\n", !peter+11); // (3)
    !(joe+mary); // (4)
    return 0;
}