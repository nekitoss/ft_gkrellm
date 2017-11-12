
#include "CPU.hpp"
#include "RAM.hpp"

int main(void) {
    CPU h;
    h.upData();
    std::cout << h.getCPU() << std::endl;
    std::cout << h.getCPULoad() << std::endl;
    RAM n;
    n.upData();
    std::cout << n.getRam() << std::endl;
    std::cout << n.getUseram() << std::endl;
}