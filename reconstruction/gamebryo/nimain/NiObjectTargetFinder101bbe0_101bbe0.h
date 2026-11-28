// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// NiObjectTargetFinder101bbe0, StandinRTTI101bbe0, StandinTarget101bbe0, StandinController101bbe0, StandinControllerManager101bbe0, FindControllerManagerTarget, GetRTTI, IsKindOf, AsNode, name, base, ms_RTTI, next, target, controllers, unk08, unk48, Unk_01..Unk_04: GUESS(low) STANDIN; community list names 0x101bbe0 NiNode::FindControllerManagerTarget, but its offsets (+0x18 controller list, +0x40 next, +0xC0 target) do not fit NiNode or NiTimeController
#pragma once

#include <cstdint>

struct StandinRTTI101bbe0
{
    const char*              name;  // 00
    const StandinRTTI101bbe0* base;  // 08
};

class StandinTarget101bbe0;

class StandinController101bbe0
{
public:
    virtual ~StandinController101bbe0();
    virtual void                     Unk_01();
    virtual const StandinRTTI101bbe0* GetRTTI() const;  // 10

    bool IsKindOf(const StandinRTTI101bbe0* rtti) const
    {
        for (const StandinRTTI101bbe0* cur = GetRTTI(); cur; cur = cur->base)
        {
            if (cur == rtti)
            {
                return true;
            }
        }
        return false;
    }

    std::uint64_t            unk08[7];   // 08
    StandinController101bbe0* next;       // 40
    std::uint64_t            unk48[15];  // 48
    StandinTarget101bbe0*    target;     // C0
};
static_assert(sizeof(StandinController101bbe0) == 0xC8, "StandinController101bbe0 size");

class StandinControllerManager101bbe0 : public StandinController101bbe0
{
public:
    static const StandinRTTI101bbe0 ms_RTTI;
};

class NiObjectTargetFinder101bbe0
{
public:
    virtual ~NiObjectTargetFinder101bbe0();
    virtual void                        Unk_01();
    virtual void                        Unk_02();
    virtual void                        Unk_03();
    virtual void                        Unk_04();
    virtual NiObjectTargetFinder101bbe0* AsNode();  // 28

    StandinTarget101bbe0* FindControllerManagerTarget();

    std::uint64_t            unk08[2];     // 08
    StandinController101bbe0* controllers;  // 18
};
static_assert(sizeof(NiObjectTargetFinder101bbe0) == 0x20, "NiObjectTargetFinder101bbe0 size");
