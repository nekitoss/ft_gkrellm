
#include "CPU.hpp"
#include "Network.hpp"

int main(void) {
    CPU h;
    h.upData();
    std::cout << h.getCPU() << std::endl;
    std::cout << h.getCPULoad() << std::endl;
    Network n;
    n.upData();
    std::cout << n.getButes() << std::endl;
    std::cout << n.getPuckets() << std::endl;
}