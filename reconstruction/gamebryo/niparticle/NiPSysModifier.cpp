// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings and
// decompiler output of the pinned image, with types from the header beside this file.
// Code origin: original reconstruction from binary analysis; the Sibling source lines below name where a body parallels an admitted sibling.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:53
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:86
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:42
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:52 (LinkObject, CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:41 (ProcessClone, CC0-1.0)
// 0xfa11c0 NiPSysModifier::SetSystemPointer
// 0xfa1010 NiPSysModifier::LinkObject
// 0xfa1040 NiPSysModifier::RegisterStreamables
// 0xfa1140 NiPSysModifier::IsEqual
// 0xfa1090 NiPSysModifier::SaveBinary
// 0xfa0f40 NiPSysModifier::LoadBinary
// 0xfa11d0 NiPSysModifier::ProcessClone
// 0xfa1360 NiPSysModifier::Functionfa1360
// CI hash: 0xfa1360 ?Functionfa1360@@YAXPEAVCtorFa1360@@@Z
#include "NiPSysModifier.h"

#include <intrin.h>
#include <cstdint>
#include <new>

// CtorFa1360, MemberFa, typeFaA, typeFaB, refCountFa: GUESS(low) STANDIN
extern "C" char typeFaA;
extern "C" char typeFaB;
volatile long refCountFa;
class MemberFa { public: MemberFa(); };
class CtorFa1360
{
public:
    CtorFa1360();
    void* field00;  // 00
    std::uint64_t pad08;  // 08
    MemberFa member10;  // 10
};

CtorFa1360::CtorFa1360() : field00(&typeFaA), member10()
{
    field00 = &typeFaB;
    // Release the local reference count after the comparison object is detached.
    _InterlockedDecrement(&refCountFa);
}

void Functionfa1360(CtorFa1360* a_object)
{
    new (a_object) CtorFa1360();
}

void NiPSysModifier::SetSystemPointer(NiParticleSystem* a_target)
{
    target = a_target;
}

void NiPSysModifier::Initialize(NiPSysData*, std::uint16_t, NiPoint3*)
{
}

void NiPSysModifier::HandleReset()
{
}

void NiPSysModifier::SetActive(bool a_active)
{
    active = a_active;
}

void NiPSysModifier::LinkObject(NiStream& a_stream)
{
    NiObject::LinkObject(a_stream);
    // the linked object is resolved later by the stream; the result is not kept here
    a_stream.ReadLinkID();
}

bool NiPSysModifier::RegisterStreamables(NiStream& a_stream)
{
    if (!NiObject::RegisterStreamables(a_stream)) {
        return false;
    }
    a_stream.RegisterFixedString(name);
    return true;
}

bool NiPSysModifier::IsEqual(NiObject* a_object)
{
    if (!NiObject::IsEqual(a_object)) {
        return false;
    }
    auto other = static_cast<NiPSysModifier*>(a_object);
    return name == other->name && order == other->order && active == other->active;
}

void NiPSysModifier::SaveBinary(NiStream& a_stream)
{
    NiObject::SaveBinary(a_stream);
    a_stream.SaveFixedString(name);
    a_stream.oStr->write(&order, 1);
    a_stream.SaveLinkID(reinterpret_cast<NiObject*>(target));
    a_stream.oStr->put(active);
}

void NiPSysModifier::LoadBinary(NiStream& a_stream)
{
    NiObject::LoadBinary(a_stream);
    if (a_stream.nifMaxVersion < 0x14010001) {
        a_stream.LoadFixedStringLegacy(name);
    } else {
        a_stream.LoadFixedString(name);
    }
    a_stream.iStr->read(&order, 1);
    a_stream.LoadLinkID();
    char isActive;
    a_stream.iStr->read(&isActive, 1);
    active = isActive != 0;
}

void NiPSysModifier::ProcessClone(NiCloningProcess& a_cloning)
{
    NiObject::ProcessClone(a_cloning);
    NiObject* found = nullptr;
    a_cloning.cloneMap.find(this, found);
    auto clone = static_cast<NiPSysModifier*>(found);
    a_cloning.cloneMap.find(reinterpret_cast<NiObject*>(target), found);
    clone->SetSystemPointer(reinterpret_cast<NiParticleSystem*>(found));
}
