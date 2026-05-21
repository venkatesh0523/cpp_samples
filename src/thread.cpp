#include <iostream>
#include <thread>
#include <functional>
using namespace std;
void display(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Venkat: " << i << endl;
    }
}
void displayr(int n) {
    for (int i = 0; i < n; i++) {
        cout << "rahul: " << i << endl;
    }
}
 std::function<void(int)> func = display;
 std::function<void(int )> func2 = displayr;
void thread_function(std::function<void(int)> f, int n) {
    f(n);
}
int main() {
    thread t1(thread_function,func,10);
    thread t2(thread_function,func2,10 );
    t1.join();
    t2.join();
    cout << endl;
    return 0;
}

