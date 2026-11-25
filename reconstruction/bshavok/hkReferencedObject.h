// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction; declarations from CommonLibSSE-NG and the local listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// hkReferencedObject, hkReferencedObject::CalcContentStatistics, hkReferencedObject::~hkReferencedObject, hkReferencedObject::GetClassType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08, hkBaseObject: GUESS(low); local stand-in for the generated base, which declares no virtuals
// g_specialClass, StatBuf, GetStatFlag, CollectStat: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class hkBaseObject
{
public:
    virtual ~hkBaseObject() {}
};
static_assert(sizeof(hkBaseObject) == 0x8, "hkBaseObject size");

class hkClass;
class hkStatisticsCollector;
class hkReferencedObject;

extern hkClass g_specialClass;

struct StatBuf
{
    std::uint8_t data[8];
};

bool* GetStatFlag(StatBuf* a_out, const hkClass* a_class);
void CollectStat(const hkReferencedObject* a_self, const hkClass* a_class, hkStatisticsCollector* a_collector);

class hkReferencedObject : public hkBaseObject
{
public:
    ~hkReferencedObject() override;  // 00
    virtual const hkClass* GetClassType() const;  // 01
    virtual void CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const;  // compared: 0xaa2c40  // slot 02

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint16_t memSizeAndFlags;  // 08
    std::int16_t referenceCount;  // 0A
    std::uint8_t unknown0C[0x4];  // 0C
    void Functionaa2b50();
    static void Functionaa2ab0(std::uint32_t a_value);
    void Functionaa2870();
    void Functionaa2890();
};
static_assert(sizeof(hkReferencedObject) == 0x10, "hkReferencedObject size");
