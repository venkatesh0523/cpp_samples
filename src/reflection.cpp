#include <iostream>
#include <meta> // New C++26 reflection header

enum class Color { Red, Green, Blue };

template <typename T>
void print_enum_names() {
    // 1. Get reflection info for the type T
    constexpr std::meta::info type_info = ^^T;
    
    // 2. Loop over the enum members at compile time
    template auto... member : std::meta::members_of(type_info) {
        // 3. Extract and print the name of each member
        std::cout << std::meta::name_of(member) << "\n";
    }
}

int main() {
    print_enum_names<Color>(); 
    // Output:
    // Red
    // Green
    // Blue
}
