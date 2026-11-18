// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/BSMain/BSPSysStripUpdateModifier.cpp:12 (BSPSysStripUpdateModifier::Initialize)
// BSPSysStripUpdateModifier, Initialize: GUESS(low)
#pragma once

// NiPSysData, BSStripPSysData, NiPoint3, InitializePoint, data, particle, position: GUESS(low)
class NiPSysData {};
class BSStripPSysData : public NiPSysData { public: void InitializePoint(unsigned short particle); };
class NiPoint3;
class BSPSysStripUpdateModifier { public: void Initialize(NiPSysData* data, unsigned short particle, NiPoint3* position); };
