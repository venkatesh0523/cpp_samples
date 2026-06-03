#include<iostream>
#include<utility>
#include<memory>
using namespace std;
void process(const string& str) {
    cout << "Processing: " << str << endl;
}   
/*void process(const string&& str) {
    cout << "venkat: " << str << endl;
} */      
template<typename T>
void wrapper(T&& arg) {
    process(forward<T>(arg)); // Perfect forwarding
}

int main()
 {
    // Using move semantics to transfer ownership of a resource
    string str = "Hello, World!";
    wrapper(str); // Calls process(const string& str)
    wrapper("Hello, Move!"); // Calls process(const string&& str) 
    process("Hello, Move!"); // Calls process(const string&& str) and str is now in a valid but unspecified state          
    int* ptr1 = new int(10); // ptr1 owns the resource
    int *ptr2 = move(ptr1); // ptr2 now owns the resource, ptr1 is left in a valid but
    ptr1= move(ptr2); // ptr1 is now a nullptr, ptr2 is the only owner
   // delete ptr2; // Clean up the resource
    cout << "ptr2: " << *ptr1 << endl; 
    unique_ptr<int> uptr1(new int(20)); // uptr1 owns the resource
    unique_ptr<int> uptr2 = move(uptr1); // uptr2 nowowns the resource, uptr1 is left empty
    uptr1 = move(uptr2); // uptr1 now owns the resource, uptr2 is empty
    cout << "uptr2: " << *uptr1 <<  endl; 
    return 0;
}
 