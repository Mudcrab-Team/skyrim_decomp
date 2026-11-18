// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// InitializeData: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:102
// TESGrass::InitializeData: SIBLING(fo4-private@1b765c70, author-permission)
// waterDistance, waterMode, grassFlags: STANDIN GUESS(low)
// SetDensity: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:35
// SetMinSlopeDegrees: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:46
// SetMaxSlopeDegrees: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:55
// SetWavePeriod: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESGrass.cpp:91
// TESGrass, TESGrass::SetDensity, TESGrass::SetMinSlopeDegrees, TESGrass::SetMaxSlopeDegrees, TESGrass::SetWavePeriod: SIBLING(fo4-private@1b765c70, author-permission)
// 0x2704e0 TESGrass::InitializeData
// 0x2703d0 TESGrass::SetDensity
// 0x2703f0 TESGrass::SetMinSlopeDegrees
// 0x270410 TESGrass::SetMaxSlopeDegrees
// 0x2704c0 TESGrass::SetWavePeriod
#include "TESGrass.h"

bool TESGrass::SetDensity(std::uint8_t value) { if (value <= 100) { density = value; return true; } return false; }
bool TESGrass::SetMinSlopeDegrees(std::uint8_t value) { if (value > 90 || value > maxSlope) return false; minSlope = value; return true; }
bool TESGrass::SetMaxSlopeDegrees(std::uint8_t value) { if (value > 90 || value < minSlope) return false; maxSlope = value; return true; }
bool TESGrass::SetWavePeriod(float value) { if (value > 0.0f) { wavePeriod = value; return true; } return false; }

void TESGrass::InitializeData() { density = 30; minSlope = 0; waterDistance = 0; waterMode = 0; grassFlags = 0; maxSlope = 90; positionRange = 32.0f; heightRange = 0.2f; colorRange = 0.5f; wavePeriod = 10.0f; }
