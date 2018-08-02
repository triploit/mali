#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "types.hpp"
#include "std.hpp"

namespace Mali
{
    namespace color {

        enum type
        {
            black = 0x00,
            blue = 0x01,
            green = 0x02,
            cyan = 0x03,
            red = 0x04,
            magenta = 0x05,
            brown = 0x06,
            light_gray = 0x07,
            dark_gray = 0x08,
            light_blue = 0x09,
            light_green = 0x0A,
            light_cyan = 0x0B,
            light_red = 0x0C,
            light_magenta = 0x0D,
            yellow = 0x0E,
            white = 0x0F
        };

    }

    struct background 
    {
        inline background(color::type color) : m_color(color) {}
        color::type m_color;
    };

    class Video 
    {
    private:
        uint16_t* buffer;
        uint16_t m_color;

        unsigned int posY;
        unsigned int posX;

        const size_t VGA_WIDTH = 80;
        const size_t VGA_HEIGHT = 25;

    public:
        Video();

        Video& operator << (const char* s);
        Video& operator << (int i);
        Video& operator << (color::type color);
        Video& operator << (const background& color);

        void setCursor(uint8_t x, uint8_t y);
        void putChar(char c);
        void clearScreen();
    };

    extern Video screen;
} // Mali

#endif