// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// AnimationStreamLoadGame, BGSLoadGameBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// TransformData7d9560, LoadDataEndian, LoadTransform, Unk_01, Unk_02, LoadQuat, buffer: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_dest, std::uint32_t a_size, std::uint32_t a_count);
};

struct TransformData7d9560
{
    float translation[4];
    float rotation[4];
    float scale[4];
};

class AnimationStreamLoadGame
{
public:
    virtual ~AnimationStreamLoadGame();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void LoadQuat(void* a_dest);

    bool LoadTransform(TransformData7d9560* a_dest);

    BGSLoadGameBuffer* buffer;
};

static_assert(offsetof(TransformData7d9560, rotation) == 0x10, "rotation offset");
static_assert(offsetof(TransformData7d9560, scale) == 0x20, "scale offset");
static_assert(offsetof(AnimationStreamLoadGame, buffer) == 0x08, "buffer offset");
