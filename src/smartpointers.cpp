#include <iostream>
#include <memory>

using namespace std;

struct Mystruct
{
    double d1;   // 8 bytes
    char c1;    // 1 byte
    char c2;    // 1 byte
     double d;   // 8 bytes

    char c3;    // 1 byte
    
    char c4;    // 1 byte
    char c5;    // 1 byte
    
    char c6;    // 1 byte
    char c7;    // 1 byte
    
    char c8;    // 1 byte
     char c9;    // 1 byte
    
};

class Myclass
{
     int no;
    const char *name;
protected:
   

public:
    Myclass(int n, const char *n_name) : no(n), name(n_name)
    {
        cout << "Constructor called" << endl;
    }

    virtual ~Myclass()
    {
        cout << "Destructor called" << endl;
    }

    virtual void display()
    {
        cout << "Display function called " << no << " " << name << endl;
    }
};

class Myclass2 : public Myclass
{
public:
    Myclass2(int n, const char *n_name) : Myclass(n, n_name)
    {
        cout << "Myclass2 Constructor called" << endl;
    }

    ~Myclass2() 
    {
        cout << "Myclass2 Destructor called" << endl;
    }

    void display() 
    {
        cout << "Myclass2 Display function called "  << endl;
    }
};

int main()
{
    unique_ptr<Myclass> ptr1 = make_unique<Myclass>(5, "Alice");

    ptr1->display();
    ptr1 = make_unique<Myclass2>(9, "Bob");
    ptr1->display();

    cout << "End of main function" << sizeof(Mystruct) << endl;
}
