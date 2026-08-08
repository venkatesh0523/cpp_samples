#include<iostream>
#include<thread>
#include<chrono>
#include<queue>
#include<mutex>
#include<functional>
#include<condition_variable>
#include<vector>
#include<utility>
#include<fstream>

using namespace std;

mutex output_mtx;
size_t number_count = 0;

class threadpool
{
    vector<thread> threads;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop;
    public:

    void func()
    {
        while(true)
        {
            function<void()> task;
            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [this]{ return stop || !tasks.empty(); });
                if(stop && tasks.empty())
                {
                    return;
                }
                task = move(tasks.front());
                tasks.pop();
            }
            task();
        }
    }
    threadpool(size_t num_threads = thread::hardware_concurrency())
    {
        stop = false;
        for(size_t i=0; i<num_threads; i++)
        {
            threads.emplace_back(&threadpool::func, this);
        }
    }
    template<class F, class... Args>
    void enqueue(F&& f, Args&&... args)
    {
        {
            unique_lock<mutex> lock(mtx);
            tasks.emplace(bind(forward<F>(f), forward<Args>(args)...));
        }
        cv.notify_one();
    }
    ~threadpool()
    {        {
            unique_lock<mutex> lock(mtx);
            stop = true;
        }
        cv.notify_all();        
         for(thread &worker : threads)
        {
            worker.join();
        }  
    } 


};

void example_task1(int n)
{
    // it will open file and write 10 line text1 to text10 in file named text.txt
    {
        lock_guard<mutex> lock(output_mtx);
        std::ofstream file("src/rec/test.txt", std::ios::app);
        for(int i=1; i<=100; i++)
        {
            file<<"Task "<<n<<" is running in thread "<<i<<" with ID "<<this_thread::get_id()<<endl;
        }
        std::cout<<"Task "<<n<<" is running in thread "<<this_thread::get_id()<<endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));
}
void example_task2(int n)
{
    // it will open file and write 11 line text1 to text20 in file named text.txt
    {
        lock_guard<mutex> lock(output_mtx);
        std::ofstream file("src/rec/test.txt", std::ios::app);
        for(int i=101; i<=200; i++)
        {
            file<<"Task "<<n<<" is running in thread "<<i<<" with ID "<<this_thread::get_id()<<endl;
        }
        std::cout<<"Task "<<n<<" is running in thread "<<this_thread::get_id()<<endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));
}
void example_task3(int n)
{
    // it will open file and write 21 line text1 to text30 in file named text.txt
    {
        lock_guard<mutex> lock(output_mtx);
        std::ofstream file("src/rec/test.txt", std::ios::app);
        for(int i=201; i<=300; i++)
        {
            file<<"Task "<<n<<" is running in thread "<<i<<" with ID "<<this_thread::get_id()<<endl;
        }
        std::cout<<"Task "<<n<<" is running in thread "<<this_thread::get_id()<<endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));
}
void example_task4(int n)
{
    // it will open file and write 31 line text1 to text40 in file named text.txt
    {
        lock_guard<mutex> lock(output_mtx);
        std::ofstream file("src/rec/test.txt", std::ios::app);
        for(int i=301; i<=400; i++)
        {
            file<<"Task "<<n<<" is running in thread "<<i<<" with ID "<<this_thread::get_id()<<endl;
        }
        std::cout<<"Task "<<n<<" is running in thread "<<this_thread::get_id()<<endl;
    }
    this_thread::sleep_for(chrono::milliseconds(100));
}
void counter_task()
{
      std::ofstream file("src/rec/test.txt", std::ios::app);
      //count "Task" word in file and write count to file from line 1 to line 100
      {
          lock_guard<mutex> lock(output_mtx);
          ifstream input_file("src/rec/test.txt");
          string line;
          while(getline(input_file, line))
          {
              if(line.find("Task") != std::string::npos)
              {
                  number_count++;
              }
          }
         
          std::cout<<"Counter Task is running in thread "<<this_thread::get_id()<<" and count is "<<number_count<<endl;
      }
}
int main()
{
    threadpool pool(4);
    std::function<void(int)> tasks[] = {example_task1, example_task2, example_task3, example_task4};
        
    
       // pool.enqueue(tasks[0], 1);
       // pool.enqueue(tasks[1], 2);
        //pool.enqueue(tasks[2], 3);
        //pool.enqueue(tasks[3], 4);
        pool.enqueue(counter_task);
    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}   
