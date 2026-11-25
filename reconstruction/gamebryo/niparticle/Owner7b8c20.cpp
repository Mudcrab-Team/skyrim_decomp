// Source exposure: mixed. Drafted from local instruction listings and
// decompiler output of the pinned image, with types from the header beside this file.
// Code origin: original reconstruction from binary analysis; the Sibling source lines below name where a body parallels an admitted sibling. Stamped as a twin of matched 0xfa11c0 (gamebryo/niparticle/NiPSysModifier): source copied, names replaced by placeholders.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:53
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:86
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:42
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:52 (LinkObject, CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:41 (ProcessClone, CC0-1.0)
// 0x7b8c20 Owner7b8c20::SetSystemPointer
#include "Owner7b8c20.h"
#include <intrin.h>
#include <cstdint>
#include <new>

// guess: same compiled code as matched 0xfa11c0 apart from relocated fields; its role here is not established.
void Owner7b8c20::SetSystemPointer(NiParticleSystem* a_target)
{
    target = a_target;
}
