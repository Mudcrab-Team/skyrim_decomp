// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempEffectSimpleDecal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSTempEffectSimpleDecal::Get3D, BSTempEffectSimpleDecal::Initialize, BSTempEffectSimpleDecal::~BSTempEffectSimpleDecal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// effect3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares NiPointer<BSGeometry>,
// kept as a raw NiAVObject pointer because Get3D returns it unchanged
// avShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares NiPointer<BSTriShape>,
// kept as a raw pointer because the helper takes it by value
// SetupAVShape: GUESS(low); the helper at 0x4b10e0 takes the shape, returns a flag, and is called from Initialize
// unknown30, unknown50, unknown180: GUESS(low); padding around the members the bodies read
#pragma once

#include <cstdint>
#include "BSTempEffect.h"

class BSTriShape;

class BSTempEffectSimpleDecal : public BSTempEffect
{
public:
    BSTempEffectSimpleDecal(TESObjectCELL* a_cell, float a_lifetime);
    virtual NiAVObject* Get3D() const;  // compared: 0x4b2950
    virtual void Initialize();  // compared: 0x4b1090
    virtual ~BSTempEffectSimpleDecal();  // compared: 0x4b4a40 (scalar deleting destructor; declared, not defined)

    // Callee of Initialize (RVA 0x4b10e0); bound by hint, not defined here.
    bool SetupAVShape(BSTriShape* a_shape);

    std::uint8_t unknown30[0x18];  // 30
    NiAVObject* effect3D;  // 48
    std::uint8_t unknown50[0x128];  // 50
    BSTriShape* avShape;  // 178
    std::uint8_t unknown180[0x60];  // 180
};
static_assert(sizeof(BSTempEffectSimpleDecal) == 0x1E0, "BSTempEffectSimpleDecal size");
