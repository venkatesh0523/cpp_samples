#include<iostream>
#include<type_traits>
using namespace std;

template<typename T>
typename enable_if<is_floating_point<T>::value, void>::type
 func(T t)
{
    cout <<"floating-point t="<<t<<endl;
}
//Substitution Failure Is Not An Error (SFINAE) is a C++ template metaprogramming technique that allows the compiler to ignore certain template instantiations when they result in substitution failures. This is particularly useful for creating function templates that are only valid for specific types, enabling compile-time type checking and function overloading based on type traits.
int main()
{
    // func(10);
    func(10.5); // This will cause a compile-time error due to SFINAE
    //return 0;
}