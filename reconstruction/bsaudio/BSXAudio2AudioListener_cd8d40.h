// Source exposure: mixed (pinned image and sibling symbol names).
// Code origin: original reconstruction; minimal layout inferred from the pinned image.
// BSXAudio2AudioListener, SetOrientation: SYMBOLS(tesv-2013-map)
// ListenerVector, x, y, z, unk00, unk08, unk10, front, top, unk2C, reserved30, reserved38, x3dFront, x3dTop: GUESS(low); vector fields and coordinate conversion inferred from use.
// 0xcd8d40 BSXAudio2AudioListener::SetOrientation
#pragma once
#include <cstddef>
#include <cstdint>

struct ListenerVector {
    float x;
    float y;
    float z;
};

class BSXAudio2AudioListener {
public:
    void SetOrientation(const ListenerVector& direction, const ListenerVector& up);

    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint32_t unk10;
    ListenerVector front;
    ListenerVector top;
    std::uint32_t unk2C;
    std::uint64_t reserved30;
    std::uint64_t reserved38;
    ListenerVector x3dFront;
    ListenerVector x3dTop;
};
static_assert(offsetof(BSXAudio2AudioListener, front) == 0x14, "front offset");
static_assert(offsetof(BSXAudio2AudioListener, top) == 0x20, "top offset");
static_assert(offsetof(BSXAudio2AudioListener, x3dFront) == 0x40, "converted front offset");
static_assert(offsetof(BSXAudio2AudioListener, x3dTop) == 0x4C, "converted top offset");
