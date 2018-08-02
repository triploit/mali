#include "lib/video.hpp"
#include "lib/types.hpp"
#include "lib/multiboot.hpp"

extern "C" void xkernel()
{
    Mali::screen << "Willkommen im C++-TestKernel!";
}
