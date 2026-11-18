// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetRotation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:106
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:112
// ThirdPersonState, ThirdPersonState::GetRotation, ThirdPersonState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// Fields and helper types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct NiPoint3 { float x, y, z; };
struct NiQuaternion { float w, x, y, z; };
class ThirdPersonState
{
public:
    void GetRotation(NiQuaternion& value) const;
    void GetTranslation(NiPoint3& value) const;
private:
    std::uint64_t unknown00[8];
    NiPoint3 translation;
    NiQuaternion rotation;
};
