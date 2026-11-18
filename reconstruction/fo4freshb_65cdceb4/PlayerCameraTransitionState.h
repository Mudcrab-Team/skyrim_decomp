// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// PlayerCameraTransitionState, PlayerCameraTransitionState::Begin: GUESS(low)
// PlayerCameraTransitionState fields: STANDIN GUESS(low)
// Supporting types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
extern std::uint32_t lastTime;
class PlayerCameraTransitionState {
public: void Begin();
private: std::uint8_t pad[0x20]; std::uint32_t startTime;
};
