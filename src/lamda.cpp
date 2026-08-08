#include <iostream>
#include <numeric>
#include <vector>

int main() {
    auto divide_by_two = [](int n) {
        return n / 2.0;
    };

    std::cout << "Normal lambda call: " << divide_by_two(10) << std::endl;

    const double average = [](int count) {
        std::vector<int> nums(count);
        std::iota(nums.begin(), nums.end(), 1);  // 1,2,3,...,count
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        std::cout << "Sum: " << sum << std::endl;
        return static_cast<double>(sum) / nums.size();
    }(10);  // Define and call immediately with 10

    std::cout << "Immediate lambda call: " << average << std::endl;

    return 0;
}
