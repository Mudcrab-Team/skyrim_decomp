// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// 0xf80490 NiLookAtInterpolator::~NiLookAtInterpolator
// Adapted bodies: NiLookAtInterpolator::~NiLookAtInterpolator follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nianimation/nilookatinterpolator_noehsc_variant.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nianimation/nilookatinterpolator_noehsc_variant.cpp:28
#include "NiLookAtInterpolator_f80490.h"

NiLookAtInterpolator::~NiLookAtInterpolator()
{
    m_kTargetNodeName.Copy(emptyLookAtName);
}
