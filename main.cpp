#include "include/hds.h"
#include "include/hds1.h"
#include "include/hds2.h"


int main() {
    std::cout << "------------hds.test()-----------------" << std::endl;
    hds::test();
    std::cout << "------------hds1.test()-----------------" << std::endl;
    hds1::test();
    std::cout << "------------hds2.test()-----------------" << std::endl;
    hds2::test();
    return 0;
}
