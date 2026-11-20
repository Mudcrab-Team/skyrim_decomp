// Source exposure: binary-analysis.
// Code origin: original partial layouts for request options and their embedded list.
// PathingRequest: EXE_RTTI
// PathRequestIndexList, PathRequestSettings, GetIndexList, ClearIndexList, SetIndex, ReadSettings, Resize, SetOrAppend: GUESS(low)
#pragma once

#include <cstdint>

struct PathRequestIndexList
{
    void Resize(std::uint32_t count);
    void SetOrAppend(std::uint32_t index);
};

struct PathRequestSettings
{
    std::uint32_t requestID;
    bool exceedsThreshold;
    bool option5;
    bool option4;
};

class PathingRequest
{
public:
    PathRequestIndexList& GetIndexList();
    void ClearIndexList();
    void SetIndex(std::uint32_t index);
    void ReadSettings(PathRequestSettings& output) const;

private:
    std::uint8_t unknown00[0xb0];
    std::uint32_t requestID;
    std::uint8_t unknownB4[0xc];
    float requestDistance;
    std::uint8_t unknownC4[0xc];
    std::uint32_t flags;
    std::uint8_t unknownD4[4];
    PathRequestIndexList indexList;
};
