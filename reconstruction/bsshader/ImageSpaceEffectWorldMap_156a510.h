// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// ImageSpaceEffectWorldMap, ImageSpaceEffectWorldMap::UpdateParams, ImageSpaceEffect, ImageSpaceEffect::effectParams, ImageSpaceEffect::effectTextures: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTPrimitiveArray, ImageSpaceEffectParam, ImageSpaceShaderParam: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageSpaceEffectTexture, ImageSpaceManagerRenderTargets, RenderTargetEntry, WorldMapState, Function1015790, Function1554f90, Function1555120, Function15550b0, Function152b170, g_renderTargetTable, g_worldMapState, g_worldMapVec, g_const0, g_const1, entries, width, height, unk00, unk08, unk160, unk164, data, capacity, size, emptySlot, growthSize: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectParam
{
};

struct RenderTargetEntry
{
    std::uint32_t width;   // 00
    std::uint32_t height;  // 04
    std::uint8_t unk08[0x14];
};
static_assert(sizeof(RenderTargetEntry) == 0x1C, "RenderTargetEntry size");

struct ImageSpaceManagerRenderTargets
{
    std::int32_t Function1015790();  // callee at 0x1015790, not compared

    RenderTargetEntry entries[1];
};

extern ImageSpaceManagerRenderTargets g_renderTargetTable;

struct WorldMapState
{
    std::uint8_t unk00[0x160];
    float unk160;  // 160
    float unk164;  // 164
};

extern WorldMapState* g_worldMapState;
extern const float g_const0;
extern const float g_const1;
extern float g_worldMapVec[4];

class ImageSpaceEffectTexture
{
public:
    void Function1554f90(std::int32_t a_target);  // callee at 0x1554f90, not compared
    void Function1555120(std::int32_t a_mode);    // callee at 0x1555120, not compared
    std::int32_t Function15550b0();               // callee at 0x15550b0, not compared
};

class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
public:
    void Function152b170(std::int32_t a_idx, float a_x, float a_y, float a_z, float a_w);  // callee at 0x152b170, not compared
};

template <class T>
class NiTPrimitiveArray
{
public:
    virtual ~NiTPrimitiveArray();

    T* data;                   // 08
    std::uint16_t capacity;    // 10
    std::uint16_t size;        // 12
    std::uint16_t emptySlot;   // 14
    std::uint16_t growthSize;  // 16
};

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();

    std::uint8_t unk08[0x20];                                       // 08
    NiTPrimitiveArray<ImageSpaceEffectParam*> effectParams;         // 28
    NiTPrimitiveArray<ImageSpaceEffectTexture*> effectTextures;     // 40
};
static_assert(offsetof(ImageSpaceEffect, effectTextures) == 0x40, "effectTextures offset");

class ImageSpaceEffectWorldMap : public ImageSpaceEffect
{
public:
    bool UpdateParams(ImageSpaceEffectParam* a_param);  // compared: 0x156a510
};
