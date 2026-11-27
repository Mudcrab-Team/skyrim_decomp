// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x15312d0 VolumetricLightingDescriptor::Render
// Adapted bodies: none
#include "VolumetricLightingDescriptor_15312d0.h"

void VolumetricLightingDescriptor::Render(void* a_arg2, bool a_flag)
{
    bool skip = (a_flag && g_byte20d7128) || g_byte343635e;
    std::uint8_t inv = !skip;
    g_renderSingleton33d40a0->unk170->unk08 = inv;
    g_renderSingleton33d40a0->unk188->unk40 = inv;

    if (!unk60) {
        g_renderer3331f40.Function100abb0(2, g_arr1b42a80, g_dword20d7080, g_dword20d7098, g_dword20d70b0, 0, 0x3D);
        unk60 = &g_obj33346f8;
        g_renderSingleton33d40a0->unk1B8->Function15416a0(unk60, g_dword20d7080, g_dword20d7098, g_dword20d70b0);
    }

    if (skip) {
        return;
    }

    g_renderSingleton33d40a0->unk190->unk18 = 1;
    if (g_byte3435f45) {
        float prev2C = flt00[11];
        flt00[0] = g_flt33d3ea8[0];
        flt00[1] = g_flt33d3ea8[1];
        flt00[2] = g_flt33d3ea8[2];
        flt00[3] = g_flt33d3ea8[3];
        flt00[4] = g_flt33d3ea8[4];
        flt00[5] = g_flt33d3ea8[5];
        flt00[6] = g_flt33d3ea8[6];
        flt00[7] = g_flt33d3ea8[7];
        flt00[8] = g_flt33d3ea8[8];
        flt00[9] = g_flt33d3ea8[9];
        flt00[10] = g_flt33d3ea8[10];
        flt00[11] = g_flt33d3ea8[11];
        if (!(prev2C == g_flt33d3ea8[11])) {
            Function1532730(unk40, unk78);
            Function1532730(unk48, unk80);
        }
    }

    g_rtManager3335600.Function1015670(-1, 3, 0, false);
    Function1531b30(a_arg2);

    unk68 = &g_obj33346b8;
    g_renderer3331f40.Function100f6e0(0, unk68);
    unk70 = &g_obj33346d8;
    g_renderer3331f40.Function100f6e0(1, unk70);
    g_renderer3331f40.Function100f8b0(0, 2);
    g_renderer3331f40.Function100f8b0(1, 3);
    g_renderer3331f40.Function100f850(0, 0, 0);
    g_renderer3331f40.Function100f850(1, 0, 1);
    g_renderer3331f40.Function100f760(2, unk80);
    g_renderer3331f40.Function100f850(2, 0, 1);
    g_renderer3331f40.Function100f7a0(3, unk60);
    g_renderer3331f40.Function100f850(3, 5, 1);
    g_renderer3331f40.Function1010570(&g_constants3435db0, static_cast<std::int32_t>(sizeof(g_constants3435db0)));
    unk50->Dispatch(0, unk30 >> 5, unk34 >> 5, unk38);
    g_renderer3331f40.Function100f720(0, 0);
    g_renderer3331f40.Function100f720(1, 0);
    g_renderer3331f40.Function100f720(2, 0);
    g_renderer3331f40.Function100f720(3, 0);
    g_renderer3331f40.Function100f660(1, 0);
    g_renderer3331f40.Function100f850(0, 0, 0);
    Function1010de0(true);

    for (std::uint32_t i = 1; i < unk38; i += 2) {
        g_sliceParams3435f30.sliceIndex = i;
        g_renderer3331f40.Function1010570(&g_sliceParams3435f30, static_cast<std::int32_t>(sizeof(g_sliceParams3435f30)));
        g_renderer3331f40.Function100f6e0(0, unk70);
        g_renderer3331f40.Function100f7a0(0, unk68);
        unk58->Dispatch(0, unk30 >> 5, unk34 >> 5, 1);
        g_renderer3331f40.Function100f720(0, 0);
        Function1010de0(true);

        g_sliceParams3435f30.sliceIndex = i + 1;
        g_renderer3331f40.Function1010570(&g_sliceParams3435f30, static_cast<std::int32_t>(sizeof(g_sliceParams3435f30)));
        g_renderer3331f40.Function100f7a0(0, unk70);
        g_renderer3331f40.Function100f6e0(0, unk68);
        unk58->Dispatch(0, unk30 >> 5, unk34 >> 5, 1);
        g_renderer3331f40.Function100f720(0, 0);
        Function1010de0(true);
    }

    g_renderer3331f40.Function100f660(0, 0);
}
