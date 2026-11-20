// Source exposure: mixed (pinned image and cited public names).
// Code origin: original implementation using the observed cleanup and partial layouts.
// BaseEquals: GUESS(low)
// NiBackToFrontAccumulator, IsEqual: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>

class NiObject;

class NiBackToFrontAccumulator
{
public:
    virtual bool IsEqual(NiObject* other);

private:
    std::uint8_t BaseEquals(NiObject* other);
};
