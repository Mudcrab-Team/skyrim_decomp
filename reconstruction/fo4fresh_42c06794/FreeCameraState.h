// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:25
// FreeCameraState, FreeCameraState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// Fields and helper types: STANDIN GUESS(low)
#pragma once
#include <cstdint>
struct NiPoint3 { float x, y, z; };
class FreeCameraState
{
public:
    void GetTranslation(NiPoint3& value) const;
private:
    std::uint64_t unknown00[6];
    NiPoint3 translation;
};
