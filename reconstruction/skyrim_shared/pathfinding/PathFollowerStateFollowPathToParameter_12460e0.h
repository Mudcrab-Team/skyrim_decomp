// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// PathFollowerStateFollowPathToParameter, Func2_14112E2A0: CRASHLOGGER_PDB(59818@2026.10.24)
// PathFollowerWriter, PathFollowerIdResolver, WriteFloat, WriteUInt32, ResolveId, unk00, param08, param0C, param10, unk14, target18, Unk_02, Unk_03: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class PathFollowerWriter
{
public:
    virtual ~PathFollowerWriter();
    virtual void WriteFloat(float value);           // 08
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void WriteUInt32(std::uint32_t value);  // 20
};

class PathFollowerIdResolver
{
public:
    virtual ~PathFollowerIdResolver();
    virtual std::uint32_t ResolveId(void* target);  // 08
};

class PathFollowerStateFollowPathToParameter
{
public:
    void Func2_14112E2A0(PathFollowerWriter* writer, PathFollowerIdResolver* resolver);

    std::uint64_t unk00;     // 00
    float         param08;   // 08
    float         param0C;   // 0C
    float         param10;   // 10
    std::uint32_t unk14;     // 14
    void*         target18;  // 18
};
static_assert(sizeof(PathFollowerStateFollowPathToParameter) == 0x20, "PathFollowerStateFollowPathToParameter size");
