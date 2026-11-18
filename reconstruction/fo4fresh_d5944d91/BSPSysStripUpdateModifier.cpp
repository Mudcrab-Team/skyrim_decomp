// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/BSMain/BSPSysStripUpdateModifier.cpp:12 (BSPSysStripUpdateModifier::Initialize)
// BSPSysStripUpdateModifier, Initialize: GUESS(low)
// 0x1002c80 BSPSysStripUpdateModifier::Initialize
#include "BSPSysStripUpdateModifier.h"

void BSPSysStripUpdateModifier::Initialize(NiPSysData* data, unsigned short particle, NiPoint3*) { static_cast<BSStripPSysData*>(data)->InitializePoint(particle); }
