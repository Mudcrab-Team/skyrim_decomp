// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// PathFollowerStateFollowPathToParameter, Func3_14112E310: CRASHLOGGER_PDB(59818@2026.10.24)
// PathFollowerReader, PathFollowerTargetLookup, ReadFloat, ReadUInt32, LookupTarget, unk00, param08, param0C, param10, unk14, target18, Unk_01..Unk_03: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class PathFollowerReader
{
public:
    virtual ~PathFollowerReader();
    virtual void ReadFloat(float* value);           // 08
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void ReadUInt32(std::uint32_t* value);  // 20
};

class PathFollowerTargetLookup
{
public:
    virtual ~PathFollowerTargetLookup();
    virtual void  Unk_01();
    virtual void* LookupTarget(std::uint32_t id);  // 10
};

class PathFollowerStateFollowPathToParameter
{
public:
    void Func3_14112E310(PathFollowerReader* reader, PathFollowerTargetLookup* lookup);

    std::uint64_t unk00;     // 00
    float         param08;   // 08
    float         param0C;   // 0C
    float         param10;   // 10
    std::uint32_t unk14;     // 14
    void*         target18;  // 18
};
static_assert(sizeof(PathFollowerStateFollowPathToParameter) == 0x20, "PathFollowerStateFollowPathToParameter size");
