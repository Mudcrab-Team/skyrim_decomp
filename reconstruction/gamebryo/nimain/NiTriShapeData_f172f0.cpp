// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_00845ee0::NiTriShapeData::IsEqual.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00840000_o2.cpp:835
// 0xf172f0 f3m_00845ee0::NiTriShapeData::IsEqual
#include "NiTriShapeData_f172f0.h"

namespace f3m_00845ee0 {
bool NiTriShapeData::IsEqual(NiTriShapeData* other){if(!Func008557e0(other))return false;if(count!=other->count)return false;if(memcmp(data,other->data,count*2))return false;return true;}
}
