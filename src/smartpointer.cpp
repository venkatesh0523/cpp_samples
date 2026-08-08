#include <iostream>
#include <memory>
#include <string>
class B;
class Person
{
public:
    std::string name;

    Person(const std::string& personName)
        : name(personName)
    {
        std::cout << name << " created\n";
    }

    ~Person()
    {
        std::cout << name << " destroyed\n";
    }

    void Speak() const
    {
        std::cout << "Hello, I am " << name << '\n';
    }
};

class A
{
    std::string name;
    std::unique_ptr<B> bPtr ;
    
public:
    A(std::string name);
    void displayB() const;
    ~A()
    {
        std::cout << "A destroyed\n";
    }
    
    
};
class B
{
    std::string name;

    std::unique_ptr<A> aPtr;
public: 
B(std::string name):name(name  )
{
  std::cout << "B created" << name << std::endl;
}    
    ~B() { std::cout << "B destroyed\n"; }

    void display() 
    {
        std::cout << "B's name: " << name << '\n';
    }
};
A::A(std::string name):name(name)
    {
        std::cout << "A created for" << name << std::endl;
        bPtr = std::make_unique<B>("kumar");
        bPtr->display();
    }
    void A::displayB() const
    {
        std::cout << "A's name: " << name << '\n';
        bPtr->display();
    }
int main()
{
    /*Person person("John");
    person.Speak();
    std::unique_ptr<Person> personPtr = std::make_unique<Person>("Alice");
    personPtr->Speak();
    std::unique_ptr<Person> anotherPersonPtr = std::move(personPtr);
   anotherPersonPtr->Speak();
   std::shared_ptr<Person> sharedPersonPtr = std::make_shared<Person>("Bob");
    if (!personPtr) 
    {
        std::cout << "personPtr is now null after move\n"<<sharedPersonPtr.use_count() << std::endl;
    }
    std::weak_ptr<Person> weakPersonPtr = sharedPersonPtr;
    if(auto lockedPtr = weakPersonPtr.lock()) 
    {
        lockedPtr->Speak();
    } 
    else 
    {
        std::cout << "sharedPersonPtr is no longer valid\n";
    }*/
    std::unique_ptr<A> aPtr = std::make_unique<A>("venkatesh");
   aPtr->displayB();
   // aPtr->bPtr = std::make_unique<B>("kumar");

}