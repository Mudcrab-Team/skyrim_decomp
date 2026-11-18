// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x152d190 BSWaterShaderProperty::DoClearRenderPasses
// 0x152c410 BSWaterShaderProperty::SaveBinary
// 0x152c370 BSWaterShaderProperty::LinkObject
// 0x152cd00 BSWaterShaderProperty::Unk_2C
#include "BSWaterShaderProperty.h"

// RVA 0x152d190, 62 bytes
void BSWaterShaderProperty::DoClearRenderPasses()
{
    ReleaseWaterEntry(&unkC8);
    if (unkC0 != nullptr) {
        unkC0->ClearRenderPass();
        unkC0 = nullptr;
    }
    BSShaderProperty::DoClearRenderPasses();
}

// RVA 0x152c410, 82 bytes
void BSWaterShaderProperty::SaveBinary(NiStream& a_stream)
{
    BSShaderProperty::SaveBinary(a_stream);
    std::uint32_t componentSize = sizeof(waterFlags);
    a_stream.oStr->binary_write(&waterFlags, sizeof(waterFlags), &componentSize, 1);
}

// RVA 0x152c370, 123 bytes
void BSWaterShaderProperty::LinkObject(NiStream& a_stream)
{
    BaseLinkObject(a_stream);
    BSShaderMaterial* previous = material;
    material = nullptr;
    BSShaderProperty::SetMaterial(previous, false);
    if (previous != nullptr) {
        previous->~BSShaderMaterial();
        if (g_scrapHeapInitState != 2) {
            InitScrapHeapGuard(&g_memoryManager, &g_scrapHeapInitState);
        }
        g_memoryManager.GetThreadScrapHeap(0)->Deallocate(previous);
    }
}


// Retained generated leaf; its byte-match evidence is renewed with this unit.
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t BSWaterShaderProperty::QShader() const
{
    return 0x11;
}
