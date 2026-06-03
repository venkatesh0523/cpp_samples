#include<iostream>
#include<utility>
using namespace std;
class A {
    int x;
public:
    A(int val) : x(val) {}
    void display1() const {
        cout << "Value: " << x << endl;
    }
};
template<typename T>
concept Displayable = requires(T a) {
    { a.display1() } -> std::same_as<void>;
};
template<typename T>
concept Displayableone = requires(T a) {
    { a.display1() } -> std::same_as<void>;
};
template<Displayableone T>
void show(const T& obj) {
    obj.display1();
}
int main() {
    A a(42.3);
    show(a); // Works because A satisfies the Displayable concept
    return 0;
}