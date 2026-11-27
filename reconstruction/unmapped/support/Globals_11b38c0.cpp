// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: RoundUpToPowerOfTwo.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00ea0000_od.cpp:9
// 0x11b38c0 RoundUpToPowerOfTwo
#include "Globals_11b38c0.h"

unsigned int RoundUpToPowerOfTwo(unsigned int value)
{
    if (value > 16)
    {
        if (value > 64)
        {
            if (value > 128)
            {
                if (value > 256)
                {
                    if (value > 512)
                    {
                        return 1024;
                    }
                    else
                    {
                        return 512;
                    }
                }
                else
                {
                    return 256;
                }
            }
            else
            {
                return 128;
            }
        }
        else
        {
            if (value > 32)
            {
                return 64;
            }
            else
            {
                return 32;
            }
        }
    }
    else
    {
        if (value > 4)
        {
            if (value > 8)
            {
                return 16;
            }
            else
            {
                return 8;
            }
        }
        else
        {
            if (value > 2)
            {
                return 4;
            }
        }
    }
    return value;
}
