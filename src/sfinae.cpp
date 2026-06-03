#include<iostream>
#include<type_traits>
using namespace std;

template<typename T>
typename enable_if<is_floating_point<T>::value, void>::type
 func(T t)
{
    cout <<"floating-point t="<<t<<endl;
}

int main()
{
   // func(10);
    func(10.5); // This will cause a compile-time error due to SFINAE
    //return 0;
}