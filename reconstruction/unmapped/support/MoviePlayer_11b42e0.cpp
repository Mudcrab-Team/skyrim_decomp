// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_007fb000::MoviePlayer::CalculateScale.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_007e0000_o2.cpp:3706
// 0x11b42e0 f3m_007fb000::MoviePlayer::CalculateScale
#include "MoviePlayer_11b42e0.h"

namespace f3m_007fb000 {
float MoviePlayer::CalculateScale(unsigned int divisorA, unsigned int divisorB, bool useFirst)
{
    if (useFirst)
        return (float)GetFirst() / divisorA;
    else
        return (float)GetSecond() / divisorB;
}
}
