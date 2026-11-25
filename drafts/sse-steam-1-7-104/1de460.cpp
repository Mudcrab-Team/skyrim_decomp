// Near miss: 0.0% | other
// TESActorBaseData: virtual accessors, ClearDataComponent and InitializeDataComponent, build sse-steam-1-7-104.
//
// RVA 0x1de5e0, 3 bytes (Unk_07);
// RVA 0x1de5f0, 5 bytes (GetVoiceType);
// RVA 0x1de5c0, 7 bytes (GetInvulnerable);
// Source exposure: mixed
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1de460 TESActorBaseData::~TESActorBaseData

#include "include/1de460/TESActorBaseData.h"

// gDefaultBaseDisposition: GUESS(low); a byte global at 0x20780f8 copied into baseDisposition
extern std::uint8_t gDefaultBaseDisposition;

namespace
{
    // TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
    inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 1) != 0;
    }
}

bool TESActorBaseData::GetIsGhost() const
{
    return TestBit(actorData.actorBaseFlags, 29);
}

bool TESActorBaseData::GetInvulnerable() const
{
    return TestBit(actorData.actorBaseFlags, 31);
}

bool TESActorBaseData::Unk_07()
{
    return true;
}

BGSVoiceType* TESActorBaseData::GetVoiceType()
{
    return voiceType;
}

void TESActorBaseData::ClearDataComponent()
{
    factions.Clear();
}

void TESActorBaseData::InitializeDataComponent()
{
    actorData.level = 1;
    actorData.calcLevelMin = 0;
    actorData.actorBaseFlags = 0;
    actorData.magickaOffset = 0;
    actorData.staminaOffset = 0;
    actorData.healthOffset = 0;
    actorData.calcLevelMax = 0;
    actorData.speedMult = 100;
    actorData.baseDisposition = gDefaultBaseDisposition;
    voiceType = nullptr;
    deathItem = nullptr;
    baseTemplateForm = nullptr;
    actorData.templateUseFlags = 0;
    actorData.bleedoutOverride = 0;
    unk38 = 0;
}


// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbasedata.cpp:31 (destructor cleanup shape)
// TESActorBaseData::~TESActorBaseData: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); cleanup shape only
TESActorBaseData::TESActorBaseData() {}
TESActorBaseData::~TESActorBaseData() { factions.Clear(); }
