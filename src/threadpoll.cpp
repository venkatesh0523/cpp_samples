#include<iostream>
#include<functional>
#include<thread>
#include<queue>
#include<vector>
#include<mutex>  
#include<condition_variable>   
using namespace std;
class ThreadPoll
{
    std::vector<std::thread> thread_;
    queue<function<void()>> task_queue;
    mutex mtx;
    condition_variable cv;
    bool stop_ = false;
public:
ThreadPoll(size_t num_threads = thread::hardware_concurrency()  )
{
    
    for(size_t i =0;i<num_threads;i++)
    {
        thread_.emplace_back([this](){
                while(true)
                {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(mtx);
                        cv.wait(lock, [this](){ return !task_queue.empty() || stop_; });
                        if(stop_ && task_queue.empty())
                        {
                            return; // exit the thread
                        }
                        task = move(task_queue.front());
                        task_queue.pop();

                    }
                    task();
                }
        });
    }

}
~ThreadPoll()
{
    {
        unique_lock<mutex> lock(mtx);
        stop_ = true;
    }
    cv.notify_all();
    for(thread &t : thread_)
    {
        if(t.joinable())
        {
            t.join();
        }
    }
}
void enqueue(function<void()> task)
{
    unique_lock<mutex> lock(mtx);
    task_queue.emplace(move(task));
    cv.notify_one();
}
    
};
int main()
{
    ThreadPoll pool(4); // create a thread pool with 4 threads
    for(int i =0;i<10;i++)
    {
        pool.enqueue([i](){
            cout<<"Task "<<i<<" is being processed by thread "<<this_thread::get_id()<<endl;
        });
    }
    return 0;
}
