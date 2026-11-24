// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSTweenerModifier, UpdateRate, UpdateContext, pad00, useFixedRate, fixedRate, rate80, delta40: GUESS(low); stand-in class view, members named by offset only
#pragma once
#include <cstdint>

struct UpdateContext
{
    std::uint8_t pad00[0x40];  // 00
    float delta40;             // 40
};

class BSTweenerModifier
{
public:
    void UpdateRate(void* a_unused, const UpdateContext* a_context);  // compared: 0xbbc170

    std::uint8_t pad00[0x52];  // 00
    std::uint8_t useFixedRate;  // 52
    std::uint8_t pad53;         // 53
    float fixedRate;            // 54
    std::uint8_t pad58[0x28];   // 58
    float rate80;               // 80
};
