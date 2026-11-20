// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// 0x26b3e0 TESEffectShader::InitializeData
// 0x26b760 TESEffectShader::InitItemImpl
#include "TESEffectShader.h"

void TESEffectShader::InitializeData()
{
    data.Initialize();
}

// TestBit: GUESS(low); tests one bit of a word by value.
static bool TestBit(std::uint32_t a_word, std::uint32_t a_bit)
{
    return ((a_word >> a_bit) & 1) != 0;
}

// BGSDebris: GUESS(low); stand-in for the record type the dynamic cast in InitItemImpl targets.
class BGSDebris {};

// TESEffectShader::InitItemImpl, RVA 0x26b760, 180 bytes. Resolves the two stored form IDs (at 0x118 and
// 0x160) into object pointers, after adding the compile index to each.
void TESEffectShader::InitItemImpl()
{
    auto* base = reinterpret_cast<std::uint8_t*>(this);
    if (!TestBit(formFlags, 3)) {
        std::uint32_t formID = *reinterpret_cast<std::uint32_t*>(base + 0x118);
        if (formID != 0) {
            RecordFlags_AddCompileIndex(&formID, GetCompileIndexForOwner(this, 0xffffffff));
            *reinterpret_cast<BGSDebris**>(base + 0x118) = dynamic_cast<BGSDebris*>(GetFormForID(formID));
        }
        formID = *reinterpret_cast<std::uint32_t*>(base + 0x160);
        if (formID != 0) {
            RecordFlags_AddCompileIndex(&formID, GetCompileIndexForOwner(this, 0xffffffff));
            *reinterpret_cast<void**>(base + 0x160) = LoadFormForID(formID);
        }
        FinishInitItem(this, true);
    }
}
