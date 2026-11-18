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
// Fields and helper types: STANDIN GUESS(low)
#pragma once
#include <cstdint>

class TESGrass
{
public:
    void InitializeData();
    bool SetDensity(std::uint8_t value);
    bool SetMinSlopeDegrees(std::uint8_t value);
    bool SetMaxSlopeDegrees(std::uint8_t value);
    bool SetWavePeriod(float value);
private:
    std::uint64_t unknown00[11];
    std::uint8_t density, minSlope, maxSlope, unknown5b;
    std::uint16_t waterDistance, unknown5e;
    std::uint32_t waterMode;
    float positionRange, heightRange, colorRange, wavePeriod;
    std::uint8_t grassFlags;
};
