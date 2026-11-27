// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00cf6920.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp:443
// 0xaa8e80 Func00cf6920
#include "Globals_aa8e80.h"

void Func00cf6920(void* a1, Node* apNode, void* apArg)
{
    if (a1 == 0)
        return;
    Node* p = apNode;
    do
    {
        WriteReflectedMembers(a1, p, apArg);
        p = p->Func00d46d50();
    } while (p != 0);
}
