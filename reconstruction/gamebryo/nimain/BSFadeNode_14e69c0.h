// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSFadeNode, SetFadeRange, pad00, fadeNear, fadeFar, minFadeNear: GUESS(low); stand-in class view, members named by offset only
#pragma once
#include <cstdint>

// minFadeNear: GUESS(low); integer tunable
extern std::int32_t minFadeNear;

class BSFadeNode
{
public:
    void SetFadeRange(float a_near, float a_far);  // compared: 0x14e69c0

    std::uint8_t pad00[0x128];  // 00
    float fadeNear;             // 128
    float fadeFar;              // 12C
};
