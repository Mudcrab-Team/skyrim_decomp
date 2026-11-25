// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x155d830 ShadowmapDescriptor::~ShadowmapDescriptor
// 0x155dc00 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::SetSize
// 0x155d970 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::Clear
// 0x155c750 BSShadowLight::ReleaseShadowmapDescriptor
// 0x155c850 BSShadowLight::SetShadowmapCount
// 0x155c590 BSShadowLight::~BSShadowLight
// 0x155d890 BSShadowLight::`scalar deleting destructor'
// CI hash: 0x155c590 ??1BSShadowLight@@UEAA@XZ
// CI hash: 0x155c750 ?ReleaseShadowmapDescriptor@BSShadowLight@@QEAAXI@Z
// CI hash: 0x155c850 ?SetShadowmapCount@BSShadowLight@@QEAAXI@Z
// CI hash: 0x155d830 ??1ShadowmapDescriptor@@QEAA@XZ
// CI hash: 0x155d890 ??_GBSShadowLight@@UEAAPEAXI@Z
// CI hash: 0x155d970 ?Clear@?$BSTArray@UShadowmapDescriptor@@VBSTArrayHeapAllocator@@@@QEAAX_N@Z
// CI hash: 0x155dc00 ?SetSize@?$BSTArray@UShadowmapDescriptor@@VBSTArrayHeapAllocator@@@@QEAA_NI@Z
#include "BSShadowLight_Pool.h"

// g_freeShadowmapMask: GUESS(low); a bit per shadowmap slot that is free to hand out
extern std::uint32_t g_freeShadowmapMask;

// ShadowmapDescriptor, its constructor, destructor and the array members: CRASHLOGGER_PDB(59818@2026.10.24)
ShadowmapDescriptor::~ShadowmapDescriptor() noexcept
{
}

template bool BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::SetSize(std::uint32_t);
template void BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::Clear(bool);

// ReleaseShadowmapDescriptor, SetShadowmapCount, ~BSShadowLight: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowLight::ReleaseShadowmapDescriptor(std::uint32_t a_index)
{
    if (shadowmapDescriptors[a_index].renderTarget != -1) {
        g_freeShadowmapMask |= 1 << shadowmapDescriptors[a_index].shadowmapIndex;
        shadowmapDescriptors[a_index].renderTarget = -1;
        shadowmapDescriptors[a_index].shaderAccumulator = nullptr;
        shadowmapDescriptors[a_index].camera = nullptr;
        if (shadowmapDescriptors[a_index].cullingProcess != cullingProcess) {
            if (shadowmapDescriptors[a_index].cullingProcess) {
                shadowmapDescriptors[a_index].cullingProcess->Unk_15(1);
            }
            shadowmapDescriptors[a_index].cullingProcess = nullptr;
        }
    }
}

void BSShadowLight::SetShadowmapCount(std::uint32_t a_count)
{
    if (a_count > shadowMapCount) {
        shadowmapDescriptors.SetSize(a_count);
        for (std::uint32_t i = shadowMapCount; i < a_count; ++i) {
            shadowmapDescriptors[i].unkCC = 1.0f;
            shadowmapDescriptors[i].unkE8 = 1;
            shadowmapDescriptors[i].shaderAccumulator = nullptr;
            shadowmapDescriptors[i].cullingProcess = nullptr;
        }
    } else if (a_count < shadowMapCount) {
        for (std::uint32_t i = a_count; i < shadowMapCount - 1; ++i) {
            ReleaseShadowmapDescriptor(i);
        }
        shadowmapDescriptors.SetSize(a_count);
    }
    shadowMapCount = a_count;
}

BSShadowLight::~BSShadowLight()
{
    for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
        ReleaseShadowmapDescriptor(i);
    }
}
