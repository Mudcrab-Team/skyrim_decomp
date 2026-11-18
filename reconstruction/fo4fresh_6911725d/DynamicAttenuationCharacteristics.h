// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Body reconstructed from the target listing.
// GetMaxDistance: Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSSoundOutput.cpp:77
// DynamicAttenuationCharacteristics, BGSSoundOutput::DynamicAttenuationCharacteristics::GetMaxDistance: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, actorValue, maxDistance: STANDIN GUESS(low)
#pragma once
#include <cstdint>
namespace BGSSoundOutput {
class DynamicAttenuationCharacteristics {
public:
    float GetMaxDistance() const;
private:
    std::uint32_t unknown00[3];
    float maxDistance;
};
}
