#include "lib/video.hpp"
#include "lib/types.hpp"
#include "lib/multiboot.hpp"

extern "C" void xkernel()
{
    Mali::screen << "Hallo Welt: " << Mali::std::itoa(12, 10) << " " << -12;
}
