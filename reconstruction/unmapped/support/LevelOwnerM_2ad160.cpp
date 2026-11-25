// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: LevelOwnerM::Func004c8f40.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004c0000_o2.cpp:1689
// 0x2ad160 LevelOwnerM::Func004c8f40
#include "LevelOwnerM_2ad160.h"

float LevelOwnerM::Func004c8f40()
{
    int level;
    if (data28)
        level = data28->level98;
    else if (source20)
        level = source20->GetLevelM();
    else
        level = 0;
    return (float)(level << 12);
}
