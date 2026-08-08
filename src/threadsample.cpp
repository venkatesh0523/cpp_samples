#include<iostream>
#include<functional>
#include<queue>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>

using namespace std;

class threadpool
{
    vector<thread> threads;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop;
    public:
    threadpool(size_t num_threads = thread::hardware_concurrency())    {
        stop = false;
        for (size_t i = 0; i < num_threads; i++)        {
            threads.emplace_back([this]{
                while (true)                {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(mtx);
                        cv.wait(lock, [this]{ return stop || !tasks.empty(); });
                        if (stop && tasks.empty())                            {
                            return;
                        }
                        task = move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }
    template<class F, class... Args>
    void enqueue(F&& f, Args&&... args)    {
        {
            unique_lock<mutex> lock(mtx);
            tasks.emplace(bind(forward<F>(f), forward<Args>(args)...));
        }
        cv.notify_one();
    }
    ~threadpool()  
      {
        {
            unique_lock<mutex> lock(mtx);
            stop = true;
        }     cv.notify_all();          

      for (thread &worker : threads)        {
            worker.join();
        }
      }

};


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

int main()
{
    threadpool pool(4);

    while (true)
    {
        int i;

        cout << "\nSelect task to execute:\n";
        cout << "1. Execute function1\n";
        cout << "2. Execute function2\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> i))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (i)
        {
            case 1:
                pool.enqueue(function1);
                break;

            case 2:
                pool.enqueue(function2);
                break;

            case 3:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid input. Please enter 1, 2, or 3.\n";
                break;
        }
    }
}