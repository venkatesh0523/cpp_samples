#include <iostream>
#include <thread>
#include <functional>
#include <queue>
#include <mutex>
using namespace std;
mutex mtx1, mtx2;
void display(int n) {
    std::lock_guard<std::mutex> lock(mtx1);
    for (int i = 0; i < n; i++) {
        cout << "Venkat: " << i << endl;
    }
   //  std::lock_guard<std::mutex> lock2(mtx2);
}
void displayr(int n) {
    std::lock_guard<std::mutex> lock(mtx1);
    for (int i = 0; i < n; i++) {
        cout << "rahul: " << i << endl;
    }
   //  std::lock_guard<std::mutex> lock2(mtx1);
}
 std::function<void(int)> func = display;
 std::function<void(int )> func2 = displayr;
void thread_function(std::function<void(int)> f, int n) {
    f(n);
}
void venkat()
{
    for (int i = 0; i < 10; i++) {
        cout << "Venkat12: " << i << endl;
    }
}
int main() {
       // Queue of tasks
   // queue<function<void()> > tasks_;
   // tasks_.emplace
    thread t1(thread_function,func,10);
    thread t2(thread_function,func2,10 );
    t1.join();
    t2.join();
   // thread t3(venkat);
   // t3.join();
   // cout << endl;

    return 0;
}

