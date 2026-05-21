#include <iostream>
#include <memory>
using namespace std;
class Sample {
public:
    Sample() {
        std::cout << "Sample constructor called!" << std::endl;
    }
    ~Sample() { 
        std::cout << "Sample destructor called!" << std::endl;
    }
    void display() {
        std::cout << "Hello from Sample class!" << std::endl;
    }
};
int main() {
    unique_ptr<Sample> samplePtr1(new Sample());
samplePtr1->display();
    unique_ptr<int> ptr1(new int[5]{1, 2, 3, 4, 5});
    for (int i = 0; i < 5; ++i) {
        cout << "Value of ptr1: " << ptr1.get()[i] << endl;   
    }

    // Transfer ownership to ptr2
        unique_ptr<int> ptr2 = move(ptr1);
        for (int i = 0; i < 5; ++i) {
        cout << "Value of ptr2: " << ptr2.get()[i] << endl;
        }

    // Check if ptr1 is empty
    if (!ptr1) {
        cout << "ptr1 is now empty." << endl;
    }
    if (!ptr2) {
        cout << "ptr2 is now empty." << endl;
    }

    return 0;
}

