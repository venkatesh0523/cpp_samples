#include    <iostream>
#include    <memory>
#include    <queue>
#include    <mutex>
#include    <condition_variable>
#include    <thread>
using namespace std;

class Queue
{
    int arr[5];
    int front;
    int rear;
    public:
    Queue(): front(-1),rear(-1) {}
    void enque(int val)
    {
    if( rear == 4)       
    {
        cout<<"Queqe is empty\n"; 
    }
    else
    {
        rear++;
        arr[rear] = val;
        if(front == -1)
        {
            front = 0;
        }
    }
    }
    void dqueue() {
        if (front != -1) {
            front++;
            if (front > rear) {
                front = rear = -1; // Reset the queue when it's empty
            }
        } else {
            cout << "Queue is empty!" << endl;
        }
    }
    void display()
    {
        if (front == rear)
        {
            cout<<"queue is empty1\n";
        }
        else{
            for(int i=front ;i<=rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    }

}  ;
int main()
{
    Queue q;
    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);
    q.enque(50);
    q.display();
    q.dqueue();
    q.dqueue();
    q.dqueue();
    q.dqueue();
    q.dqueue();
    q.dqueue();
    q.display();
    return 0;
}
