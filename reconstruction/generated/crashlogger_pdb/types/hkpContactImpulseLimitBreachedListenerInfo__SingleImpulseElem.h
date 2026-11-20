// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactImpulseLimitBreachedListenerInfo__SingleImpulseElem; size 0x20
#pragma once

struct hkContactPoint_68092cba;
struct hkpConstraintInstance;
struct hkpContactPointProperties;
struct hkpContactImpulseLimitBreachedListenerInfo__SingleImpulseElem {
    unsigned short m_type_0;
    unsigned short m_isContact_2;
    char _pad_4[4];
    hkpConstraintInstance* m_constraintInstance_8;
    hkpContactPointProperties* m_properties_10;
    hkContactPoint_68092cba* m_contactPoint_18;
};
static_assert(sizeof(hkpContactImpulseLimitBreachedListenerInfo__SingleImpulseElem) == 32, "hkpContactImpulseLimitBreachedListenerInfo__SingleImpulseElem layout differs from the PDB");
