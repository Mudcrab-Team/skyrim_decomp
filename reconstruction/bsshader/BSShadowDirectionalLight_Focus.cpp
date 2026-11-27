// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x155d110 BSShadowDirectionalLight::SetupFocusShadowAccumulators
// CI hash: 0x155d110 ?SetupFocusShadowAccumulators@BSShadowDirectionalLight@@QEAAXXZ
#include "BSShadowDirectionalLight_Focus.h"

// g_focusShadowmapCount, g_focusEntries, g_accumulatorMask: GUESS(low); the number of focus descriptors, a table of 16-byte entries (scene root at 08) per descriptor and a shared value every accumulator keeps
struct FocusEntry
{
    std::uint64_t unknown00;
    NiAVObject* root;  // 08
};
extern std::uint32_t g_focusShadowmapCount;
extern FocusEntry* g_focusEntries;
extern const void* g_accumulatorMask;

// SetupFocusShadowAccumulators: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowDirectionalLight::SetupFocusShadowAccumulators()
{
    for (std::uint32_t i = 0; i < g_focusShadowmapCount; ++i) {
        ShadowmapDescriptor* descriptor = &focusShadowmapDescriptors[i];
        descriptor->unkE9 = 1;
        if (!descriptor->shaderAccumulator) {
            descriptor->shaderAccumulator = new BSShaderAccumulator(0x63);
            descriptor->shaderAccumulator->unk150 = 0xE;
            descriptor->shaderAccumulator->unk12C = false;
            descriptor->shaderAccumulator->unk12D = true;
        }
        descriptor->shaderAccumulator->unk148 = g_accumulatorMask;
        if (descriptor->shaderAccumulator) {
            descriptor->shaderAccumulator->AccumulateSceneGraph(g_focusEntries[i].root, false);
        }
    }
}
