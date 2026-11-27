// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiPSysMeshEmitter::LoadBinary_140D1A750.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp:2280
// 0xfb2d70 NiPSysMeshEmitter::LoadBinary_140D1A750
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp:2055
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp:1810
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp:2216
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp:1825
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmeshemitter.cpp:2231
// Adapted helpers: BinaryRead, NiBinaryStreamLoad, ReadC1E
#include "NiPSysMeshEmitter_fb2d70.h"

void NiPSysMeshEmitter::LoadBinary_140D1A750(NiStreamC1E& kStream)
{
    Func00c223b0(kStream);
    kStream.Func00a64670();
    m_uiValue74 = ReadC1E<unsigned int>(*kStream.m_pUnderlyingStream);
    m_uiValue78 = ReadC1E<unsigned int>(*kStream.m_pUnderlyingStream);
    m_kMember7C.Func00a59be0(kStream);
}
