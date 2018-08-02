#ifndef STD_HPP
#define STD_HPP

#include "types.hpp"

namespace Mali
{
    namespace std
    {
        static inline uint8_t inb(uint16_t port)
        {
            uint8_t ret;
            asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
            return ret;
        }

        static inline void outb(uint16_t port, uint8_t val)
        {
            asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
        }

        static char* itoa(int value, int base)
        {
            static char buf[32] = { 0 };
            int i = 30;
            bool m = false;

            if (value < 0)
            {
                m = true;
                value = (value*-1);
            }
            
            for(; value && i ; --i, value /= base)
                buf[i] = "0123456789abcdef"[value % base];

            if (m)
            {
                m = false;
                buf[i] = '-';
                i--;
            }
            
            return &buf[i+1];
            
        }
    }
}

#endif