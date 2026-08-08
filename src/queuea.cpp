#include<iostream>
#include<functional>
#include<thread>

using namespace std;
#include <queue>

void function1()
{
   for (int i = 0; i < 10; i++)
   {
       cout << "This is a function f1: " << i << endl;
   }
}
void function2()
{
    for (int i = 0; i < 10; i++)
    {       
   cout << "This is a function f2: " << i << endl;
    }
   
}
void function3()
{
   for (int i = 0; i < 10; i++)
   {
       cout << "This is a function f3: " << i << endl;
   }
}
int main()
{   
    
    std::function<void()> f1 = function1;
    std::function<void()> f2 = function2;
    std::function<void()> f3 = function3;
    std::queue<std::function<void()>> q;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    q.push(f1);
    while (!q.empty())
    {
        std::function<void()> f = q.front();
        thread t1(f);
         thread t2(f);
        t1.join();
        t2.join();
        q.pop();
    }   
    
    
    return 0;
}