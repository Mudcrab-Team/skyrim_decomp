// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: SetFlagRecursive.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00c80000_o2.cpp:1176
// 0x1052750 SetFlagRecursive
// CI hash: 0x1052750 ?bhkUtilFunctions_SetCOUseVel@@YAX_NPEAUWalkNode_cls@@@Z
#include "Globals_1052750.h"

void SetFlagRecursive(bool abSet, WalkNode_cls* node)
{
    FlaggedObj_cls* f = node->m_1c;
    if (f != 0)
    {
        if (abSet)
        {
            f->m_0c |= 0x20;
        }
        else
        {
            f->m_0c &= 0xffdf;
        }
    }

    WalkNode_cls* child = node->v03();
    if (child != 0)
    {
        unsigned int i = 0;
        while (i < child->m_a6)
        {
            WalkNode_cls** arr = child->m_a0;
            WalkNode_cls* item = arr[i];
            if (item != 0)
            {
                SetFlagRecursive(abSet, item);
            }
            ++i;
        }
    }
}
