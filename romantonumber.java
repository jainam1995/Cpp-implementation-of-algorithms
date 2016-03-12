#include<iostream>
#include <stdlib.h>
  

  
struct node
{
    int a;
    int b;
};
  
typedef struct node Node;
  
void swap(void *a,void *b)
{
    void *temp;
    temp=a;  
    a=b; 
    b=temp;
}
   
int main()
{
    Node *a1,*b1;
    a1=(Node*)malloc(sizeof(Node));
    b1=(Node*)malloc(sizeof(Node));
    a1->a=10;
    a1->b=20;
    b1->a=30;
    b1->b=40;
    cout<<a1->a<<" "<<a1->b<<endl;
    cout<<b1->a<<" "<<b1->b<<endl;
    cout << a1 << " " << b1 << endl;
    swap(a1,b1);
    cout << a1 << " " << b1 << endl;
    cout<<a1->a<<" "<<a1->b<<endl;
    cout<<b1->a<<" "<<b1->b;
}