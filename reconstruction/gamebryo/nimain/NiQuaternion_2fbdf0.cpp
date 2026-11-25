// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_008e2480::NiQuaternion::ToRotation.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:21760
// 0x2fbdf0 f3m_008e2480::NiQuaternion::ToRotation
// Sibling source: momusdigital/fnv_decomp@2b07cb3e include/NiPoint3.h:44
// Sibling source: momusdigital/f3_decomp@f5bac1b5 include/NiPoint3.h:23
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00700000_o2.cpp:82357
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:21742
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:21743
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:21744
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:21745
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:21747
// Adapted helpers: operator*=, SetCol, SetW, SetX, SetY, SetZ, Normalize
#include "NiQuaternion_2fbdf0.h"

namespace f3m_008e2480 {
void NiQuaternion::ToRotation(NiMatrix3& rot) const
{
	float tx = 2.0f*m_fX;
	float ty = 2.0f*m_fY;
	float tz = 2.0f*m_fZ;
	float twx = tx*m_fW;
	float twy = ty*m_fW;
	float twz = tz*m_fW;
	float txx = tx*m_fX;
	float txy = ty*m_fX;
	float txz = tz*m_fX;
	float tyy = ty*m_fY;
	float tyz = tz*m_fY;
	float tzz = tz*m_fZ;

	rot.SetCol(0, 1.0f-(tyy+tzz), txy+twz, txz-twy);
	rot.SetCol(1, txy-twz, 1.0f-(txx+tzz), tyz+twx);
	rot.SetCol(2, txz+twy, tyz-twx, 1.0f-(txx+tyy));
}
}
