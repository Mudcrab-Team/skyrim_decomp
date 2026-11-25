// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0xf5de10 (gamebryo/nianimation/NiMultiTargetTransformController): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ControlledEntry, NiCloningProcess: GUESS(low)
// Owner14e5430: GUESS(low) STANDIN
// NiInterpController, AllocateEntries, BaseLoadBinary, m_entries, m_entryPtrs, m_count: GUESS(low) STANDIN
#pragma once
#include "NiMultiTargetTransformController.h"
#include <cstring>

class Owner14e5430 : public NiInterpController
{
public:
    Owner14e5430();
    virtual std::uint16_t GetInterpolatorCount() const;
    virtual const char* GetInterpolatorID(std::uint16_t a_index = 0);
    virtual ~Owner14e5430();
    virtual void GuaranteeTimeRange(float a_startTime, float a_endTime);
    virtual std::uint16_t GetInterpolatorIndex(const char* a_id) const;
    virtual void LoadBinary(NiStream& a_stream);
    virtual void SaveBinary(NiStream& a_stream);
    virtual bool IsEqual(NiObject* a_object);
    virtual void ResetTimeExtrema();
    virtual void ProcessClone(NiCloningProcess& a_cloning);

    void AllocateEntries(std::uint16_t a_count);
    void BaseLoadBinary(NiStream& a_stream);

    ControlledEntry* m_entries;  // 48
    ControlledEntry** m_entryPtrs;  // 50
    std::uint16_t m_count;  // 58
    std::uint8_t unknown5A[0x6];  // 5a
};
static_assert(sizeof(Owner14e5430) == 0x60, "Owner14e5430 size");
