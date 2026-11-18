// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings and
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:53
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:86
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp:42
// 0xfa11c0 NiPSysModifier::SetSystemPointer
// 0xfa1010 NiPSysModifier::LinkObject
// 0xfa1040 NiPSysModifier::RegisterStreamables
// 0xfa1140 NiPSysModifier::IsEqual
// 0xfa1090 NiPSysModifier::SaveBinary
// 0xfa0f40 NiPSysModifier::LoadBinary
// 0xfa11d0 NiPSysModifier::ProcessClone
#include "NiPSysModifier.h"

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
