// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1de5e0 TESActorBaseData::Unk_07
// 0x1de5f0 TESActorBaseData::GetVoiceType
// 0x1de5c0 TESActorBaseData::GetInvulnerable
// 0x1de5d0 TESActorBaseData::GetIsGhost
// 0x1dc630 TESActorBaseData::ClearDataComponent
// 0x1dc5e0 TESActorBaseData::InitializeDataComponent
#include "TESActorBaseData.h"

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

// TESActorBaseData::CopyFromTemplateForms: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void TESActorBaseData::CopyFromTemplateForms()
{
}
