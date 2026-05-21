#include <iostream>
#include <memory>
using namespace std;        
class Node{
public:
    int data;
    std::unique_ptr<Node> next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    std::unique_ptr<Node> head;
public:
    LinkedList() : head(nullptr) {}
    void insert(int val) {
        auto newNode = std::make_unique<Node>(val);
        if (!head) {
            head = std::move(newNode);
        } else {
            Node* current = head.get();
            while (current->next) {
                current = current->next.get();
            }
            current->next = std::move(newNode);
        }
    }
    void display() const {
        Node* current = head.get();
        while (current) {
            std::cout << current->data << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
};
int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    std::cout << "Linked List: ";
    list.display();
    return 0;
}