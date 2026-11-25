// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00455150::Func00455150_Array::Func00455150.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00440000_o2.cpp:9188
// 0x317e20 f3m_00455150::Func00455150_Array::Func00455150
#include "NiFormArray_317e20.h"

namespace f3m_00455150 {
void* Func00455150_Array::Func00455150(unsigned int index)
{
    if (index >= size)
        return 0;
    void* element = data[index];
    data[index] = 0;
    if (element)
        --count;
    if (index == size - 1)
        --size;
    return element;
}
}
