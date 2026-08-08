#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template <typename T>
class student
{
    static_assert(!is_floating_point_v<T>, "Floating-point values are not allowed for student.");

    T name;
    T age;

public:
    student(const T& n, const T& a) : name(n), age(a)
    {
    }

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void add(const T& n, const T& a)
    {
        name = n;
        age = a;
        cout << "Student added: " << name + age << endl;
    }
};

int main()
{
    student<int> s1(44, 24);
    student<string> s3("Anirudh", "Meena");
    s1.display();
    s3.display();
    s1.add(10, 20);
    s3.add("Anirudh ", "Meena");
    return 0;
}
