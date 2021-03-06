#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std::chrono;
int main ()
{
    auto t0 = high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::microseconds(999));
    auto t1 = high_resolution_clock::now();

    // std::cout << std::fixed;
	// std::cout.precision(0);
    uint64_t dt = duration_cast<nanoseconds>(t1 - t0).count();
    std::cout << '\n' << dt << "ns\n";
    dt = (round (double(dt) / 1000) );
    std::cout << dt << "us\n";
    dt = (round (double(dt) / 1000) );
    std::cout << dt << "ms\n";

    //std::cin.get();
	return 0;
}
