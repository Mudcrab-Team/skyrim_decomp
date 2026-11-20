// Source exposure: binary-analysis.
// Code origin: original partial request layout for copying straight-line state.
// PathingRequestSafeStraightLine: EXE_RTTI
// PathingRequest, CopyMembers, straightLineState: GUESS(low)
#pragma once

#include <cstdint>

class PathingRequest
{
public:
    void CopyMembers(PathingRequest& destination) const;

protected:
    std::uint8_t unknown00[0x140];
};

class PathingRequestSafeStraightLine : public PathingRequest
{
public:
    void CopyMembers(PathingRequestSafeStraightLine& destination) const;

private:
    std::uint64_t straightLineState;
};
