#include "../src/util/fd.h"
#include <fcntl.h>
#include <iostream>
#include <utility>

int main() {
    Fd a(open("/dev/null", O_RDONLY));

    std::cout << "a holds " << a.get() << "\n";

    {
        Fd b = std::move(a);

        std::cout
            << "b holds " << b.get()
            << ", a valid: "
            << a.valid()
            << "\n";
    }

    std::cout << "after block\n";
}