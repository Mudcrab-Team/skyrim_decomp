// Source exposure: mixed
// Code origin: original; local target observations and community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// UI3DSceneManager, NiPoint3, NiMatrix3, NiTransform, NiUpdateData, NiAVObject, NiCamera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; minimal accessed fields.
// UI3DSceneManager::SetCameraPosition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include <cstddef>

class NiPoint3 { public: float x, y, z; };
class NiMatrix3 { public: float entry[3][3]; };
class NiTransform { public: NiMatrix3 rotate; NiPoint3 translate; float scale; };
class NiUpdateData { public: NiUpdateData(float a_time, std::uint32_t a_flags) : time(a_time), flags(a_flags) {} float time; std::uint32_t flags; };
class NiAVObject
{
public:
    void Update(NiUpdateData& data);
    std::uint8_t unknown00[0x48];
    NiTransform local;
};
class NiCamera : public NiAVObject {};
class UI3DSceneManager
{
public:
    void SetCameraPosition(const NiPoint3& position);
    std::uint8_t unknown00[0x20];
    NiCamera* camera;
};
static_assert(offsetof(UI3DSceneManager, camera) == 0x20, "camera offset");
static_assert(offsetof(NiAVObject, local) + offsetof(NiTransform, translate) == 0x6c, "translation offset");
