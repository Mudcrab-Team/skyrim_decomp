// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// FindNonExcludedDeliveryFunctor, FindNonExcludedDeliveryFunctor::MatchCondition: GUESS(low)
// FindNonExcludedDeliveryFunctor fields: STANDIN GUESS(low)
// Supporting types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct EffectSetting { std::uint8_t pad[0xdc]; int delivery; };
struct EffectItem { std::uint8_t pad[0x10]; EffectSetting* setting; };
class FindNonExcludedDeliveryFunctor {
public: bool MatchCondition(EffectItem* item);
private: std::uint8_t pad[0x18]; int excluded;
};
