// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// ImageSpaceManager, ImageSpaceManager::SetupEffects, ImageSpaceManager::effects: CRASHLOGGER_PDB(59818@2026.10.24)
// ImageSpaceEffect, ImageSpaceEffectParam, BSTriShape, NiTPrimitiveArray: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// unk00, Render, Setup, data, capacity, size, emptySlot, growthSize: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSTriShape;
class ImageSpaceEffectParam;
class ImageSpaceManager;

template <class T>
class NiTPrimitiveArray
{
public:
    virtual ~NiTPrimitiveArray();

    T* data;                  // 08
    std::uint16_t capacity;   // 10
    std::uint16_t size;       // 12
    std::uint16_t emptySlot;  // 14
    std::uint16_t growthSize; // 16
};
static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18, "NiTPrimitiveArray size");

class ImageSpaceEffect
{
public:
    virtual ~ImageSpaceEffect();
    virtual void Render(BSTriShape* a_shape, ImageSpaceEffectParam* a_param);
    virtual void Setup(ImageSpaceManager* a_manager, ImageSpaceEffectParam* a_param);
};

class ImageSpaceManager
{
public:
    void SetupEffects();  // compared: 0x14edb20

    std::uint8_t unk00[0x20];                       // 00
    NiTPrimitiveArray<ImageSpaceEffect*> effects;   // 20
};
static_assert(offsetof(ImageSpaceManager, effects) == 0x20, "effects offset");
