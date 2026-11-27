// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: fnv_00eace50::NiCollisionData::SetBoundingVolume.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nicollision/nicollisiondata.cpp:95
// 0xf23b00 fnv_00eace50::NiCollisionData::SetBoundingVolume
// CI hash: 0xf23b00 ?SetBoundingVolume@NiCollisionData@fnv_00eace50@@QEAAXPEAUNiBoundingVolume@2@@Z
#include "NiCollisionData_f23b00.h"

namespace fnv_00eace50 {
void NiCollisionData::SetBoundingVolume(NiBoundingVolume* pkBV)
{
    if (_2c)
        _2c->v2(1);
    if (_30)
        _30->v2(1);
    _2c = pkBV;
    if (pkBV)
    {
        _30 = pkBV->v6();
        if (_08)
            _30->v5(_2c, &_08->m_7c);
    }
    else
    {
        _30 = 0;
    }
}
}
