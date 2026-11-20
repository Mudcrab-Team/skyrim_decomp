// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Body reconstructed from the target listing.
// SetActorValue: Sibling source: fo4-private@1b765c70 src/Game/Magic/StimpakEffect.cpp:6
// ValueModifierEffect, ValueModifierEffect::SetActorValue: SIBLING(fo4-private@1b765c70, author-permission)
// unknown00, actorValue, maxDistance: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class ValueModifierEffect {
public:
    void SetActorValue(std::uint32_t value);
private:
    std::uint64_t unknown00[18];
    std::uint32_t actorValue;
};
