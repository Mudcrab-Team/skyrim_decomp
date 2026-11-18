// Origin: original partial declarations from target listing and sibling type/name hints.
// Source exposure: mixed (pinned target listing and sibling hints).
// PlayerCamera, PlayerCamera::SetSittingRotation: GUESS(low)
// PlayerCamera fields: STANDIN GUESS(low)
// CameraState: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct CameraState { std::uint8_t pad[0x68]; float rotation; };
class PlayerCamera {
public:
    void SetSittingRotation(float value);
private:
    std::uint8_t pad[0xb8]; CameraState* state;
};
