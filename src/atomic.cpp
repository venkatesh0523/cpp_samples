#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

int main()
{
    //std::atomic<int> sum(0);
    int sum = 0;

    auto f = [&sum]() {
        for (int i = 0; i < 10; i++)
        {
            sleep(1);
            sum++;
        }
    };

    std::vector<std::thread> threads;

    for (int i = 0; i < 8; i++)
    {
        threads.emplace_back(f);
    }

    for (auto& t : threads)
    {
        t.join();
    }

    std::cout << "Expected: " << 8000000 << std::endl;
    std::cout << "Actual:   " << sum << std::endl;

    return 0;
}