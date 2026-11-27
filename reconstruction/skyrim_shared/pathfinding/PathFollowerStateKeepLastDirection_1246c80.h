// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// PathFollowerStateKeepLastDirection, PathFollowerStateKeepLastDirection::SaveGame: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingStreamWrite, IPathingRefSaver, NiPoint3, Unk_00, WriteFloat, Unk_02, Unk_03, WriteUInt32, GetRefId, x, y, z, vtable, direction, unk14, unk18: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class BSPathingStreamWrite
{
public:
    virtual void Unk_00();
    virtual void WriteFloat(float a_value);
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void WriteUInt32(std::uint32_t a_value);
};

class IPathingRefSaver
{
public:
    virtual void Unk_00();
    virtual std::uint32_t GetRefId(void* a_ref);
};

class PathFollowerStateKeepLastDirection
{
public:
    void SaveGame(BSPathingStreamWrite* a_stream, IPathingRefSaver* a_refSaver);

    void* vtable;
    NiPoint3 direction;
    float unk14;
    void* unk18;
};

static_assert(offsetof(PathFollowerStateKeepLastDirection, direction) == 0x08, "direction offset");
static_assert(offsetof(PathFollowerStateKeepLastDirection, unk14) == 0x14, "unk14 offset");
static_assert(offsetof(PathFollowerStateKeepLastDirection, unk18) == 0x18, "unk18 offset");
