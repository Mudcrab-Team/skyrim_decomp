// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: PathingTaskData::DestroyIfFlagged.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/geometrydecalshader.cpp:87
// 0x11f7950 PathingTaskData::DestroyIfFlagged
// CI hash: 0x11f7950 ?DestroyIfFlagged@PathingTaskData@@QEAAPEAXI@Z
#include "PathingTaskData_11f7950.h"

void* PathingTaskData::DestroyIfFlagged(unsigned int a)
{
    ((Func00bcb210_shell*)this)->Func00bcb210();
    if (a & 1)
        _delete(this, 0x90);
    return this;
}
