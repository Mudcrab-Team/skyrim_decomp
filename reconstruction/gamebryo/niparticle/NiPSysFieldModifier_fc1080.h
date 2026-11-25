// Source exposure: mixed (community declarations; pinned-image observations; sibling symbol facts).
// Code origin: original stand-in declarations with labelled names
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiPSysModifier, NiObject::IsEqual, NiPSysModifier::IsEqual: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysFieldModifier, NiPSysFieldModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// m_pkFieldObj, m_fMagnitude, m_fAttenuation, m_bUseMaxDistance, m_fMaxDistance: SYMBOLS(fo4-pdb)
// Slot00 through Slot1B, unknown08, unknown41, field offsets: STANDIN OBSERVED
#pragma once
#include <cstdint>
class NiObject {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual bool IsEqual(NiObject* object);
};
class NiPSysModifier : public NiObject {
public:
    bool IsEqual(NiObject* object) override;
    std::uint8_t unknown08[0x28];
};
class NiPSysFieldModifier : public NiPSysModifier {
public:
    bool IsEqual(NiObject* object) override;
    NiObject* m_pkFieldObj;
    float m_fMagnitude;
    float m_fAttenuation;
    bool m_bUseMaxDistance;
    std::uint8_t unknown41[3];
    float m_fMaxDistance;
};
