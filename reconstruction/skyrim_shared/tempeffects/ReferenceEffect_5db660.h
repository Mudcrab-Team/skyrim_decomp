// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// ReferenceEffect, ReferenceEffect::ClearTarget: GUESS(low)
// ReferenceEffect fields: STANDIN GUESS(low)
// Supporting types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
extern std::uint32_t nullHandle;
class ReferenceEffect {
public: void ClearTarget();
private: std::uint8_t pad[0x38]; std::uint32_t target;
};
