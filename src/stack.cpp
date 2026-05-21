#include <iostream>
using namespace std;
class Stack{
    int arr[5];
    int top;
    public:
    Stack():top(-1) {}
void push (int val)
{
   if(top == 4) 
   {
    cout<<"stack is full"<<endl;
  }
  else
  {
    top++;
    arr[top] = val;
  }
}
void pop ()
{
   if(top == -1) 
   {
    cout<<"stack is empty"<<endl;
  }
  else
  {
    top--;
   
  }
}
void display()
{
    if(top == -1)
    {
        cout<<"stack is empty\n";
    }
    else
    {
        for (int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
    }
    
}

} ;
int main()
{
    Stack s;
    s.push(11);
    s.push(13);
    s.pop();
    s.pop();
    s.display();
}