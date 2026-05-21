#include<iostream>
#include <memory>
#include <cstring>
using namespace std;
class spointers
{
    unique_ptr<int> ptr;
    unique_ptr<string> name;
    unique_ptr<char[]> ptr2;
    public:
    spointers(int val, const string& n,const char *c)
    {
        ptr = make_unique<int>(val);
        name = make_unique<string>(n);
        ptr2 = make_unique<char[]>(strlen(c) + 1);
        strcpy(ptr2.get(), c);
    }
    void setvalue(int val)
    {
        *ptr = val;
    }
    void display()
    {
        cout<<"value is "<<*ptr<<" and name is "<<*name<<" and char is "<<ptr2.get()<<endl;
    }
};
int main()
{
    unique_ptr<spointers> s = make_unique<spointers>(22, "Alice", "venkat");
   // s->setvalue(10);
    s->display();
    return 0;
}