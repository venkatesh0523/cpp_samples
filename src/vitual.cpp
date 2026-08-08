#include <iostream>
#include <memory>
using namespace std;
class Base {
    
protected:
int i=21;
public:
    virtual void display() {
        cout << "Base class display function" << endl;
    }
};
class Derived : public Base {

    public:
    void display()
    {
        cout<<i;
    }

};
int main() {
   shared_ptr<Base> b ,b1;
   b= make_shared<Derived>();
   b1=b;
   b->display();
   b1->display();
}