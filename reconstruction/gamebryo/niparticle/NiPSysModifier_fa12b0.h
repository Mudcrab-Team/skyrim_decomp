// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial layouts follow the pinned field accesses and cited declarations.
// NiRefObject, NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::~NiRefObject, NiRefObject::DeleteThis, NiRefObject::_refCount, NiObject::~NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::NiObject: OBSERVED
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString::_data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ORDER: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG wraps it in stl::enumeration<ORDER, std::uint32_t>
// NiPSysModifier: EXE_RTTI
// NiPSysModifier::name, NiPSysModifier::order, NiPSysModifier::target, NiPSysModifier::active, NiPSysModifier::~NiPSysModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifier::NiPSysModifier: OBSERVED
#pragma once

#include <cstdint>

class NiParticleSystem;

// Only the slots and members this unit needs; the NiObject constructor is out of line, as the image calls it.
class NiRefObject
{
public:
    virtual ~NiRefObject();     // 00
    virtual void DeleteThis();  // 01

    std::uint32_t _refCount;  // 08
};

class NiObject : public NiRefObject
{
public:
    NiObject();
    ~NiObject() override;
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

// An interned string, compared by pointer.
class BSFixedString
{
public:
    const char* _data;  // 00
};

enum class ORDER : std::uint32_t
{
    kKillOldParticles = 0,
    kBSLOD = 1,
    kEmitter = 1000,
    kSpawn = 2000,
    kGeneral = 3000,
    kForce = 4000,
    kCollider = 5000,
    kPosUpdate = 6000,
    kPostPosUpdate = 6500,
    kBoundUpdate = 7000,
    kBSStripUpdate = 8000
};

class NiPSysModifier : public NiObject
{
public:
    NiPSysModifier();
    ~NiPSysModifier() override;

    BSFixedString     name;      // 10
    ORDER             order;     // 18
    NiParticleSystem* target;    // 20
    bool              active;    // 28
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");
