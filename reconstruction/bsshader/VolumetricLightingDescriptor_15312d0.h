// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// VolumetricLightingDescriptor, VolumetricLightingDescriptor::Render, RenderTargetManager: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderMgr3331F40, RenderSub, RenderResource, VolumetricLightingConstants, VolumetricLightingSliceParams, ComputeDispatch, Function100abb0..g_sliceParams3435f30: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct RenderSub
{
    std::uint8_t unk00[0x08];
    std::uint8_t unk08;
    std::uint8_t unk09[0x0F];
    std::uint8_t unk18;
    std::uint8_t unk19[0x27];
    std::uint8_t unk40;
};

struct RenderSub1B8
{
    void Function15416a0(void* a_tex, std::uint32_t a_a, std::uint32_t a_b, std::uint32_t a_c);
};

struct RenderSingleton
{
    std::uint8_t unk000[0x170];
    RenderSub* unk170;    // 170
    std::uint8_t unk178[0x10];
    RenderSub* unk188;    // 188
    RenderSub* unk190;    // 190
    std::uint8_t unk198[0x20];
    RenderSub1B8* unk1B8; // 1B8
};

struct ComputeDispatch
{
    virtual void VFunc00();
    virtual void VFunc08();
    virtual void Dispatch(std::uint32_t a_a, std::uint32_t a_b, std::uint32_t a_c, std::uint32_t a_d);  // +0x10
};

struct RenderTargetManager
{
    void Function1015670(std::int32_t a_a, std::int32_t a_b, std::int32_t a_c, bool a_d);
};

struct RenderMgr3331F40
{
    void Function100abb0(std::int32_t a_a, const void* a_b, std::uint32_t a_c, std::uint32_t a_d, std::uint32_t a_e, std::int32_t a_f, std::int32_t a_g);
    void Function100f6e0(std::int32_t a_idx, void* a_obj);
    void Function100f8b0(std::int32_t a_a, std::int32_t a_b);
    void Function100f850(std::int32_t a_a, std::int32_t a_b, std::int32_t a_c);
    void Function100f760(std::int32_t a_idx, void* a_obj);
    void Function100f7a0(std::int32_t a_idx, void* a_obj);
    void Function1010570(void* a_ptr, std::int32_t a_size);
    void Function100f720(std::int32_t a_a, std::int32_t a_b);
    void Function100f660(std::int32_t a_a, std::int32_t a_b);
};

void Function1010de0(bool a_flag);

class VolumetricLightingDescriptor
{
public:
    void Render(void* a_arg2, bool a_flag);  // compared: 0x15312d0
    void Function1532730(void* a_a, void* a_b);
    void Function1531b30(void* a_arg2);

    float flt00[12];            // 00..2C
    std::uint32_t unk30;        // 30
    std::uint32_t unk34;        // 34
    std::uint32_t unk38;        // 38
    std::uint32_t unk3C;        // 3C
    void* unk40;                // 40
    void* unk48;                // 48
    ComputeDispatch* unk50;     // 50
    ComputeDispatch* unk58;     // 58
    void* unk60;                // 60
    void* unk68;                // 68
    void* unk70;                // 70
    void* unk78;                // 78
    void* unk80;                // 80
};
static_assert(offsetof(VolumetricLightingDescriptor, unk30) == 0x30, "unk30 offset");
static_assert(offsetof(VolumetricLightingDescriptor, unk60) == 0x60, "unk60 offset");
static_assert(offsetof(VolumetricLightingDescriptor, unk80) == 0x80, "unk80 offset");

struct RenderResource;

struct VolumetricLightingConstants
{
    std::uint8_t unk00[0x180];
};
static_assert(sizeof(VolumetricLightingConstants) == 0x180, "VolumetricLightingConstants size");

struct VolumetricLightingSliceParams
{
    std::uint8_t unk00[0x10];  // 00
    std::uint32_t sliceIndex;  // 10
};
static_assert(sizeof(VolumetricLightingSliceParams) == 0x14, "VolumetricLightingSliceParams size");
static_assert(offsetof(VolumetricLightingSliceParams, sliceIndex) == 0x10, "sliceIndex offset");

extern std::uint8_t g_byte20d7128;
extern std::uint8_t g_byte343635e;
extern std::uint8_t g_byte3435f45;
extern RenderSingleton* g_renderSingleton33d40a0;
extern std::uint32_t g_dword20d7080;
extern std::uint32_t g_dword20d7098;
extern std::uint32_t g_dword20d70b0;
extern std::uint8_t g_arr1b42a80[];
extern RenderMgr3331F40 g_renderer3331f40;
extern RenderTargetManager g_rtManager3335600;
extern RenderResource g_obj33346f8;
extern RenderResource g_obj33346b8;
extern RenderResource g_obj33346d8;
extern VolumetricLightingConstants g_constants3435db0;
extern VolumetricLightingSliceParams g_sliceParams3435f30;
extern float g_flt33d3ea8[12];
