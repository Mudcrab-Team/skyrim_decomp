// Source exposure: mixed (permitted sibling game code; pinned-image observations).
// Code origin: original declarations from target observations and labelled naming sources
// MovementHandlerAgentPlayerControls, MovementHandlerAgentPlayerControls::SaveGame: SIBLING(fo4-private@1b765c70, author-permission)
// PathingWriter, inputType, dampenAccelerationMultiplier, field4C: GUESS(low)
#pragma once
#include <cstdint>
class PathingWriter {
public:
    virtual void Unknown0() = 0;
    virtual void WriteFloat(float value) = 0;
    virtual void Unknown2() = 0;
    virtual void Unknown3() = 0;
    virtual void WriteUnsigned(std::uint32_t value) = 0;
    virtual void Unknown5() = 0;
    virtual void Unknown6() = 0;
    virtual void Unknown7() = 0;
    virtual void Unknown8() = 0;
    virtual void Unknown9() = 0;
    virtual void WriteBool(bool value) = 0;
};
class MovementHandlerAgentPlayerControls {
public:
    void SaveGame(PathingWriter& stream) const;
    std::uint8_t prefix[0x38];
    std::uint32_t inputType;
    std::uint8_t gap3C[0xC];
    float dampenAccelerationMultiplier;
    bool field4C;
};
