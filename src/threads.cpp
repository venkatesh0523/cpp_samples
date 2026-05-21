#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
mutex mtx;
condition_variable cv;
bool first_thread_turn = true;

void display() {
    for (int i = 0; i < 10; i++) {
        cout << "Venkat: " << i << endl;
    }
}

void thread_function() {
    for (int i = 0; i < 10; i=i+2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return first_thread_turn; });
        cout << "thread1: " << i << endl;
        first_thread_turn = false;
        cv.notify_one();
    }
}

void thread_function2() {
    for (int i = 1; i < 10; i=i+2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !first_thread_turn; });
        cout << "thread2: " << i << endl;
        first_thread_turn = true;
        cv.notify_one();
    }
}

int main() {
    thread t1(thread_function);
    thread t2(thread_function2);

    t1.join();
    t2.join();

    cout << endl;
    return 0;
}
