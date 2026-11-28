// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// UI3DSceneManager, UI3DSceneManager::SetCameraRotate_1408d3990: CRASHLOGGER_PDB(59818@2026.10.24)
// NiMatrix3, NiUpdateData, NiCamera98b180, Update, localRotate, camera, time, flags: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiMatrix3
{
    float entry[3][3];  // 00
};
static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 size");

struct NiUpdateData
{
    float         time;   // 00
    std::uint32_t flags;  // 04
};
static_assert(sizeof(NiUpdateData) == 0x08, "NiUpdateData size");

class NiCamera98b180
{
public:
    void Update(NiUpdateData& a_data);

    std::uint8_t unk00[0x48];  // 00
    NiMatrix3    localRotate;  // 48
};
static_assert(offsetof(NiCamera98b180, localRotate) == 0x48, "localRotate offset");

class UI3DSceneManager
{
public:
    void SetCameraRotate_1408d3990(const NiMatrix3& a_rotate);  // compared: 0x98b180

    std::uint8_t    unk00[0x20];  // 00
    NiCamera98b180* camera;       // 20
};
static_assert(offsetof(UI3DSceneManager, camera) == 0x20, "camera offset");
