#include<iomanip>
#include<iostream>
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
    
    
};
struct Mystruct1
{
    double d1;   // 8 bytes
   
     double d;   // 8 bytes
    char c1;    // 1 byte
    char c2;    // 1 byte
    char c3;    // 1 byte
    
    char c4;    // 1 byte
    char c5;    // 1 byte
    
    char c6;    // 1 byte
    char c7;    // 1 byte
    
    char c8;    // 1 byte
    
    
};
int main()
{
    Mystruct s1;
    cout << "Size of Mystruct is " << sizeof(Mystruct1) << endl;
        cout << "Size of Mystruct is " << sizeof(s1) << endl;
        cout << "Size of double is " << sizeof(double) << endl;
        cout << "Size of char is " << sizeof(char) << endl;


        return 0;
}
