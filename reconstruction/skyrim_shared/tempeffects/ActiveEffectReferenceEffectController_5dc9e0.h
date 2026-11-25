// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0x5dc660 compared function
// Code origin: original reconstruction from binary analysis; no external implementation code copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffectReferenceEffectController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// ReferenceEffectController: STANDIN EXE_RTTI
// ActiveEffectReferenceEffectController::GetElapsedTime, ActiveEffectReferenceEffectController::GetNoInitialFlare, ActiveEffectReferenceEffectController::GetSourcePosition, ActiveEffectReferenceEffectController::GetEffectPersists, ActiveEffectReferenceEffectController::GetGoryVisuals, ActiveEffectReferenceEffectController::GetHitEffectShader, ActiveEffectReferenceEffectController::GetHitEffectArt: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3, TESEffectShader, BGSArtObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); three floats only
// ActiveEffectReferenceEffectController::SetTarget: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// ReferenceEffectController::~ReferenceEffectController, unknown08: GUESS(low)
// ActiveEffectOwner, ActiveEffectSourceNode, ReferenceEffectRefData, ReferenceTarget: GUESS(low)
// ActiveEffectOwner::source, ActiveEffectOwner::elapsed, ActiveEffectOwner::flags, ReferenceEffectRefData::flags, ReferenceTarget::flags: GUESS(low)
// ActiveEffectSourceNode::position: GUESS(low)
// ActiveEffectReferenceEffectController::owner, ActiveEffectReferenceEffectController::targetHandle: GUESS(low)
// GetEffectRefData, GetEffectArtForRef, GetEffectShaderForRef: GUESS(low)
// TestBit: GUESS(low)
// ActiveEffectReferenceEffectController::EffectShouldFaceTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// ActiveEffectOwner::target: GUESS(low); the effect's target pointer at 0x50, NG has it as ActiveEffect::target
// ReferenceEffectRefData::art, EffectArtData, EffectArtData::flags: GUESS(low); pointer at 0x120 and its flag byte at 0x30
#pragma once

#include <cstdint>
#include <cstddef>

class TESEffectShader;
class BGSArtObject;

class NiPoint3
{
public:
    float x;
    float y;
    float z;
};
static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 size");

class ReferenceEffectController
{
public:
    virtual ~ReferenceEffectController() = default;
};
static_assert(sizeof(ReferenceEffectController) == 0x8, "ReferenceEffectController size");

// Object at owner+0x38 in the controller's owner; GetSourcePosition returns a reference into it.
class ActiveEffectSourceNode
{
public:
    std::uint8_t unknown00[0xA0];
    NiPoint3 position;  // 0xA0
};
static_assert(offsetof(ActiveEffectSourceNode, position) == 0xA0, "ActiveEffectSourceNode::position offset");

// The object at controller+0x08.
class ActiveEffectOwner
{
public:
    std::uint8_t unknown00[0x38];
    ActiveEffectSourceNode* source;  // 0x38
    std::uint8_t unknown40[0x10];
    void* target;  // 0x50
    std::uint8_t unknown58[0x18];
    float elapsed;  // 0x70
    std::uint8_t unknown74[0x8];
    std::uint32_t flags;  // 0x7C
};
static_assert(offsetof(ActiveEffectOwner, target) == 0x50, "ActiveEffectOwner::target offset");
static_assert(offsetof(ActiveEffectOwner, elapsed) == 0x70, "ActiveEffectOwner::elapsed offset");
static_assert(offsetof(ActiveEffectOwner, flags) == 0x7C, "ActiveEffectOwner::flags offset");

class EffectArtData
{
public:
    std::uint8_t unknown00[0x30];
    std::uint8_t flags;  // 0x30
};

// The object returned by GetEffectRefData.
class ReferenceEffectRefData
{
public:
    std::uint8_t unknown00[0x68];
    std::uint32_t flags;  // 0x68
    std::uint8_t unknown6C[0xB4];
    EffectArtData* art;  // 0x120
};
static_assert(offsetof(ReferenceEffectRefData, flags) == 0x68, "ReferenceEffectRefData::flags offset");
static_assert(offsetof(ReferenceEffectRefData, art) == 0x120, "ReferenceEffectRefData::art offset");

// The object SetTarget receives; only its flags word is read.
class ReferenceTarget
{
public:
    std::uint8_t unknown00[0x28];
    std::uint32_t flags;  // 0x28
};
static_assert(offsetof(ReferenceTarget, flags) == 0x28, "ReferenceTarget::flags offset");

class TESEffectShader;

class ActiveEffectReferenceEffectController : public ReferenceEffectController
{
public:
    virtual float GetElapsedTime();  // compared: 0x5dc6d0
    virtual bool GetNoInitialFlare();  // compared: 0x5dc7f0
    virtual const NiPoint3& GetSourcePosition();  // compared: 0x5dc760
    virtual bool GetEffectPersists();  // compared: 0x5dc810
    virtual bool GetGoryVisuals();  // compared: 0x5dc830
    virtual TESEffectShader* GetHitEffectShader();  // compared: 0x5dc990
    virtual BGSArtObject* GetHitEffectArt();  // compared: 0x5dc950
    virtual bool EffectShouldFaceTarget();  // compared: 0x5dc9e0
    void SetTarget(ReferenceTarget* a_target);  // compared: 0x5dc660

    ActiveEffectOwner* owner;  // 0x08
    std::uint32_t targetHandle;  // 0x10
    std::uint8_t unknown14[0xC];  // 0x14
};
static_assert(sizeof(ActiveEffectReferenceEffectController) == 0x20, "ActiveEffectReferenceEffectController size");

// Declared, not defined: the target calls these, and attempt binds them by hint.
ReferenceEffectRefData* GetEffectRefData(ActiveEffectOwner* a_owner);
BGSArtObject* GetEffectArtForRef(ReferenceEffectRefData* a_ref, bool a_flag);
TESEffectShader* GetEffectShaderForRef(ReferenceEffectRefData* a_ref, bool a_flag);
void CreateRefHandle(std::uint32_t* a_out, ReferenceTarget* a_target);
// RefHandleStandIn: GUESS(low); eight-byte stand-in for the handle slot
extern std::uint32_t gNullHandle;

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit) { return ((a_flags >> a_bit) & 1) != 0; }
