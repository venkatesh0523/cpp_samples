#include <iostream>
#include <string>
#include <vector>
using namespace std;
class student {
    int id;
    string name;
    int physics_mark;
    int math_mark;
    int chemistry_mark;
public:
student(int id, string name, int physics_mark, int math_mark, int chemistry_mark):id(move(id)), name(std::move(name)), physics_mark(move(physics_mark)), math_mark(move(math_mark)), chemistry_mark(move(chemistry_mark)) {}
void sample_function() {
    
        std::cout << id<< name << physics_mark << math_mark << chemistry_mark << std::endl;
    
}
};

int main() {
    std::cout << "Hello from the sample framework!\n";
    std::cout << "enter number of students: \n";
    vector<student> students;
    int n;
    cin >> n;
    while (n--) {
        int id;
        string name;
        int physics_mark;
        int math_mark;
        int chemistry_mark;
        cout << "enter id: \n";
        cin >> id;
        cout << "enter name: \n";
        cin >> name;
        cout << "enter physics mark: \n";
        cin >> physics_mark;
        cout << "enter math mark: \n";
        cin >> math_mark;
        cout << "enter chemistry mark: \n";
        cin >> chemistry_mark;
        student s(id, name, physics_mark, math_mark, chemistry_mark );
        students.push_back(s);
    }
    
 
    for ( auto& s : students) {
        s.sample_function();
    }
    return 0;
}
