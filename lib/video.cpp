#include "video.hpp"

typedef unsigned int size_t;

namespace Mali
{
    Video screen;

    Video::Video() : buffer((uint16_t*) 0xb8000), posX(0), posY(0), m_color(0x0700)
    {
        clearScreen();
    }

    void Video::clearScreen()
    {
        for(int i = 0;i < (80*25);i++)
            buffer[i] = (unsigned char)' ' | m_color;

        posY = 0;
        posX = 0;

        setCursor(posX, posY);			
    }

    Video& Video::operator<<(const char* s)
    {
        while (*s != '\0')
            putChar(*s++);


        setCursor(posX, posY);
        return *this;
    }

    Video& Video::operator<<(color::type color)
    {
        m_color = (static_cast<uint16_t>(color) << 8) | (m_color & 0xF000);
        return *this;
    }

    Video& Video::operator<<(const background& color)
    {
        m_color = (static_cast<uint16_t>(color.m_color) << 12) | (m_color & 0x0F00);
        return *this;
    }

    void Video::putChar(char c)
    {
        if(posY >= VGA_WIDTH)
        {
            posY = 0;
            posX += VGA_WIDTH;
        }

        if(posX >= (VGA_WIDTH*VGA_HEIGHT))
            clearScreen();

        buffer[posX + posY] = (uint16_t)c | m_color;
        posY++;
    }

    void Video::setCursor(uint8_t x, uint8_t y) 
    {
        uint16_t tmp;
        tmp = x * VGA_WIDTH + y;

        std::outb(0x3D4,14);
        std::outb(0x3D5,tmp >> 8);

        std::outb(0x3D4,15);
        std::outb(0x3D5,tmp);
    }
}

