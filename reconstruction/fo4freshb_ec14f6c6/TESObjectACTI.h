// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// TESObjectACTI, TESObjectACTI::InitializeData: GUESS(low)
// TESObjectACTI fields: STANDIN GUESS(low)
// Supporting types: STANDIN GUESS(low)
#pragma once
#include <cstdint>

class TESObjectACTI {
public: void InitializeData();
private: std::uint8_t pad[0xa8]; void* soundLoop; void* soundActivate; void* waterForm; std::uint16_t flags;
};
