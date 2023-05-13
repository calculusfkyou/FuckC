#include<iostream>
using namespace std;
#define DEFAULT_STACK_SIZE 10
class Stack{
private:
    int top;
    int*arr;
public: 
    /*在此定義完整的stack類別，使得main()可以完美執行*/
    Stack() : top(-1) {
        arr=new int[DEFAULT_STACK_SIZE];
    }
    Stack(int size) : top(-1) {
        if (size <= 0) {
            cout << "Invalid stack size!\n";
            exit(EXIT_FAILURE);
        }
        arr = new int[size];
    }
    Stack(const Stack& s) : top(s.top) {
        arr = new int[DEFAULT_STACK_SIZE];
        for (int i = 0; i <= top; i++) {
            arr[i] = s.arr[i];
        }
    }
    bool is_empty() { 
        return top == -1;
    }
    bool is_full() {
        return top == DEFAULT_STACK_SIZE - 1;
    }
    void push(int element) {
        if (is_full()) {
            cout << "Stack overflow error!\n";
            exit(EXIT_FAILURE);
        }
        arr[++top] = element;
    }
    int pop() {
        if (is_empty()) {
            cout << "Stack underflow error!\n";
            exit(EXIT_FAILURE);
        }
        return arr[top--];
    }
    int peek(){
        if(is_empty()){
            cout<<"Stack is empty~\n";
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    void print_stack(){
        if(is_empty()){
            cout<<"Stack is empty~\n";
            return;
        }
        cout<<"Elements in the stack: ";
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    Stack& operator<<(int data){
        push(data);
        return *this;
    }
    Stack& operator<<(Stack &s){
        Stack temp(s);
        while (!temp.is_empty()) {
            push(temp.pop());
        }
        return *this;
    }
    Stack& operator=(const Stack& s){
        if(this == &s){
            return *this;
        }
        Stack temp(s),temp2;
        while(!temp.is_empty()){ 
            temp2.push(temp.pop()); 
        }
        while(!temp2.is_empty()){
            push(temp2.pop()); 
        }
        return *this;
    }
    Stack& operator+=(Stack& s) {
        if(s.is_empty()){
            return *this;
        }
        else{
            Stack temp(s),temp2; 
            while(!temp.is_empty()){
                temp2.push(temp.pop()); 
            }
            while(!temp2.is_empty()){
                push(temp2.pop()); 
            }
        }
        return *this;
    }
    Stack& operator-() {
        if(!is_empty()) {
            pop();
        }
        else{
            cout << "Stack is empty!\n";
        }
        return *this;
    }
    int operator-=(int num) {
        int popped_element;
        while (num--) {
            popped_element = pop();
        }
        return popped_element;
    }
    int operator~() {
        return peek();
    }
    void operator!() {
        while (!is_empty()) {
            pop();
        }
        // cout << "Stack is empty!\n";
    }
};
ostream& operator<<(ostream&os, Stack&s){   //cout
    s.print_stack();
    return os;
}
// Stack& operator+(const Stack& s1, const Stack& s2) {
//     Stack temp(s1);
//     temp += s2;
//     return temp;
// }
int main(){
    int m=5;
    Stack s1,s2(m),s3(s1);  //overloading constructors
    cout<<s1<<s2<<s3;       //display the stack content
    s1<<1<<2<<3;            // << : push element
    cout<<s1<<s2<<s3;       //overloading <<
    s2<<8<<9;               //s1:123 s2:89
    s3=s2+=s1<<4;           // +=: copy content to other stack //先做<< //s1:1234 //s2+=s1 //s2=891234 //s3=s2
//    s3=(s2+s1)<<4;
    cout<<s1<<s2<<s3;       
    cout<<-s1<<-s2<<-s3;    // -: pop
    cout<<s1<<s2<<s3;       
    cout<<~s1<<~s2<<5<<"\n";      // ~:peek
    !s1;                    // empty stack  
    s1<<0<<s2;              //overloading <<  // 我將 "<<" 設定為 s1原本的資料保留，然後將s2裡的資料由top丟進s1，
    cout<<s1<<(s2<<-1)<<s3; 
    return 0;
}