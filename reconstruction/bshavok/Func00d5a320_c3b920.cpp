// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00d5a320::AssignReference.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesshape.cpp:52
// 0xc3b920 Func00d5a320::AssignReference
#include "Func00d5a320_c3b920.h"

void Func00d5a320::AssignReference(RefObj* apRef, bool b)
{
    if (apRef) apRef->RetainReference();
    if (*(DDCC60World**)((char*)this + 0x88)) (*(DDCC60World**)((char*)this + 0x88))->removeReference();
    *(RefObj**)((char*)this + 0x88) = apRef;
    if (b && apRef) Func00d59f40();
}
