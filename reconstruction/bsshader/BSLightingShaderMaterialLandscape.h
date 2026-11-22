// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialLandscape::GetFeature, BSLightingShaderMaterialLandscape::~BSLightingShaderMaterialLandscape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownA0: GUESS(low)
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
#pragma once

#include <cstdint>
#include <cstddef>
#include "BSLightingShaderMaterialBase.h"

// MemoryManager: STANDIN GUESS(low); the allocator object the image reads at 0x369a810, with its once-init guard at 0x369ac98
class MemoryManager
{
public:
    void* Allocate(std::uint32_t a_size, std::int32_t a_alignment, bool a_alignmentRequired);  // 0xcde250
};
// g_memoryManager, g_memoryManagerGuard, InitMemoryManager: GUESS(low)
extern MemoryManager g_memoryManager;
extern std::int32_t  g_memoryManagerGuard;
void InitMemoryManager(MemoryManager* a_manager, std::int32_t* a_guard);  // 0xcde810

class BSLightingShaderMaterialLandscape : public BSLightingShaderMaterialBase
{
public:
    static void* operator new(std::size_t a_size) throw();
    BSShaderMaterial* Create() override;  // compared: 0x1527560
    // the image's Create calls the constructor at its own address, so it stays a separate function
    __declspec(noinline) BSLightingShaderMaterialLandscape();
    std::uint32_t GetTextures(NiSourceTexture** a_textures);  // compared: 0x15279b0
    virtual Feature GetFeature() const;  // compared: 0x1527a80
    virtual ~BSLightingShaderMaterialLandscape();  // compared: 0x1529030 (scalar deleting destructor)

    // LandscapeLayers: GUESS(low); layout read by GetTextures: a count, two parallel arrays of five textures, two trailing textures
    std::uint32_t              layerCount;     // A0
    std::uint32_t              padA4;          // A4
    NiSourceTexture*           diffuse[5];     // A8
    NiSourceTexture*           normal[5];      // D0
    NiSourceTexture*           extraF8;        // F8
    NiSourceTexture*           extra100;       // 100
    std::uint8_t               unknown108[0x50];  // 108
};
static_assert(sizeof(BSLightingShaderMaterialLandscape) == 0x158, "BSLightingShaderMaterialLandscape size");
