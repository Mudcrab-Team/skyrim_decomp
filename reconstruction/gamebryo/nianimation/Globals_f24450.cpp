// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: LoadEnum.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:363
// 0xf24450 LoadEnum
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:305
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:159
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:189
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:165
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:197
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:298
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:357
// Adapted helpers: LoadEnum, Write, GetWriter, Load
// CI hash: 0xf24450 ??$LoadEnum@W4KeyType@AnimationKey@@@@YAXPEAUStreamBinView_cf@@AEAW4KeyType@AnimationKey@@@Z
#include "Globals_f24450.h"

template <class T> inline void LoadEnum(StreamBinView_cf* istr, T& v)
{
    unsigned int u;
    istr->Load(&u);
    v = (T)u;
}

template void LoadEnum<enum AnimationKey::KeyType>(struct StreamBinView_cf *, enum AnimationKey::KeyType &);
