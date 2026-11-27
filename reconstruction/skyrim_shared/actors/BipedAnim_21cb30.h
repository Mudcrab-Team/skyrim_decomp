// Source exposure: mixed (pinned image, cited public declarations, the 2013 map and the FNV sibling).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// BipedAnim, BipedAnim::_refCount, ::root, ::objects, ::bufferedObjects, ::actorRef: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BIPOBJECT, BIPOBJECT::item, ::addon, ::part, ::skinTexture, ::partClone, ::weaponManager: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESModel, TESModel::model, ::textures, ::addons, ::numTextures, ::numAddons: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BIPED_OBJECT, BIPED_OBJECT::kHead, BIPED_OBJECT::kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BipedAnim::IsFaceGenObject: SYMBOLS(tesv-2013-map)
// TESModel::flags, TESModel::kFaceGenModel: GUESS(low); the pinned code tests bit 0 of the byte after numAddons
// TESForm, TESObjectARMA, BGSTextureSet, NiAVObject, NiNode, WeaponAnimationGraphManagerHolder: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include <cstdint>

class TESForm;
class TESObjectARMA;
class BGSTextureSet;
class NiAVObject;
class NiNode;
class WeaponAnimationGraphManagerHolder;

enum BIPED_OBJECT
{
    kHead = 0,
    kTotal = 42
};

class TESModel
{
public:
    enum : std::uint8_t
    {
        kFaceGenModel = 1 << 0
    };

    virtual ~TESModel();

    const char*    model;        // 08 - BSFixedString
    void*          textures;     // 10 - BSResource::ID*
    std::uint32_t* addons;       // 18
    std::uint16_t  numTextures;  // 20
    std::uint8_t   numAddons;    // 22 - CommonLib declares 16 bits; narrowed because the pinned code reads byte 23 alone
    std::uint8_t   flags;        // 23 - single-byte bit test in the pinned code
};
static_assert(offsetof(TESModel, flags) == 0x23, "flags byte differs from the pinned access");
static_assert(sizeof(TESModel) == 0x28, "layout differs from CommonLibSSE-NG");

struct BIPOBJECT
{
    TESForm*                           item;           // 00
    TESObjectARMA*                     addon;          // 08
    TESModel*                          part;           // 10
    BGSTextureSet*                     skinTexture;    // 18
    NiAVObject*                        partClone;      // 20 - NiPointer<NiAVObject>
    std::uint64_t                      unk28;          // 28
    std::uint64_t                      unk30;          // 30
    std::uint64_t                      unk38;          // 38
    std::uint64_t                      unk40;          // 40
    std::uint64_t                      unk48;          // 48
    std::uint64_t                      unk50;          // 50
    std::uint64_t                      unk58;          // 58
    WeaponAnimationGraphManagerHolder* weaponManager;  // 60 - BSTSmartPointer
    std::uint64_t                      unk68;          // 68
    void*                              unk70;          // 70
};
static_assert(offsetof(BIPOBJECT, part) == 0x10, "layout differs from CommonLibSSE-NG");
static_assert(sizeof(BIPOBJECT) == 0x78, "layout differs from CommonLibSSE-NG");

class BipedAnim
{
public:
    bool IsFaceGenObject(BIPED_OBJECT a_slot);

    std::uint32_t _refCount;                 // 0000 - BSIntrusiveRefCounted
    NiNode*       root;                      // 0008
    BIPOBJECT     objects[kTotal];           // 0010
    BIPOBJECT     bufferedObjects[kTotal];   // 13C0
    std::uint32_t actorRef;                  // 2770 - ObjectRefHandle
};
static_assert(offsetof(BipedAnim, objects) == 0x10, "layout differs from CommonLibSSE-NG");
static_assert(offsetof(BipedAnim, bufferedObjects) == 0x13C0, "layout differs from CommonLibSSE-NG");
static_assert(sizeof(BipedAnim) == 0x2778, "layout differs from CommonLibSSE-NG");
