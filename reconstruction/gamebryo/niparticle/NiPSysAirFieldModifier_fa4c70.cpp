// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiPSysAirFieldModifier::SaveBinary_140D0D7A0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysairfieldmodifier.cpp:378
// 0xfa4c70 NiPSysAirFieldModifier::SaveBinary_140D0D7A0
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/bsanimnote.cpp:265
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00940000_o2.cpp:1790
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niparticle/nipsysairfieldmodifier.cpp:190
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysairfieldmodifier.cpp:328
// Adapted helpers: BinaryWrite, SerializeValue
#include "NiPSysAirFieldModifier_fa4c70.h"

void NiPSysAirFieldModifier::SaveBinary_140D0D7A0(NiStream& stream)
{
    NiPSysFieldModifierBase::SaveBinary(stream);
    m_kFogTint.SaveBinary(stream);
    SerializeValue(stream.m_pBackingStream, m_f58);
    SerializeValue(stream.m_pBackingStream, m_f5C);
    unsigned char ucBool = m_b60;
    SerializeValue(stream.m_pBackingStream, ucBool);
    ucBool = m_b61;
    SerializeValue(stream.m_pBackingStream, ucBool);
    ucBool = m_b62;
    SerializeValue(stream.m_pBackingStream, ucBool);
    SerializeValue(stream.m_pBackingStream, m_f64);
}
