// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00c1b0b0_cls::Func00c1b0b0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/niparticlesystem.cpp:2915
// 0xf99260 Func00c1b0b0_cls::Func00c1b0b0
#include "NiParticleSystem_f99260.h"

bool Func00c1b0b0_cls::Func00c1b0b0(S_00c1b0b0_Stream* kStream)
{
    if (!Func00a9b190(kStream))
        return false;

    for (S_00c1b0b0_Item* pkPos = unkC8; pkPos;)
    {
        S_00c1b0b0_Obj*& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        element->v21(kStream);
    }

    return true;
}
