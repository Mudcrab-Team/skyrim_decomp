// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// TweenMenuCameraState, TweenMenuCameraState::ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// NiQuaternion, NiPoint2, TESCamera, BSIntrusiveRefCounted8ff2a0, TESCameraState8ff2a0, gIdentityQuat, gZeroPoint2, refCount, camera, id, initialRotation, unk30, currentRotation, targetRotation, unk44, unk48, unk4C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESCamera;

struct NiQuaternion
{
    float w;  // 00
    float x;  // 04
    float y;  // 08
    float z;  // 0C
};
static_assert(sizeof(NiQuaternion) == 0x10, "NiQuaternion size");

struct NiPoint2
{
    NiPoint2(const NiPoint2& a_rhs) : x(a_rhs.x), y(a_rhs.y) {}

    float x;  // 00
    float y;  // 04
};
static_assert(sizeof(NiPoint2) == 0x08, "NiPoint2 size");

extern const NiQuaternion gIdentityQuat;
extern const NiPoint2 gZeroPoint2;

class BSIntrusiveRefCounted8ff2a0
{
public:
    BSIntrusiveRefCounted8ff2a0() : refCount(0) {}

    std::uint32_t refCount;  // 00 (08 in TESCameraState8ff2a0)
};

class TESCameraState8ff2a0 : public BSIntrusiveRefCounted8ff2a0
{
public:
    TESCameraState8ff2a0(TESCamera* a_camera, std::uint32_t a_id) :
        BSIntrusiveRefCounted8ff2a0(),
        camera(a_camera),
        id(a_id)
    {
    }

    virtual ~TESCameraState8ff2a0();

    TESCamera*    camera;    // 10
    std::uint32_t id;        // 18
};
static_assert(sizeof(TESCameraState8ff2a0) == 0x20, "TESCameraState8ff2a0 size");

class TweenMenuCameraState : public TESCameraState8ff2a0
{
public:
    TweenMenuCameraState(TESCamera* a_camera, std::uint32_t a_id);  // compared: 0x8ff2a0

    NiQuaternion  initialRotation;  // 20
    std::uint32_t unk30;            // 30
    NiPoint2      currentRotation;  // 34
    NiPoint2      targetRotation;   // 3C
    std::uint32_t unk44;            // 44
    std::uint32_t unk48;            // 48
    bool          unk4C;            // 4C
};
static_assert(offsetof(TweenMenuCameraState, initialRotation) == 0x20, "initialRotation offset");
static_assert(offsetof(TweenMenuCameraState, currentRotation) == 0x34, "currentRotation offset");
static_assert(offsetof(TweenMenuCameraState, unk4C) == 0x4C, "unk4C offset");
